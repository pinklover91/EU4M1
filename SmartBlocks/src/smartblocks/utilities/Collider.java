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
     * Tells if the specified block and object collide
     * @param block
     * @param object
     * @return true is block and object collide
     */
    boolean collide(Block block, MovingObject object);

}
