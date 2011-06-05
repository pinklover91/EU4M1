/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.shapes;

import smartblocks.utilities.Vector2D;

/**
 *
 * @author David FUENMAYOR
 */
public class ShapeFactory {

    private ShapeFactory() {
    }

   /**
    * SingletonHolder is loaded on the first execution of Singleton.getInstance()
    * or the first access to SingletonHolder.INSTANCE, not before.
    */
   private static class SingletonHolder {
     public static final ShapeFactory INSTANCE = new ShapeFactory();
   }

   public static ShapeFactory getInstance(){
       return SingletonHolder.INSTANCE;
   }

     public Shape createShape(Vector2D offset,Vector2D size){
            return new Box(offset,size);
     }

     public Shape createShape(Vector2D center,float radius){
            return new Circle(center,radius);
     }

     public Shape createShape(Vector2D offset, Vector2D[] v){
            return new Polygon(offset,v);
     }

}
