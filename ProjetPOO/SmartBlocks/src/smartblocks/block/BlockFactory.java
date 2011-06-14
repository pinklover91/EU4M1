/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.block;

import java.util.Map;
import smartblocks.utilities.EnumDirections;
import smartblocks.utilities.Vector2D;

/**
 * A factory of Blocks implemented as a singleton
 * @author David FUENMAYOR
 */
public class BlockFactory {

    private BlockFactory() {
    }

   /**
    * SingletonHolder is loaded on the first execution of Singleton.getInstance()
    * or the first access to SingletonHolder.INSTANCE, not before.
    */
   private static class SingletonHolder {
     public static final BlockFactory INSTANCE = new BlockFactory();
   }

   /**
    * Returns a reference to the BlockFactory
    * @return
    */
   public static BlockFactory getInstance(){
       return SingletonHolder.INSTANCE;
   }

    /**
     * Creates a new block of the specified type.
     * The specified parameters  are copied into the new block
     * @param blockType
     * @param x Horizontal position of the block
     * @param y Vertical position of the block
     * @param w Width of the block
     * @param h Height of the block
     * @param params Parameters to be copied into the block
     * @return A new Block
     */
    public Block createBlock(EnumBlocks blockType,float x, float y, float w, float h,Map<EnumBlockParams,Object> params){
        Vector2D offset=new Vector2D(x,y);
        Vector2D size=new Vector2D(w,h);
        return createBlock(blockType, offset, size, params);
    }

    /**
     * Creates a new block of the specified type.
     * The specified parameters  are copied into the new block
     * @param blockType
     * @param offset Vector2D with the position of the block
     * @param size Vector2D with the size of the block
     * @param params Parameters to be copied into the block
     * @return A new Block
     */
     public Block createBlock(EnumBlocks blockType,Vector2D offset, Vector2D size,Map<EnumBlockParams,Object> params){
        Block block;
        switch (blockType){
            case ACCELERATOR:
                block=new AcceleratorBlock(offset,size,params,EnumDirections.ALL);
                break;
            case ACCELERATOR_UP:
                block=new AcceleratorBlock(offset,size,params,EnumDirections.UP);
                break;
            case ACCELERATOR_LEFT:
                block=new AcceleratorBlock(offset,size,params,EnumDirections.LEFT);
                break;
            case ACCELERATOR_DOWN:
                block=new AcceleratorBlock(offset,size,params,EnumDirections.DOWN);
                break;
            case ACCELERATOR_RIGHT:
                block=new AcceleratorBlock(offset,size,params,EnumDirections.RIGHT);
                break;
            case BOUNDING:
                block=new BoundingBlock(offset,size,EnumDirections.ALL);
                break;
            case FORBIDDEN:
                block=new ForbiddenBlock(offset,size,params);
                break;
            case TARGET:
                block=new TargetBlock(offset,size,params);
                break;
            case VISCOUS:
                block=new ViscousBlock(offset,size,params);
                break;
            case PROPORTIONAL:
                block=new ProportionalBlock(offset, size, params);
                break;
            default:
                block=new BlockImpl(blockType,offset,size);
                break;
        }
        return block;
     }

     /**
      * Creates one of the blocks used as walls in the simulation
      * @param x Horizontal position of the block
      * @param y Vertical position of the block
      * @param w Width of the block
      * @param h Height of the block
      * @param direction of application of the force
      * @return BoundingBlock used as element of the wall
      */
     public Block createBoundingBlock(float x, float y, float w, float h, EnumDirections direction){
        Vector2D offset=new Vector2D(x,y);
        Vector2D size=new Vector2D(w,h);
        return new BoundingBlock(offset,size,direction);
     }
}
