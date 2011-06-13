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
strictfp class BoundingBlock extends BlockImpl{
    protected EnumDirections direction;

    BoundingBlock(Vector2D offset, Vector2D size,EnumDirections direction){
        super(EnumBlocks.BOUNDING,offset,size);
        this.direction=direction;        
    }

    @Override    
    public Vector2D[] computeForces(MovingObject mo,Vector2D[] contacts) throws CollisionOcurred{
                throw new CollisionOcurred(this, direction);                
    }
}

