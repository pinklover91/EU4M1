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
public strictfp class PunctualCollider implements Collider{

    @Override
    public Vector2D[] collide(Block block, MovingObject mo) {
         if(block.getShape().contains(mo.getPosition())){
              return new Vector2D[1];
         }else{
              return null;
         }
    }
}
