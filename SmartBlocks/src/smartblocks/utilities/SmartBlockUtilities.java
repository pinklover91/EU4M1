/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */
package smartblocks.utilities;

import smartblocks.block.Block;
import smartblocks.block.EnumBlocks;
import smartblocks.object.EnumObjects;
import smartblocks.object.MovingObject;

/**
 * Static class with utilities to be used during a simulation
 * Provides the methods for external code to instantiate colliders
 * @author David FUENMAYOR
 */
public class SmartBlockUtilities {

    /**
     * Looks if both blocks actually overlap
     * @param a First block
     * @param b Second block
     * @return true if they overlap each other
     */
    public static boolean overlaps(Block a,Block b){
        if(a.getX()<b.getX()&&a.getY()<b.getY()){
            if(a.getX()+a.getWidth()>b.getX()&&a.getY()+a.getHeight()>b.getY()){
                return true;
            }else return false;
        }else if(a.getX()>b.getX()&&a.getX()>b.getY()){
            if(a.getX()<b.getX()+b.getWidth()&&a.getY()<b.getY()+b.getHeight()){
                return true;
            }else return false;
        }// TODO: it's not over!!!
        return false;
    }

    /**
     * Return the collider associated with the object and block types
     * @param blockType
     * @param objectType
     * @return The collider responsible for checking collisions
     */
    public static Collider getCollider(EnumBlocks blockType, EnumObjects objectType){
            switch(objectType){
                case CIRCLE:                   
                case RECTANGLE:                    
                case POLYGON:                    
                default:
                    return CollidersHolder.PUNCTUAL_COLLIDER;
            }
    }

    private static class CollidersHolder{
        public static final PunctualCollider PUNCTUAL_COLLIDER = new PunctualCollider();
        //TODO: Add more colliders
    }
}
