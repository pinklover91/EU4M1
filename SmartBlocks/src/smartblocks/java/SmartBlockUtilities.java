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
public class SmartBlockUtilities {

    static private Simulation simulation;
    /**
     * Looks if both blocks actually overlap
     * @param a
     * @param b
     * @return
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
     * Implements a blocks' factory - method factory design pattern
     * Params are copied.
     * @param blockType
     * @param offset
     * @param size
     * @param params
     * @return
     */
    public static Block createBlock(EnumBlocks blockType,int x, int y, int w, int h,Map<EnumBlockParams,Double> params){
        Vector2D offset=new Vector2D(x,y);
        Vector2D size=new Vector2D(w,h);
        return createBlock(blockType, offset, size, params);
    }

     public static Block createBlock(EnumBlocks blockType,Vector2D offset, Vector2D size,Map<EnumBlockParams,Double> params){
        Block block;
        switch (blockType){
            case ACCELERATOR:
                block=new AcceleratorBlock(blockType.ACCELERATOR,offset,size,params);
                break;
            case BOUNCING:
                block=new BouncingBlock(blockType.BOUNCING,offset,size,params);
            case FORBIDDEN:

            case TARGET:

            case VISCOUS:

            default:
                block=new BlockImpl(offset,size);
                break;

        }
        return block;
     }

    /**
     * Params are copied.
     * @param objectType
     * @param params
     * @return
     */
     public static MovingObject createMovingObject(EnumObjects objectType,Map<EnumObjectParams,Double> params){
        MovingObject mo;       
        switch (objectType){
            case PUNCTUAL:
                mo=new PunctualMass(objectType.PUNCTUAL,params);
                break;
            case RECTANGLE:
                //block=new BouncingBlock(blockType.BOUNCING);
            case CIRCLE:

            case POLYGON:
                
            default:
                mo=new PunctualMass(objectType.PUNCTUAL,params);
                break;
        }
        return mo;
     }
   

}
