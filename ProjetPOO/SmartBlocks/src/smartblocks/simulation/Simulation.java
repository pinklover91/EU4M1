/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.simulation;

import smartblocks.object.MovingObject;
import java.util.List;
import smartblocks.block.Block;

/**
 * Interface representing the current simulation
 * @author David FUENMAYOR
 */
public interface Simulation {

    /**
     * Inserts new block into simulation
     * @param b
     */
    void insertBlock(Block b);    

    /**
     * Inserts new moving object into simulation
     * @param mo
     */
    void insertMovingObject(MovingObject mo);

    /**
     * Creates and adds new moving object into simulation
     * @return
     */
    MovingObject createMovingObject();

    /**
     * Creates and adds new block into simulation
     * @return
     */
    Block createBlock();

    /**
     * Generates the next step of simulation
     * @param dt time interval
     * @throws SimulationTerminated
     */
    void nextStep(float dt) throws SimulationTerminated;

    /**
     * Returns the List of blocks for this simulation
     * @return
     */
    List<Block> getBlocks();

    /**
     * Returns the List of moving objects for this simulation
     * @return
     */
    List<MovingObject> getMovingObjects();

    /**
     * Removes the specified block from the list of blocks
     * @param block the block to remove from the list
     * @return true if the given block existed in the list and was succesfully removed
     */
    boolean deleteBlock(Block block);

    /**
     * Removes the specified moving object from the list of moving objects
     * @param mo the object to remove from the list
     * @return true if the given object existed in the list and was succesfully removed
     */
    boolean deleteMovingObject(MovingObject mo);

}
