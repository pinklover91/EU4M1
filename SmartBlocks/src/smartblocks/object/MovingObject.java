/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.object;

import smartblocks.shapes.EnumShapes;
import smartblocks.simulation.SimulationObject;
import smartblocks.utilities.EnumDirections;
import smartblocks.utilities.Vector2D;

/**
 * Interface implemented by all objects to be used in the simulation
 * @author David FUENMAYOR
 */
public interface MovingObject extends SimulationObject{


    public void resetForces();

    public void applyForces(float dt);

    public void addForces(float fx, float fy, float fz);


    /**
     * Updates the values of linear and angular position according to the time
     * interval specified and the current values of linear and angular momentum.
     * @param dt
     */
    public void updatePosition(float dt); 

    /**
     * Returns current angle of this object in radians
     * @return
     */
    public float getRotation();

    /**
     * Returns the velocity vector of the moving object
     * @return Vector2D velocity vector
     */
    public Vector2D getVelocity();

    /**
     * Returns the angular velocity of the moving object     *
     * @return angular velocity
     */
    public float getAngularVelocity();

    /**
     * Returns the momentum vector of the moving object
     * @return
     */
    public Vector2D getMomentum();


    /**
     * Returns the angular momentum of this moving object
     * @return angular momentum
     */
    public float getAngularMomentum();

    /**
     * Sets momentum for this moving object
     * @param mom
     */
    public void setMomentum(Vector2D mom);

    /**
     * Sets momentum for this moving object
     * @param px
     * @param py
     */
    public void setMomentum(float px, float py);

    /**
     * Rotates the object the given amount in radians
     * @param a The angle specified in radians
     */
    public void rotate(float da);

    /**
     * Sets the object to the specified angle
     * @param a The angle specified in radians
     */
    public void setRotation(float da);

    /**
     * Translates the object the specified distance
     * @param dx
     * @param dy
     */
    public void translate(float dx, float dy);

    /**
     * Makes this object bounce towards the specified direction
     * @param direction
     */
    public void bounce(EnumDirections direction);

    /**
     * Returns the type of the object which determines its shape
     */
    public EnumShapes getType();

}