/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.simulation;

import smartblocks.block.Block;
import smartblocks.object.MovingObject;

/**
 *
 * @author David FUENMAYOR
 */
public class SimulationTerminatedException extends Exception{

    Block sourceBlock;
    MovingObject sourceObject;
    EnumSimulation reason;


    public SimulationTerminatedException(EnumSimulation reason){
        super();
        this.reason=reason;
    }

    public SimulationTerminatedException(Block sourceBlock, MovingObject sourceObject,EnumSimulation reason){
        this(reason);
        this.sourceBlock=sourceBlock;
        this.sourceObject=sourceObject;        
    }

    @Override
    public String getMessage() {
        return "Smartblocks simulation is over: "+reason.name();
    }
}
