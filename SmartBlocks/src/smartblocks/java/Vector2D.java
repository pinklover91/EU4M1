/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package smartblocks.java;

import java.io.Serializable;

/**
 *
 * @author david
 */
public class Vector2D implements Serializable{
    public double x, y;

    Vector2D(){
        x=0;
        y=0;
    }

    Vector2D(double x, double y){
        this.x=x;
        this.y=y;
    }

     /**
     * Returns distance between two vectors
     * @param r1
     * @param r2
     * @return
     */
    public static Vector2D distance(Vector2D r1, Vector2D r2){
        return new Vector2D(Math.abs(r1.x-r2.x),Math.abs(r1.y-r2.y));
    }

    public static Vector2D substraction(Vector2D r1, Vector2D r2){
        return new Vector2D(r1.x-r2.x,r1.y-r2.y);
    }

    public static double norm2(Vector2D r){
        return Math.sqrt(Math.pow(r.x,2)+Math.pow(r.y,2));
    }


    public static Vector2D sum(Vector2D r1, Vector2D r2){
        return new Vector2D(r1.x+r2.x,r1.y+r2.y);
    }

    public static Vector2D scale(Vector2D r, double a){        
        return new Vector2D(r.x*a,r.y*a);
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
