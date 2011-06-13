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


   /**
    * Creates a non-initialized Shape according to the type passed as argument
    * @param t
    * @return new Shape object
    */
   public Shape createShape(EnumShapes t){
       Shape ret;
       switch(t){
           case BOX:
              ret= createShape(new Vector2D(),t.getSize());
              break;
           case CIRCLE:
               ret= createShape(new Vector2D(),t.getSize());
               break;
           case POLYGON :
              Vector2D[] v=new Vector2D[3];
              ret= createShape(new Vector2D(),v);
              break;
           default:
              ret= createShape(new Vector2D() ,t.getSize());
              break;
       }
       return ret;
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
