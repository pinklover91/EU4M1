/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.block;

import smartblocks.utilities.Vector2D;
import smartblocks.object.MovingObject;
import java.util.Map;
import smartblocks.utilities.SmartBlockUtilities;

/**
 *
 * @author David FUENMAYOR
 */
class ViscousBlock extends BlockImpl{

 ViscousBlock(Vector2D offset, Vector2D size, Map<EnumBlockParams,Double> params){
        super(EnumBlocks.VISCOUS,offset,size,params);
    }

@Override
    public void operate(MovingObject mo, double dt) {        
        double fX, fY;   
        
       
        if(SmartBlockUtilities.getCollider(this.getType(), mo.getType()).collide(this, mo)){
            fX=-1.0*getParam(EnumBlockParams.VISCOUS_COEF)*mo.getVelocity().x;
            fY=-1.0*getParam(EnumBlockParams.VISCOUS_COEF)*mo.getVelocity().y;
                mo.applyForce(fX, fY, dt);
                //mo.applyTorque(Tz, dt);
        }
    }
}

