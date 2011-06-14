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

    /**
    * Sets to zero the forces and the torque to be applied to this object.
    * One can think of this forces as a buffer.
    */
    public void resetForces();

    /**
     * Applies the forces and torque added before.
     * Like flushing the "forces buffer"
     * @param dt
     */
    public void applyForces(float dt);

    /**
     * Adds the specified forces and torque to the "forces buffer"
     * It doesn't actually carry out any operation on this moving object
     * @param fx
     * @param fy
     * @param fz
     */
    public void addForces(float fx, float fy, float fz);


    /**
     * Updates the values of linear and angular position according to the time
     * interval specified and the current values of linear and angular momentum.
     * @param dt
     */
    public void updatePosition(float dt); 

    /**
     * Returns current angle of rotation of this object in radians
     * @return angle of rotation, clockwise
     */
    public float getRotation();

    /**
     * Returns the velocity vector of the moving object
     * @return Vector2D velocity vector
     */
    public Vector2D getVelocity();

    /**
     * Returns the angular velocity of the moving object in rad/s
     * @return angular velocity
     */
    public float getAngularVelocity();

    /**
     * Returns the momentum vector of this moving object
     * @return Vector2D linear momentum vector
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
     * @param px linear momentum in x direction
     * @param py linear momentum in y direction
     */
    public void setMomentum(float px, float py);

    /**
     * Rotates the object clockwise the given amount in radians
     * @param da The angle specified in radians
     */
    public void rotate(float da);

    /**
     * Sets the object to the specified angle, clockwise
     * @param a The angle specified in radians
     */
    public void setRotation(float a);

    /**
     * Translates the object the specified distance
     * @param dx delta x
     * @param dy delta y
     */
    public void translate(float dx, float dy);

    /**
     * Makes this object bounce towards the specified direction
     * @param direction
     */
    public void bounce(EnumDirections direction);

    /**
     * Returns the type of the object which determines its shape
     * @return type of this MovingObject
     */
    public EnumShapes getType();

}