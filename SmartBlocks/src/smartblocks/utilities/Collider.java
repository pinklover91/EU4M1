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
     * Tells if the specified block and object collide, if so,
     * returns array of colliding points
     * @param block
     * @param object
     * @return array of colliding points
     */
    Vector2D[] collide(Block block, MovingObject object);

}
