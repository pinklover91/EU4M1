/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.utilities;

import smartblocks.block.Block;
import smartblocks.object.MovingObject;

/**
 * Collider used to get collisions between a rectangular block and a punctual mass
 * @author David FUENMAYOR
 */
public class PunctualCollider implements Collider{

    @Override
    public boolean collide(Block block, MovingObject mo) {
         Vector2D semiSize=Vector2D.scale(block.getSize(),0.5);
         Vector2D center =Vector2D.sum(block.getOffset(),semiSize);
         return (Vector2D.norm2(Vector2D.distance(center,mo.getPosition()))<Vector2D.norm2(semiSize));  // Area of influence
    }
}
