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
import smartblocks.utilities.SmartBlockUtilities;
import smartblocks.utilities.Vector3D;


/**
 * Block with a constant force all along its surface
 * @author David FUENMAYOR
 */
class AcceleratorBlock extends BlockImpl {

    AcceleratorBlock(Vector2D offset, Vector2D size, Map<EnumBlockParams,Object> params){
        super(EnumBlocks.ACCELERATOR,offset,size,params);
        force.x=getParam(EnumBlockParams.CONSTANT_FORCE_X);
        force.y=getParam(EnumBlockParams.CONSTANT_FORCE_Y);
    }

    @Override
    public boolean operate(SimulationObject so, float dt) {
        
         if(so instanceof MovingObject){
            MovingObject mo=(MovingObject)so;
            if(SmartBlockUtilities.getCollider(this.getType(), mo.getType()).collide(this, mo)!=null){
                return true;
            }
        }
         return false;
    }
}