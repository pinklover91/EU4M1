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
     * The mass of the object
     */
    double m;

    /**
     * Parameters of the moving object
     */
    Map<EnumObjectParams,Double> params;

    /**
     *
     * The type of this moving object
     */
    EnumObjects type;

    ObjectImpl(){
        r=new Vector2D(0,0);
        p=new Vector2D(0,0);
        m=1;
        params=new EnumMap(EnumObjectParams.class);
    }

    ObjectImpl(EnumObjects type){
        this();
        this.type=type;
    }

    ObjectImpl(EnumObjects type,Map<EnumObjectParams,Double> params){
        this(type);
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
    public void translate(double dx, double dy){
        r.x+=dx;
        r.y+=dy;
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

    @Override
    public EnumObjects getType(){
        return type;
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
        if (Double.doubleToLongBits(this.m) != Double.doubleToLongBits(other.m)) {
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
        return hash;
    }
}
