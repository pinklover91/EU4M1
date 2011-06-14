/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.utilities;

import smartblocks.block.Block;
import smartblocks.object.MovingObject;

/**
 * Interface used in order to check for collisions between blocks and objects
 * @author David FUENMAYOR
 */
public interface Collider {

    /**
     * Tells if the specified block and object collide, if so, returns array 
     * of colliding points whose coordinates are given with respect of the centroid of
     * the block. 
     * @param block
     * @param object
     * @return array of colliding points
     */
    Vector2D[] getCollidingVertices(Block block, MovingObject object);

    /**
     * Converts the specified forces applied in the corresponding vertices into
     * one single force applied in the centroid of the object and a torque.
     * Uses MovingObject's {@code addForces(...)} method which only adds forces and
     * torques to it. In order to apply the sum of the forces to the object use
     * MovingObject's {@code applyForces(...)} afterwards.
     * @param mo
     * @param forces
     * @param vertices
     */
    void collide(MovingObject mo,Vector2D[] forces,Vector2D[] vertices);

}
