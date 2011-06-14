/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.utilities;

import smartblocks.block.Block;
import smartblocks.object.MovingObject;
import smartblocks.shapes.Shape;

/**
 * Collider used to get collisions between a rectangular block and a circular object
 * @author David FUENMAYOR
 */
public strictfp class CircleCollider implements Collider{

    @Override
    public void collide(MovingObject mo,Vector2D[] forces,Vector2D[] vertices){
        //TODO: Provide a correct implementation
        Vector2D totalForce=Vector2D.mean(forces);
         mo.addForces(totalForce.x, totalForce.y,0);
    }

    @Override
    public Vector2D[] getCollidingVertices(Block block, MovingObject mo){
        //TODO: Provide a correct implementation
        Shape blockShape=block.getShape();
        if(blockShape.overlaps(mo.getShape())){
              Vector2D[] ret=new Vector2D[1];
              ret[0]=mo.getPosition();
              ret[0].substract(blockShape.getCentroid(true));
              return ret;
         }else{
              return null;
         }
    }
}
