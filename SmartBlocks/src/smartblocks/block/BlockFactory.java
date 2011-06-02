/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.block;

import java.util.Map;
import smartblocks.utilities.Vector2D;

/**
 * Singleton factory used to instantiate blocks
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
    public Block createBlock(EnumBlocks blockType,int x, int y, int w, int h,Map<EnumBlockParams,Double> params){
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
     public Block createBlock(EnumBlocks blockType,Vector2D offset, Vector2D size,Map<EnumBlockParams,Double> params){
        Block block;
        switch (blockType){
            case ACCELERATOR:
                block=new AcceleratorBlock(offset,size,params);
                break;
            case BOUNCING:
                block=new BouncingBlock(offset,size,params);
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
            default:
                block=new BlockImpl(blockType,offset,size);
                break;
        }
        return block;
     }
}
