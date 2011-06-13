/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.simulation;

import smartblocks.object.MovingObject;
import smartblocks.shapes.Shape;
import smartblocks.utilities.CollisionOcurred;
import smartblocks.utilities.Vector2D;

/**
 * Common interface representing an object used during the simulation, such as
 * a block or a moving object.
 * @author David FUENMAYOR
 */
public interface SimulationObject {

    /**
     * Returns the shape of this SimulationObject
     * @return
     */
    public Shape getShape();

    /**
     * Sets the position of this SimulationObject
     * @param r Vector2D
     */
    public void setPosition(Vector2D r);

    /**
     * Returns the position of this SimulationObject
     * @return
     */
    public Vector2D getPosition();
       
    /**
     * Computes the forces and torques to be exerted by this object from a set of
     * points giving the coordinates of the vertices of the colliding moving object
     * with respect to the offset of this object.
     * @param contacts array of Vector2D giving the colliding vertices
     * @return array of Vector2D giving the forces on every vertex
     * @throws CollisionOcurred
     * @throws SimulationTerminated
     */
    public Vector2D[] computeForces(MovingObject mo, Vector2D[] contacts) throws CollisionOcurred,SimulationTerminated;
}
