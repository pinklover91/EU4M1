/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */
package smartblocks.utilities;

import smartblocks.block.Block;
import smartblocks.block.EnumBlocks;
import smartblocks.shapes.EnumShapes;

/**
 * Static class with utilities to be used during a simulation
 * Provides the methods for external code to instantiate colliders
 * @author David FUENMAYOR
 */
public strictfp class SmartBlockUtilities {

    /**
     * Looks if both blocks actually overlap
     * @param a First block
     * @param b Second block
     * @return true if they overlap each other
     */
    public static boolean overlaps(Block a,Block b){        
        return false;
    }

    public static float[] asArray(Vector2D[] points){
        float[] ret=new float[points.length*2];
        int i=0;
        for(Vector2D p:points){
            ret[i]=p.x;
            i++;
            ret[i]=p.y;
            i++;
        }
        return ret;
    }

    /**
     * Return the collider associated with the object and block types
     * @param blockType
     * @param objectType
     * @return The collider responsible for checking collisions
     */
    public static Collider getCollider(EnumBlocks blockType, EnumShapes objectType){
            switch(objectType){
                case CIRCLE:
                    return CollidersHolder.CIRCLE_COLLIDER;
                case BOX:
                    return CollidersHolder.BOX_COLLIDER;
                case POLYGON: 
                    return CollidersHolder.POLYGON_COLLIDER;
                default:
                    return CollidersHolder.PUNCTUAL_COLLIDER;
            }
    }

    private static class CollidersHolder{
        public static final PunctualCollider PUNCTUAL_COLLIDER = new PunctualCollider();
        public static final BoxCollider BOX_COLLIDER = new BoxCollider();
        public static final CircleCollider CIRCLE_COLLIDER = new CircleCollider();
        public static final PolygonCollider POLYGON_COLLIDER = new PolygonCollider();
    }
}
