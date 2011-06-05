/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */
package smartblocks.shapes;

import smartblocks.utilities.Vector2D;

/**
 * A Circle
 * @author David FUENMAYOR
 */
public strictfp class Circle extends Box{

        /** The radius of the circle */
	float radius;
	
	/**
	 * Create a new circle based on its radius
	 * @param radius The radius of the circle
	 */
	public Circle(Vector2D center,float r) {
            centroid=new Vector2D(r,r);
            offset=Vector2D.substraction(center,centroid);
            size=Vector2D.scale(centroid,2f);            
            area= 2f*(float)Math.PI*r;
            radius = r;
	}

        protected Circle(){

        }
        

	/**
	 * Get the radius of the circle 
	 * @return The radius of the circle
	 */
	public float getRadius() {
		return radius;
	}
	
	
	@Override
	public boolean overlaps(Shape other) {

            if(other instanceof Circle){
                Circle oth=(Circle)other;
                Vector2D oCent=oth.getCentroid(true);
                Vector2D cent=getCentroid(true);
                float totalRad2 = getRadius() + oth.getRadius();

		if (Math.abs(cent.x - oCent.x) > totalRad2) {
			return false;
		}
		if (Math.abs(cent.y - oCent.y) > totalRad2) {
			return false;
		}

		totalRad2 *= totalRad2;

		float dx = Math.abs(cent.x - oCent.x);
		float dy = Math.abs(cent.y - oCent.y);

		return totalRad2 >= ((dx*dx) + (dy*dy));
            }else return super.overlaps(other);
		
	}

    @Override
    public boolean contains(Vector2D point){
        Vector2D aux=Vector2D.substraction(point, offset);
        if(Vector2D.norm2(Vector2D.distance(aux,centroid))<radius){
                return true;
        }
        return false;
    }

    
}
