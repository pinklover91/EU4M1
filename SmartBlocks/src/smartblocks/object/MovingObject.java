/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.object;

import smartblocks.simulation.SimulationObject;
import smartblocks.utilities.EnumDirections;
import smartblocks.utilities.Vector2D;

/**
 * Interface implemented by all objects to be used in the simulation
 * @author David FUENMAYOR
 */
public interface MovingObject extends SimulationObject{

    /**
     * Applies the force represented by the vector [fX,fY,0] during the specified
     * time, changing the linear momentum of the moving object.
     * @param fX
     * @param fY
     * @param dt
     */
    public void applyForce(float fX, float fY, float dt);
    
    /**
     * Applies the torque represented by the vector [0,0,Tz] during the specified
     * time, changing the angular momentum of the moving object.
     * @param Tz
     * @param dt
     */
    public void applyTorque(float Tz, float dt);

    /**
     * Updates the values of linear and angular position according to the time
     * interval specified and the current values of linear and angular momentum.
     * @param dt
     */
    public void updatePosition(float dt);

    /**
     * Translates the object to the new location
     * @param pos
     */
    public void setPosition(Vector2D pos);

    /**
     * Translates the object to the new location
     * @param x
     * @param y
     */
    public void setPosition(float x, float y);

    /**
     * Returns the upper-left point of the moving object
     * @return
     */
    public Vector2D getPosition();

/**
     * Returns the upper-left point of the moving object
     * @return
     */
    public float getX();

    /**
     * Returns the upper-left point of the moving object
     * @return
     */

    public float getY();

    /**
     * Returns the velocity vector of the moving object
     * @return
     */
    public Vector2D getVelocity();

    /**
     * Returns the momentum vector of the moving object
     * @return
     */
    public Vector2D getMomentum();

    /**
     *
     * @param v
     */
    public void setVelocity(Vector2D vel);

    /**
     * Rotates the object to the angle specified
     * @param a The angle specified in radians
     */
    public void rotate(float a);

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
    public EnumObjects getType();

}