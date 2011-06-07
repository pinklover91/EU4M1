/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.object;

import java.io.Serializable;
import java.util.EnumMap;
import java.util.Map;
import smartblocks.utilities.Vector2D;
import smartblocks.shapes.Shape;
import smartblocks.simulation.SimulationObject;
import smartblocks.simulation.SimulationTerminated;
import smartblocks.utilities.EnumDirections;
import smartblocks.utilities.Vector3D;

/**
 * Default implementation of the MovingObject interface
 * @author David FUENMAYOR
 */
public class ObjectImpl implements MovingObject, Serializable{

    /**
     * The position of the object's centroid
     */
    protected Vector2D r;

    /**
     * The momentum of the object
     */
    protected Vector2D p;

    /**
     * The shape of the object
     */
    protected Shape shape;

    /**
     * The mass of the object
     */
    float m;

    /**
     * Parameters of the moving object
     */
    Map<EnumObjectParams,Object> params;

    /**
     *
     * The type of this moving object
     */
    EnumObjects type;

    /**
     * Last force exerted by this moving object
     */
    protected Vector2D force;

    /**
     * Last torque exerted by this moving object
     */
    protected float torque;

    ObjectImpl(){
        r=new Vector2D();
        p=new Vector2D();
        force=new Vector2D();
        torque=0;
        m=1f;
        params=new EnumMap(EnumObjectParams.class);
    }

    ObjectImpl(EnumObjects type){
        this();
        this.type=type;
    }

    ObjectImpl(EnumObjects type,Map<EnumObjectParams,Object> params){
        this(type);
        this.params.putAll(params);
        m=(Float)params.get(EnumObjectParams.MASS);
        r.x=(Float)params.get(EnumObjectParams.X_0);
        r.y=(Float)params.get(EnumObjectParams.Y_0);
        p.x=(Float)params.get(EnumObjectParams.PX_0);
        p.y=(Float)params.get(EnumObjectParams.PY_0);
    }

    //*************Overriden Methods

    @Override
    public void applyForce(float fX, float fY, float dt) {
        p.x+=fX*dt;
        p.y+=fY*dt;
    }

    @Override
    public void applyTorque(float Tz, float dt) {
        // TODO: Does nothing
    }

    @Override
    public void updatePosition(float dt) {
        r.x+=p.x*dt/m;
        r.y+=p.y*dt/m;
    }

    @Override
    public void setPosition(Vector2D pos) {
        System.out.println("Set Position on object: "+pos.x+" "+pos.y);
        r.x=pos.x;
        r.y=pos.y;
    }

    @Override
    public void translate(float dx, float dy){
        r.x+=dx;
        r.y+=dy;
    }

    @Override
    public void setPosition(float x, float y){
        System.out.println("Set Position on object: "+x+" "+y);
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
    public Vector2D getMomentum() {
        return new Vector2D(p.x,p.y);
    }

    @Override
    public Vector2D getPosition() {
        return r;
    }

    @Override
    public float getX() {
        return r.x;
    }

    @Override
    public float getY() {
        return r.y;
    }

    @Override
    public void rotate(float angle) {
        // Does nothing
    }

    @Override
    public EnumObjects getType(){
        return type;
    }
    
    @Override
    public boolean operate(SimulationObject mo, float dt)  throws SimulationTerminated{
        //TODO: Not implemented yet
        return false;
    }

    @Override
    public void bounce(EnumDirections direction){
        switch(direction){
            case UP:
                p.y=-Math.abs(p.y);
                break;
            case DOWN:
                p.y=Math.abs(p.y);
                break;
            case LEFT:
                p.x=-Math.abs(p.x);
                break;
            case RIGHT:
                p.x=Math.abs(p.x);
                break;
            case ALL:
                p.x=-p.x;
                p.y=-p.y;
                break;
        }
    }

    @Override
    public Vector2D getLastForce() {
        return this.force;
    }

    @Override
    public float getLastTorque(){
        return this.torque;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final ObjectImpl other = (ObjectImpl) obj;
        if (this.r != other.r && (this.r == null || !this.r.equals(other.r))) {
            return false;
        }
        if (this.p != other.p && (this.p == null || !this.p.equals(other.p))) {
            return false;
        }
        if (Float.floatToIntBits(this.m) != Float.floatToIntBits(other.m)) {
            return false;
        }
        if (this.type != other.type) {
            return false;
        }
        return true;
    }

    @Override
    public int hashCode() {
        int hash = 7;
        hash = 67 * hash + (this.r != null ? this.r.hashCode() : 0);
        hash = 67 * hash + (this.p != null ? this.p.hashCode() : 0);
        hash = 67 * hash + Float.floatToIntBits(this.m);
        hash = 67 * hash + (this.type != null ? this.type.hashCode() : 0);
        return hash;
    }

   
}
