/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.block;

import smartblocks.utilities.Vector2D;
import smartblocks.object.MovingObject;
import java.util.Map;
import smartblocks.simulation.SimulationTerminated;

/**
 *
 * @author David FUENMAYOR
 */
strictfp class ViscousBlock extends BlockImpl{

 ViscousBlock(Vector2D offset, Vector2D size, Map<EnumBlockParams,Object> params){
        super(EnumBlocks.VISCOUS,offset,size,params);
    }

    @Override
    public Vector2D[] computeForces(MovingObject mo,Vector2D[] contacts) {
         int n=contacts.length;
         Vector2D[] forces=new Vector2D[n];
         float b=(Float)getParam(EnumBlockParams.VISCOUS_COEF);
         b/=n;
         Vector2D velocity=mo.getVelocity();
         int i=0;
         for(Vector2D c:contacts){
             forces[i]=new Vector2D(-b*velocity.x,-b*velocity.y);
             i++;
         }
         return forces;
    }
}