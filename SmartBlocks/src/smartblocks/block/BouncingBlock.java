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
import smartblocks.utilities.SmartBlockUtilities;

/**
 * Block with a force proportional to the distance of the moving object
 * @author David FUENMAYOR
 */
class BouncingBlock extends BlockImpl{

    BouncingBlock(Vector2D offset, Vector2D size, Map<EnumBlockParams,Object> params){
        super(EnumBlocks.BOUNCING,offset,size,params);
    }

    @Override    
    public void operate(SimulationObject so, float dt) {
        if(so instanceof MovingObject){
            MovingObject mo=(MovingObject)so;
            if(SmartBlockUtilities.getCollider(this.getType(), mo.getType()).collide(this, mo)!=null){
                Vector2D center =shape.getCentroid(true);
                Vector2D distance=Vector2D.distance(center,mo.getPosition());
                force.x=getParam(EnumBlockParams.RIGID_COEF)*distance.x;
                force.y=getParam(EnumBlockParams.RIGID_COEF)*distance.y;              
            }
        }
    }
}

