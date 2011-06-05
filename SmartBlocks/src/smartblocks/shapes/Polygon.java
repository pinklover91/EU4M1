/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */
package smartblocks.shapes;

import smartblocks.utilities.Vector2D;

/**
 * A polygon
 * @author David FUENMAYOR
 *
 */
public strictfp class Polygon extends Circle {
	
	/**
         * Create a new polygon.
         * The actual offset and vertices of the polygon are calculated so
         * it behaves as a circle whose center is: offset + vertices' centroid
         * and radius is the radius of the vertices' bounding circle
         * @param vertices
         */
	public Polygon(Vector2D offset, Vector2D[] v) {
            float r = computeBoundingCircleRadius();
            this.area = computeArea();
            Vector2D center = computeCentroid();
            vertices = new Vector2D[v.length];
            System.arraycopy(v, 0, vertices, 0, v.length);
            for(int i=0;i<v.length;i++){
                        vertices[i].substract(center);
             }
            center.add(offset);
            setAsCircle(center,r);
	}

        protected void setAsCircle(Vector2D center, float r){
            centroid=new Vector2D(r,r);
            offset=Vector2D.substraction(center,centroid);
            size=Vector2D.scale(centroid,2f);
            radius = r;
        }
	
	/**
	 * For overloading
	 */
	protected Polygon() {}
	
	/**
	 * Computes the area as described by Paul Borke.
	 * See: http://local.wasp.uwa.edu.au/~pbourke/geometry/polyarea/
	 * 
	 * @return this polygon's computed area
	 */
	protected final float computeArea() {
		this.area = 0;		
		Vector2D v1, v2;
		
		for ( int i = 0; i < vertices.length; i++ ) {
			v1 = vertices[i];
			v2 = vertices[(i+1) % vertices.length];
			
			this.area += v1.x * v2.y;
			this.area -= v2.x * v1.y;
		}
		
		return Math.abs(this.area / 2f);
	}
	
	/**
	 * Compute the centroid (center of mass) as described by Paul Borke.
	 * See: http://local.wasp.uwa.edu.au/~pbourke/geometry/polyarea/
	 * 
	 * Make sure you have computed the area before calling this!
	 * 
	 * @return the computed centroid
	 */
	protected final Vector2D computeCentroid() {
		float x = 0;
		float y = 0;
		
		Vector2D v1, v2;
		
		for ( int i = 0; i < vertices.length; i++ ) {
			v1 = vertices[i];
			v2 = vertices[(i+1) % vertices.length];
			
			x += (v1.x + v2.x) * (v1.x * v2.y - v2.x * v1.y);
			y += (v1.y + v2.y) * (v1.x * v2.y - v2.x * v1.y);
		}
		
		return new Vector2D(x / (6 * this.area), y / (6 * this.area));
	}
	
	/**
	 * Computes the radius of an approximation of a minimal bounding circle
	 * which has its origin at the centroid.
	 * 
	 * @return 
	 */
	protected final float computeBoundingCircleRadius() {
		float r = 0;
		float l;
		
		for ( int i = 0; i < vertices.length; i++ ) {
                    Vector2D aux=Vector2D.substraction(vertices[i], centroid);
			l = aux.x * aux.x + aux.y * aux.y;
			r = l > r ? l : r;
		}
		
		return (float) Math.sqrt(r);
	}
	
	/**
	 * Check whether or not the polygon is convex.
	 * 
	 * @return true if this polygon is convex
	 */
	public boolean isConvex() {
		// check if all angles are smaller or equal to 180 degrees
		int l = vertices.length;
		
		for ( int i = 0; i < vertices.length; i++ ) {
			Vector2D x = vertices[i];
			Vector2D y = vertices[(i+1)%l];
			Vector2D z = vertices[(i+2)%l];
			
			// does the 3d cross product point up or down?
			if ( (z.x-x.x)*(y.y-x.y)-(y.x-x.x)*(z.y-x.y) >= 0 )
				return false;
		}
		
		return true;
	}

        /**
         * Returns a copy of the polygon's vertices
         * @param absolute if true applies transformations
         * @return
         */
        @Override
	public Vector2D[] getVertices(boolean absolute) {
		Vector2D[] vert = new Vector2D[vertices.length];
                System.arraycopy(vertices, 0, vert, 0, vertices.length);
		if(absolute){
                    for(int i=0;i<vertices.length;i++){
                        vert[i].rotate(angle);
                        vert[i].add(centroid);
                    }
                }
                return vert;
	}
}
