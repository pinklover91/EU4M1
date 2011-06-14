/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.simulation;

import smartblocks.block.Block;
import smartblocks.object.MovingObject;

/**
 * Throwable indicating when the simulation should end
 * @author David FUENMAYOR
 */
public class SimulationTerminated extends Throwable{

    Block sourceBlock;
    MovingObject sourceObject;
    EnumSimulation reason;


    public SimulationTerminated(EnumSimulation reason){
        super();
        this.reason=reason;
    }

    public SimulationTerminated(Block sourceBlock, MovingObject sourceObject,EnumSimulation reason){
        this(reason);
        this.sourceBlock=sourceBlock;
        this.sourceObject=sourceObject;        
    }

    @Override
    public String getMessage() {
        return "Smartblocks simulation is over: "+reason.name();
    }

    /**
     * Returns a reference to the moving object that caused this
     * @return MovingObject source of all this trouble
     */
    public MovingObject getSourceObject() {
        return sourceObject;
    }

    /**
     * Sets the source of all this trouble
     * @param sourceObject
     */
    public void setSourceObject(MovingObject sourceObject) {
        this.sourceObject = sourceObject;
    }


}
