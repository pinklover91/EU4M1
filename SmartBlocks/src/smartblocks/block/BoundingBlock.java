/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.block;

import smartblocks.utilities.Vector2D;
import java.util.Map;
import smartblocks.object.MovingObject;
import smartblocks.simulation.SimulationObject;
import smartblocks.utilities.CollisionOcurred;
import smartblocks.utilities.EnumDirections;
import smartblocks.utilities.SmartBlockUtilities;

/**
 * Block used as a wall in the simulation. Toggles object's velocity in the
 * specified direction.
 * @author David FUENMAYOR
 */
public class BoundingBlock extends BlockImpl{
    protected EnumDirections direction;

    BoundingBlock(Vector2D offset, Vector2D size,EnumDirections direction){
        super(EnumBlocks.BOUNDING,offset,size);
        this.direction=direction;
        switch(direction){
            case RIGHT:
                force.x=1f;
                force.y=0;
                break;
            case UP:
                force.x=0;
                force.y=-1f;
                break;
            case LEFT:
                force.x=-1f;
                force.y=0;
                break;
            case DOWN:
                force.x=0;
                force.y=1f;
                break;
            default:
                break;
        }
    }

    @Override    
    public boolean operate(SimulationObject so, float dt) throws CollisionOcurred {
        if(so instanceof MovingObject){
            MovingObject mo=(MovingObject)so;
            if(SmartBlockUtilities.getCollider(this.getType(), mo.getType()).collide(this, mo)!=null){
                Vector2D center =shape.getCentroid(true);
                Vector2D momentum=mo.getMomentum();
                throw new CollisionOcurred(this, direction);                
            }
        }
        return false;
    }
}

