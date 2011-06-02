/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.block;

import java.util.Map;
import smartblocks.object.MovingObject;
import smartblocks.simulation.EnumSimulation;
import smartblocks.simulation.SimulationTerminatedException;
import smartblocks.utilities.SmartBlockUtilities;
import smartblocks.utilities.Vector2D;

/**
 *
 * @author David FUENMAYOR
 */
class ForbiddenBlock extends BlockImpl{

    ForbiddenBlock(Vector2D offset, Vector2D size, Map<EnumBlockParams,Double> params){
        super(EnumBlocks.FORBIDDEN,offset,size,params);
    }

    @Override
    public void operate(MovingObject mo, double dt) throws SimulationTerminatedException{
    
        if(SmartBlockUtilities.getCollider(this.getType(), mo.getType()).collide(this, mo)){
            throw new SimulationTerminatedException(this,mo,EnumSimulation.FORBIDDEN_BLOCK);
        }
    }
}