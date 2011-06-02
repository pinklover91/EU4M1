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
public class Vector2D implements Serializable{
    public double x, y;

    public Vector2D(){
        x=0;
        y=0;
    }

    public Vector2D(double x, double y){
        this.x=x;
        this.y=y;
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
     * Substracts vector r2 from vector r1
     * @param r1
     * @param r2
     * @return Vector2D (r2-r1)
     */
    public static Vector2D substraction(Vector2D r1, Vector2D r2){
        return new Vector2D(r1.x-r2.x,r1.y-r2.y);
    }

    /**
     * Computes the norm-2 of the specified vector r
     * @param r
     * @return sqrt(r.x^2 + r.y^2)
     */
    public static double norm2(Vector2D r){
        return Math.sqrt(Math.pow(r.x,2)+Math.pow(r.y,2));
    }

    /**
     * Adds r1 and r2
     * @param r1
     * @param r2
     * @return Vector2D (r1+r2)
     */
    public static Vector2D sum(Vector2D r1, Vector2D r2){
        return new Vector2D(r1.x+r2.x,r1.y+r2.y);
    }

    /**
     * Scales the specified vector by a factor of a
     * @param r
     * @param a
     * @return Vector2D (a*r)
     */
    public static Vector2D scale(Vector2D r, double a){        
        return new Vector2D(r.x*a,r.y*a);
    }

    /**
     * Returns the z-component of the cross product between r1 and r2
     * @param r1
     * @param r2
     * @return (r1 x r2).z
     */
    public static double cross(Vector2D r1, Vector2D r2){
        return r1.x * r2.y - r1.y * r2.x;
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
        if (Double.doubleToLongBits(this.x) != Double.doubleToLongBits(other.x)) {
            return false;
        }
        if (Double.doubleToLongBits(this.y) != Double.doubleToLongBits(other.y)) {
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
