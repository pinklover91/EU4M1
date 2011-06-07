/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.simulation;

import smartblocks.utilities.CollisionOcurred;
import smartblocks.utilities.Vector2D;
import smartblocks.utilities.Vector3D;

/**
 *
 * @author David FUENMAYOR
 */
public interface SimulationObject {

    /**
     * Calculate forces and torques resulting from the
     * interaction with the specified simulation object
     * 
     * @param mo
     * @param dt
     * @return true if an interaction occurred
     */
    public boolean operate(SimulationObject so, float dt) throws SimulationTerminated,CollisionOcurred;

    /**
     * Returns the last force exerted by this block on a moving object
     * @return force vector
     */
    public Vector2D getLastForce();

    /**
     * Returns the last torque exerted by this block on a moving object
     * @return torque in Z direction
     */
    public float getLastTorque();

}
