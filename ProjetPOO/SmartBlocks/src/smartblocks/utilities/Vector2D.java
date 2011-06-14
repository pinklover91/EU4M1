/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.utilities;

import java.io.Serializable;

/**
 * Two-dimensional vector to be used in simulations
 * @author David FUENMAYOR
 */
public strictfp class Vector2D implements Serializable{
    /**
     * Components of this vector
     */
    public float x, y;

    public Vector2D(){
        x=0f;
        y=0f;
    }

    public Vector2D(float x, float y){
        this.x=x;
        this.y=y;
    }

    public Vector2D(Vector2D v){
        this.x=v.x;
        this.y=v.y;
    }

    /**
     * Adds the specified vector to this one
     * @param r2
     */
    public void add(Vector2D r2){
        x+=r2.x;
        y+=r2.y;
    }

    /**
     * Sets the components of this vector to zero
     */
    public void reset(){
        x=0;
        y=0;
    }

    /**
     * Substract the specified vector to this one
     * @param r2
     */
    public void substract(Vector2D r2){
        x-=r2.x;
        y-=r2.y;
    }

    /**
     * Multiplies this vector by the specified scalar
     * @param a
     */
    public void scale(float a){
        x*=a;
        y*=a;
    }

    /**
     * Rotates this vector the angle specified
     * @param a
     */
    public void rotate(float a){
        float ca=(float)Math.cos(a);
        float sa=(float)Math.sin(a);
        Vector2D row1= new Vector2D(ca,-sa);
        Vector2D row2= new Vector2D(sa,ca);
        x= dot(row1,this);
        y= dot(row2,this);
    }

     /**
     * Returns distance vector between two specified vectors
     * @param r1
     * @param r2
     * @return Vector2D with the absolute value of horizontal and vertical distances
     */
    public static Vector2D distance(Vector2D r1, Vector2D r2){
        return new Vector2D(Math.abs(r1.x-r2.x),Math.abs(r1.y-r2.y));
    }

    /**
     * Computed the mean of several two-dimensional vectors
     * @param v array of Vector2D
     * @return
     */
    public static Vector2D mean(Vector2D[] v){
        Vector2D ret=new Vector2D();
        int i=0;
        for(Vector2D w:v){
            i++;
            ret.add(w);
        }
        ret.scale(1/i);
        return ret;
    }

    /**
     * Substracts vector r2 from vector r1
     * @param r1
     * @param r2
     * @return Vector2D (r2-r1)
     */
    public static Vector2D substraction(Vector2D r1, Vector2D r2){
        Vector2D v= new Vector2D(r1);
        v.substract(r2);
        return v;
    }

    /**
     * Generates new Vector2D representing the clockwise rotation of this one by
     * the specified angle
     * @param r
     * @param a
     * @return
     */
    public static Vector2D rotation(Vector2D r,float a){
        Vector2D v= new Vector2D(r);
        v.rotate(a);
        return v;
    }

    /**
     * Computes the norm-2 of the specified vector r
     * @param r
     * @return sqrt(r.x^2 + r.y^2)
     */
    public static float norm2(Vector2D r){
        return (float)Math.sqrt(Math.pow(r.x,2)+Math.pow(r.y,2));
    }

    /**
     * Adds r1 and r2
     * @param r1
     * @param r2
     * @return Vector2D (r1+r2)
     */
    public static Vector2D sum(Vector2D r1, Vector2D r2){
        Vector2D v= new Vector2D(r1);
        v.add(r2);
        return v;
    }

    /**
     * Scales the specified vector by a factor of a
     * @param r
     * @param a
     * @return Vector2D (a*r)
     */
    public static Vector2D scale(Vector2D r, float a){
        return new Vector2D(r.x*a,r.y*a);
    }

    /**
     * Returns the z-component of the cross product between r1 and r2
     * @param r1
     * @param r2
     * @return (r1 x r2).z
     */
    public static float cross(Vector2D r1, Vector2D r2){
        return r1.x * r2.y - r1.y * r2.x;
    }

    /**
     * Returns dot product between vectors
     * @param r1
     * @param r2
     * @return
     */
    public static float dot(Vector2D r1, Vector2D r2){
        return r1.x * r2.x + r1.y * r2.y;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final Vector2D other = (Vector2D) obj;
        if (Float.floatToIntBits(this.x) != Float.floatToIntBits(other.x)) {
            return false;
        }
        if (Float.floatToIntBits(this.y) != Float.floatToIntBits(other.y)) {
            return false;
        }
        return true;
    }

    @Override
    public int hashCode() {
        int hash = 7;
        hash = 67 * hash + (int) (Float.floatToIntBits(this.x) ^ (Float.floatToIntBits(this.x) >>> 32));
        hash = 67 * hash + (int) (Float.floatToIntBits(this.y) ^ (Float.floatToIntBits(this.y) >>> 32));
        return hash;
    }
}
