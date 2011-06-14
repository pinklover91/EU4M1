/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.object;

import java.io.Serializable;
import java.util.EnumMap;
import java.util.Map;
import smartblocks.shapes.EnumShapes;
import smartblocks.utilities.Vector2D;
import smartblocks.shapes.Shape;
import smartblocks.shapes.ShapeFactory;
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
     * The linear momentum of the object
     */
    protected Vector2D p;

    /**
     * The angular momentum of the object
     */
    protected float l;

    /**
     * The shape of the object
     */
    protected Shape shape;

    /**
     * The mass of the object
     */
    protected float m;

    /**
     * The rotational inertia of the object
     */
    protected float inertia;    

    /**
     * Parameters of the moving object
     */
    Map<EnumObjectParams,Object> params;

    /**
     *
     * The type of this moving object
     */
    EnumShapes type;    

    /**
     * Last force exerted on this moving object by another SimulationObject
     */
    protected Vector2D f;    

    /**
     * Last torque exerted on this moving object by another SimulationObject
     */
    protected float tq;

    ObjectImpl(){        
        p=new Vector2D();        
        f=new Vector2D();       
        m=1f;
        params=new EnumMap(EnumObjectParams.class);
    }

    ObjectImpl(EnumShapes type){
        this();
        shape=ShapeFactory.getInstance().createShape(type);        
        this.type=type;
    }

    ObjectImpl(EnumShapes type,Map<EnumObjectParams,Object> params){
        this(type);
        this.params.putAll(params);
        m=(Float)params.get(EnumObjectParams.MASS);
        Vector2D r=new Vector2D();
        r.x=(Float)params.get(EnumObjectParams.X_0);
        r.y=(Float)params.get(EnumObjectParams.Y_0);
        shape.setPosition(r); 
        p.x=(Float)params.get(EnumObjectParams.PX_0);
        p.y=(Float)params.get(EnumObjectParams.PY_0);
    }

    //*************Overriden Methods

    @Override
    public void resetForces(){
        f.x=0;
        f.y=0;
        tq=0;
    }


    @Override
    public void applyForces(float dt){
        p.x+=f.x*dt;
        p.y+=f.y*dt;
        l+=tq*dt;
    }


    @Override
    public void addForces(float fx, float fy, float tz){
        f.x+=fx;
        f.y+=fy;
        tq+=tz;
    }

    @Override
    public void updatePosition(float dt) {
        shape.rotate(l*dt);
        shape.translate(p.x*dt/m, p.y*dt/m);
    }

    @Override
    public void setPosition(Vector2D pos) {
        this.shape.setPosition(pos);       
    }

    @Override
    public void translate(float dx, float dy){
        shape.translate(dx, dy);
    }    

    @Override
    public void setMomentum(Vector2D mom) {
        p.x=mom.x;
        p.y=mom.y;
    }

    @Override
    public void setMomentum(float px, float py) {
        p.x=px;
        p.y=py;
    }

    @Override
    public Vector2D getVelocity() {
        return new Vector2D(p.x/m,p.y/m);
    }

    @Override
    public float getAngularVelocity(){
        return l/inertia;
    }

    @Override
    public Vector2D getMomentum() {
        return new Vector2D(p.x,p.y);
    }

    @Override
    public float getAngularMomentum(){
        return l;
    }

    @Override
    public float getRotation(){
        return shape.getRotation();
    }
    
    @Override
    public Shape getShape(){
        return shape;
    }


    @Override
    public Vector2D getPosition() {
        return shape.getCentroid(true);
    }
    

    @Override
    public void rotate(float da) {
        shape.rotate(da);
    }

    @Override
    public void setRotation(float angle) {
        shape.setRotation(angle);
    }

    @Override
    public EnumShapes getType(){
        return type;
    }

    @Override
    public Vector2D[] computeForces(MovingObject mo,Vector2D[] vertices){
        //TODO
        return new Vector2D[vertices.length];
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
    public boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final ObjectImpl other = (ObjectImpl) obj;        
        if (!this.shape.equals(other.shape)) {
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
        hash = 67 * hash + (this.p != null ? this.p.hashCode() : 0);
        hash = 67 * hash + Float.floatToIntBits(this.m);
        hash = 67 * hash + (this.type != null ? this.type.hashCode() : 0);
        return hash;
    }   
}
