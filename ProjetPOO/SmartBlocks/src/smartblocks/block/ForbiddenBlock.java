/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.block;

import java.util.Map;
import smartblocks.object.MovingObject;
import smartblocks.simulation.EnumSimulation;
import smartblocks.simulation.SimulationObject;
import smartblocks.simulation.SimulationTerminated;
import smartblocks.utilities.SmartBlockUtilities;
import smartblocks.utilities.Vector2D;

/**
 * Special block used to signal the calling application that the moving object has
 * reached an undesirable location and the simulation should end, by throwing a
 * {@code SimulationTerminated} it's up to the caller to implement then the corresponding
 * behavior
 * @author David FUENMAYOR
 */
class ForbiddenBlock extends BlockImpl{

    ForbiddenBlock(Vector2D offset, Vector2D size, Map<EnumBlockParams,Object> params){
        super(EnumBlocks.FORBIDDEN,offset,size,params);
    }

    @Override
    public Vector2D[] computeForces(MovingObject mo,Vector2D[] contacts) throws SimulationTerminated{
                 throw new SimulationTerminated(this,null,EnumSimulation.FORBIDDEN_BLOCK);
    }           
}