/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package smartblocks.java;

import java.io.Serializable;
import java.util.EnumMap;
import java.util.Map;

/**
 * A punctual mass moving over the smart surfaces
 * @author david
 */
public class PunctualMass implements MovingObject, Serializable{

    /**
     * The position of the particle
     */
    protected Vector2D r;

    /**
     * The momentum of the particle
     */
    protected Vector2D p;

    /**
     * The mass of the particle
     */
    double m;

    /**
     * Parameters of the moving object
     */
    Map<EnumObjectParams,Double> params;

    /**
     * Default constructor
     */
    public PunctualMass(){
        r=new Vector2D(0,0);
        p=new Vector2D(0,0);
        m=1;
        params=new EnumMap(EnumObjectParams.class);
    }

    public PunctualMass(EnumObjects type,Map<EnumObjectParams,Double> params){
        this();
        this.params.putAll(params);
        m=params.get(EnumObjectParams.MASS);
        r.x=params.get(EnumObjectParams.X_0);
        r.y=params.get(EnumObjectParams.Y_0);
        p.x=params.get(EnumObjectParams.PX_0);
        p.y=params.get(EnumObjectParams.PY_0);
    }



    //*************Overriden Methods

    @Override
    public void applyForce(double fX, double fY, double dt) {
        p.x+=fX*dt;
        p.y+=fY*dt;
    }

    @Override
    public void applyTorque(double Tz, double dt) {
        // Does nothing
    }

    @Override
    public void updatePosition(double dt) {
        r.x+=p.x*dt/m;
        r.y+=p.y*dt/m;
    }

    @Override
    public void setPosition(Vector2D pos) {
        r.x=pos.x;
        r.y=pos.y;
    }

    @Override
    public void setPosition(double x, double y){
        r.x=x;
        r.y=y;
    }
    
    @Override
    public void setVelocity(Vector2D vel) {
        p.x=vel.x*m;
        p.y=vel.y*m;
    }

    @Override
    public Vector2D getVelocity() {
        return new Vector2D(p.x/m,p.y/m);
    }

    @Override
    public Vector2D getPosition() {
        return r;
    }

    @Override
    public double getX() {
        return r.x;
    }

    @Override
    public double getY() {
        return r.y;
    }

    @Override
    public void rotate(double angle) {
        // Does nothing
    }   


}
