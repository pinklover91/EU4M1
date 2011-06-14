/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.utilities;

import java.io.Serializable;

/**
 * Three-dimensional vector to be used in simulations. Just a Vector2D with extensions
 * @author David FUENMAYOR
 */
public strictfp class Vector3D extends Vector2D implements Serializable{
    /**
     * Third component of this three-dimensional vector
     */
    public float z;

    public Vector3D(){
        super();
        z=0;
    }

    public Vector3D(float x,float y,float z){
        super(x,y);
        this.z=z;
        
    }

    public Vector3D(Vector2D v){
        super(v);
        z=0;
    }

    /**
     * Adds the specified vector to this one
     * @param r2
     */
    @Override
    public void add(Vector2D r2){
        if(r2 instanceof Vector3D){
            z+=((Vector3D)r2).z;
        }
        super.add(r2);
    }

    /**
     * Substract the specified vector to this one
     * @param r2
     */
    @Override
    public void substract(Vector2D r2){
        if(r2 instanceof Vector3D){
            z-=((Vector3D)r2).z;
        }
        super.substract(r2);
    }

    /**
     * Scales this vector
     * @param a
     */
    @Override
    public void scale(float a){
        z*=a;
        super.scale(a);
    }    
    


    /**
     * Returns dot product between vectors
     * @param r1
     * @param r2
     * @return
     */    
    public static float dot(Vector2D r1, Vector2D r2){
        float aux=Vector2D.dot(r1,r2);
        if(r1 instanceof Vector3D && r2 instanceof Vector3D){
            return ((Vector3D)r1).z * ((Vector3D)r2).z + aux;
        }
        return aux;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final Vector3D other = (Vector3D) obj;
        if (Float.floatToIntBits(this.z) != Float.floatToIntBits(other.z)) {
            return false;
        }
        return super.equals(obj);
    }

    @Override
    public int hashCode() {
        int hash = 7;
        hash = 17 * hash + Float.floatToIntBits(this.z);
        hash = 17 * hash + super.hashCode();
        return hash;
    }
}
