/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.block;

import smartblocks.utilities.Vector2D;
import java.util.Map;
import smartblocks.simulation.SimulationObject;


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
    public void operate(SimulationObject mo, float dt) {
        
         //Vector2D Tz=Vector2D.cross(Vector2D.substraction(??),new Vector2D(fX,fY));
        //if(SmartBlockUtilities.getCollider(this.getType(), mo.getType()).collide(this, mo)){
            //mo.applyForce(force.x,force.y, dt);
               // mo.applyTorque(Tz, dt);
        //}
        //torque=

    }
}