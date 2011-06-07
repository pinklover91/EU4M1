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
 *
 * @author David FUENMAYOR
 */
class ForbiddenBlock extends BlockImpl{

    ForbiddenBlock(Vector2D offset, Vector2D size, Map<EnumBlockParams,Object> params){
        super(EnumBlocks.FORBIDDEN,offset,size,params);
    }

    @Override
    public boolean operate(SimulationObject so, float dt) throws SimulationTerminated{
        if(so instanceof MovingObject){
                MovingObject mo=(MovingObject)so;
            if(SmartBlockUtilities.getCollider(this.getType(), mo.getType()).collide(this, mo)!=null){
                throw new SimulationTerminated(this,mo,EnumSimulation.FORBIDDEN_BLOCK);
            }
        }
        return false;
    }
}