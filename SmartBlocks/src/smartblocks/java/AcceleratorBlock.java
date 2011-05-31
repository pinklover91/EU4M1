/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package smartblocks.java;

import java.util.Map;


/**
 *
 * @author david
 */
public class AcceleratorBlock extends BlockImpl {


    AcceleratorBlock(EnumBlocks type, Vector2D offset, Vector2D size, Map<EnumBlockParams,Double> params){
        super(type,offset,size,params);
    }

    @Override
    public void operate(MovingObject mo, double dt) {
        // Does nothing
        double fX, fY;
        fX=getParam(EnumBlockParams.CONSTANT_FORCE_X);
        fY=getParam(EnumBlockParams.CONSTANT_FORCE_Y);
        Vector2D semiSize=Vector2D.scale(size,0.5);
        Vector2D center =Vector2D.sum(offset,semiSize);
        //Vector2D Tz=Vector2D.cross(Vector2D.substraction(center,mo.getPosition()),new Vector2D(fX,fY));
        if(Vector2D.norm2(Vector2D.distance(center,mo.getPosition()))<Vector2D.norm2(semiSize)){  // Area of influence
                mo.applyForce(fX, fY, dt);
               // mo.applyTorque(Tz, dt);            
        }
    }
}
