/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package smartblocks.java;

/**
 * Interface implemented by all objects to be used in the simulation
 * @author david
 */
public interface MovingObject {

    /**
     * Applies the force represented by the vector [fX,fY,0] during the specified
     * time, changing the linear momentum of the moving object.
     * @param fX
     * @param fY
     * @param dt
     */
    public void applyForce(double fX, double fY, double dt);
    
    /**
     * Applies the torque represented by the vector [0,0,Tz] during the specified
     * time, changing the angular momentum of the moving object.
     * @param Tz
     * @param dt
     */
    public void applyTorque(double Tz, double dt);

    /**
     * Updates the values of linear and angular position according to the time
     * interval specified and the current values of linear and angular momentum.
     * @param dt
     */
    public void updatePosition(double dt);

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
    public void setPosition(double x, double y);

    /**
     * Returns the upper-left point of the moving object
     * @return
     */
    public Vector2D getPosition();

/**
     * Returns the upper-left point of the moving object
     * @return
     */
    public double getX();

    /**
     * Returns the upper-left point of the moving object
     * @return
     */

    public double getY();
    /**
     * Returns the velocity vector of the moving object
     * @return
     */

    public Vector2D getVelocity();

    /**
     *
     * @param v
     */
    public void setVelocity(Vector2D vel);

    /**
     * Rotates the object to the angle specified
     * @param a The angle specified in radians
     */
    public void rotate(double a);

}
