/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package smartblocks.java;

import java.util.List;

/**
 *
 * @author david
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
     * Next step of simulation
     * @param dt
     * @throws SimulationTerminatedException
     */
    void nextStep(double dt) throws SimulationTerminatedException;

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
     * Deletes the specified block
     * @param block
     * @return
     */
    boolean deleteBlock(Block block);

    /**
     * Deletes the specified moving object
     * @param mo
     * @return
     */
    boolean deleteMovingObject(MovingObject mo);

}
