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
     * Converts an array of Vector2D into an array of float, like this:
     * { points[0].x, points[0].y, points[1].x, points[1].y, .... }
     * @param points
     * @return
     */
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
     * Returns the collider associated with the object and block types
     * @param blockType
     * @param objectType
     * @return The collider responsible for the collision operations
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
