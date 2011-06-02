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
 * Block with a constant force all along its surface
 * @author David FUENMAYOR
 */
class AcceleratorBlock extends BlockImpl {

    AcceleratorBlock(Vector2D offset, Vector2D size, Map<EnumBlockParams,Double> params){
        super(EnumBlocks.ACCELERATOR,offset,size,params);
    }

    @Override
    public void operate(MovingObject mo, double dt) {        
        double fX, fY;
         //Vector2D Tz=Vector2D.cross(Vector2D.substraction(??),new Vector2D(fX,fY));
        if(SmartBlockUtilities.getCollider(this.getType(), mo.getType()).collide(this, mo)){
            fX=getParam(EnumBlockParams.CONSTANT_FORCE_X);
            fY=getParam(EnumBlockParams.CONSTANT_FORCE_Y);
            mo.applyForce(fX, fY, dt);
               // mo.applyTorque(Tz, dt);
        }
    }
}