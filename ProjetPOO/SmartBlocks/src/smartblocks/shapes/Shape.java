/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */
package smartblocks.shapes;

import smartblocks.utilities.Vector2D;

/**
 * An interface representing the geometric shape of a simulation object or block
 * 
 * @author David FUENMAYOR
 */
public interface Shape {

    /**
     * Get the width of the box
     *
     * @return The width of the box
     */
    public float getWidth();

    /**
     * Get the height of the box
     * @return The height of the box
     */
    public float getHeight();

    /**
     * Get the x offset to the body's position of this bounds
     * @return The x offset to the body's position of this bounds
     */
    public float getX();

    /**
     * Get the y offset to the body's position of this bounds
     * @return The y offset to this body's position of this bounds
     */
    public float getY();

        /**
         * Gets the area of the Shape
         * @return Area of the Shape
         */
	public float getArea();

        /**
         * Gets the coordinates of the centroid of this shape
         * @param absolute If true, adds this.getBounds().offset to the return value
         * @return X and Y coordinates of the centroid
         */
        public Vector2D getCentroid(boolean absolute);

        /**
         * Gets an array with a copy of the vertices of this Shape
         * @param absolute if true the vertices are rotated around the centroid 
         * and then translated according to the centroid's position
         * @return Vector2D array with the vertices of this Shape copied
         */
        public Vector2D[] getVertices(boolean absolute);

        /**
         * Sets the vertices of this Shape. Copies the values.
         * @param vertices
         */
        public void setVertices(Vector2D[] vertices);

        /**
         * Rotates the specified angle around the centroid of this shape
         * @param da angle in radians
         */
        public void rotate(float da);

        /**
         * Sets the specified angle around the centroid of this shape
         * @param a angle in radians
         */
        public void setRotation(float a);

        /**
         * Gets the rotation angle of this Shape
         * @return angle in radians
         */
        public float getRotation();

        /**
         * Translates this shape the specified amount
         * @param dr
         */
        public void translate(Vector2D dr);

        /**
         * Translates this shape the specified amount
         * @param dx
         * @param dy
         */
        public void translate(float dx, float dy);

        /**
         * Set new position of this shape
         * @param r Vector2D with the new position to be copied
         */
        public void setPosition(Vector2D r);

        /**
         * Set new position of this shape
         * @param x 
         * @param y
         */
        public void setPosition(float x, float y);

        /**
         * Tells if this shape overlaps another one
         * @param other Shape
         * @return true if it actually overlaps
         */
        public boolean overlaps(Shape other);

     /**
     * Tells if a point lies inside this box
     * @param point
     * @return true if the specified point lies inside this box
     */
        public boolean contains(Vector2D point);
}
