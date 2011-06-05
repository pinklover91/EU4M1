/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.block;

import smartblocks.utilities.Vector2D;
import smartblocks.object.MovingObject;
import java.util.Map;
import smartblocks.simulation.SimulationObject;
import smartblocks.utilities.SmartBlockUtilities;

/**
 *
 * @author David FUENMAYOR
 */
class ViscousBlock extends BlockImpl{

 ViscousBlock(Vector2D offset, Vector2D size, Map<EnumBlockParams,Object> params){
        super(EnumBlocks.VISCOUS,offset,size,params);
    }

@Override
    public void operate(SimulationObject so, float dt) {

        if(so instanceof MovingObject){
                MovingObject mo=(MovingObject)so;
            if(SmartBlockUtilities.getCollider(this.getType(), mo.getType()).collide(this, mo)!=null){
                force.x=-1.0f*getParam(EnumBlockParams.VISCOUS_COEF)*mo.getVelocity().x;
                force.y=-1.0f*getParam(EnumBlockParams.VISCOUS_COEF)*mo.getVelocity().y;
            }
        }
    }
}