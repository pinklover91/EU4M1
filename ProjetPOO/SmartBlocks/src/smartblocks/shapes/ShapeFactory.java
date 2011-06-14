/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.shapes;

import smartblocks.utilities.Vector2D;

/**
 * A factory of Shapes implemented as a singleton
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

   /**
    * Returns a reference to the ShapeFactory
    * @return
    */
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

   /**
    * Creates a Box with the specified attributes
    * @param offset distance of the upper-left corner of this box to the
    * origin of the world's coordinate system aka computer screen
    * @param size width (size.x) and height (size.y) of this block
    * @return a new Box
    */
     public Shape createShape(Vector2D offset,Vector2D size){
            return new Box(offset,size);
     }

     /**
      * Creates a Circle with the specified attributes
      * @param center of this Circle
      * @param radius of this Circle
      * @return a new Circle
      */
     public Shape createShape(Vector2D center,float radius){
            return new Circle(center,radius);
     }

     /**
      * Creates a Polygon with the specified attributes
      * The actual offset and vertices of the polygon are calculated so
      * it behaves as a circle whose center is: offset + vertices' centroid
      * and radius is the radius of the vertices' bounding circle
      * @param offset distance of the upper-left corner of this box to the
      * origin of the world's coordinate system aka computer screen
      * @param v array of vertices
      * @return
      */
     public Shape createShape(Vector2D offset, Vector2D[] v){
            return new Polygon(offset,v);
     }

}
