/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.object;

import java.util.Map;

/**
 *
 * @author David FUENMAYOR
 */
public class ObjectFactory {


    private ObjectFactory() {
    }

   /**
    * SingletonHolder is loaded on the first execution of Singleton.getInstance()
    * or the first access to SingletonHolder.INSTANCE, not before.
    */
   private static class SingletonHolder {
     public static final ObjectFactory INSTANCE = new ObjectFactory();
   }

   public static ObjectFactory getInstance(){
       return SingletonHolder.INSTANCE;
   }


    /**
     * Creates a new moving object of the specified type.
     * The specified parameters are copied into the new object
     * @param objectType
     * @param params
     * @return
     */
     public MovingObject createMovingObject(EnumObjects objectType,Map<EnumObjectParams,Object> params){
        MovingObject mo;
        switch (objectType){
            case PUNCTUAL:
                mo=new PunctualMass(params);
                break;
            case RECTANGLE:
                //block=new BouncingBlock(blockType.BOUNCING);
            case CIRCLE:

            case POLYGON:

            default:
                mo=new PunctualMass(params);
                break;
        }
        return mo;
     }
}
