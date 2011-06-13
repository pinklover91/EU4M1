/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.block;

import smartblocks.utilities.Vector2D;
import java.util.Map;
import smartblocks.object.MovingObject;

/**
 * Block with a force proportional to the inverse of the distance between its
 * centroid and that of the moving object.
 * @author David FUENMAYOR
 */
strictfp class ProportionalBlock extends BlockImpl{

    ProportionalBlock(Vector2D offset, Vector2D size, Map<EnumBlockParams,Object> params){
        super(EnumBlocks.PROPORTIONAL,offset,size,params);
    }

    @Override
    public Vector2D[] computeForces(MovingObject mo,Vector2D[] contacts) {
         int n=contacts.length;
         Vector2D[] forces=new Vector2D[n];
         float k=(Float)getParam(EnumBlockParams.RIGID_COEF);
         int i=0;
         for(Vector2D c:contacts){
             forces[i]=new Vector2D(k/(c.x*n),k/(c.y*n));
             i++;
         }
         return forces;
    }
}

