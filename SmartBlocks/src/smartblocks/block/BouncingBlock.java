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
 * Block with a force proportional to the distance of the moving object
 * @author David FUENMAYOR
 */
class BouncingBlock extends BlockImpl{

    BouncingBlock(Vector2D offset, Vector2D size, Map<EnumBlockParams,Double> params){
        super(EnumBlocks.BOUNCING,offset,size,params);
    }

@Override
    public void operate(MovingObject mo, double dt) {
        
        if(SmartBlockUtilities.getCollider(this.getType(), mo.getType()).collide(this, mo)){
            Vector2D semiSize=Vector2D.scale(size,0.5);
            Vector2D center =Vector2D.sum(offset,semiSize);
            Vector2D distance=Vector2D.distance(center,mo.getPosition());
            force.x=getParam(EnumBlockParams.RIGID_COEF)*distance.x;
            force.y=getParam(EnumBlockParams.RIGID_COEF)*distance.y;
                mo.applyForce(force.x, force.y, dt);
        }
    }
}

