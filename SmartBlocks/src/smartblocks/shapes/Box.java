/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */
package smartblocks.shapes;

import smartblocks.utilities.Vector2D;

/**
 * A rectangle used for shape bounds. 
 * It cannot be rotated
 * @author David FUENMAYOR
 */
public strictfp class Box implements Shape{
	
    Vector2D offset;

    Vector2D size;

    protected Vector2D centroid;

    protected Vector2D[] vertices;

    float angle;
    
    float area;

    /**
     *
     * @param offset
     * @param size
     */
    public Box(Vector2D offset, Vector2D size) {
            this.offset = offset;
            this.size = size;
            angle=0;
            area=size.x*size.y;
            centroid= Vector2D.scale(size,0.5f);
            vertices=new Vector2D[4];
            vertices[0]=Vector2D.scale(size,-0.5f);
            vertices[1]=new Vector2D(-centroid.x,centroid.y);
            vertices[2]=new Vector2D(centroid);
            vertices[3]=new Vector2D(centroid.x,-centroid.y);
    }

    /**
     * For overloading
     */
    protected Box(){
        
    }

    @Override
    public float getWidth() {
            return size.x;
    }

    @Override
    public float getHeight() {
            return size.y;
    }

    @Override
    public float getX() {
            return offset.x;
    }

    @Override
    public float getY() {
            return offset.y;
    }

    @Override
    public float getArea(){
        return area;
    }

    @Override
    public Vector2D getCentroid(boolean absolute){
        Vector2D ret=new Vector2D(centroid);
        if(absolute) ret.add(offset);
        return  ret;
    }
	
    @Override
    public boolean overlaps(Shape other) {
            float totalWidth = (other.getWidth() + size.x) / 2;
            float totalHeight = (other.getHeight() + size.y) / 2;
            Vector2D oCent=other.getCentroid(true);
            Vector2D cent=getCentroid(true);
            float dx = Math.abs(cent.x - oCent.x);
            float dy = Math.abs(cent.y - oCent.y);
            return (totalWidth > dx) && (totalHeight > dy);
    }

    @Override
    public boolean contains(Vector2D point){
        Vector2D aux=Vector2D.sum(size, offset);
        if(point.x>offset.x&&point.y>offset.y){
            if(point.x<aux.x&&point.y<aux.y){
                return true;
            }
        }
        return false;
    }
    
    @Override
    public Vector2D[] getVertices(boolean absolute) {
        Vector2D cen=getCentroid(true);
        Vector2D[] ret=new Vector2D[vertices.length];
        System.arraycopy(vertices, 0, ret, 0, vertices.length);
        if(absolute){
            for(int i=0;i<4;i++){
                ret[i].add(cen);
            }
        }
        return ret;        
    }

    @Override
    public void setVertices(Vector2D[] v) {
        vertices=new Vector2D[v.length];
        System.arraycopy(v, 0, vertices, 0, v.length);
    }

    @Override
    public void rotate(float da) {
        angle+=da;
    }

    @Override
    public void setRotation(float angle) {
        this.angle=angle;
    }

    @Override
    public float getRotation() {
        return angle;
    }

    @Override
    public void translate(Vector2D dr) {
        offset.add(dr);
    }

    @Override
    public void translate(float dx, float dy) {
        offset.x+=dx;
        offset.y+=dy;
    }

    @Override
    public void setPosition(Vector2D r) {
        offset.x=r.x;
        offset.y=r.y;
    }

    @Override
    public void setPosition(float x, float y) {
        offset.x=x;
        offset.y=y;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final Box other = (Box) obj;
        if (this.offset != other.offset && (this.offset == null || !this.offset.equals(other.offset))) {
            return false;
        }
        if (this.size != other.size && (this.size == null || !this.size.equals(other.size))) {
            return false;
        }
        return true;
    }

    @Override
    public int hashCode() {
        int hash = 7;
        hash = 29 * hash + (this.offset != null ? this.offset.hashCode() : 0);
        hash = 29 * hash + (this.size != null ? this.size.hashCode() : 0);
        return hash;
    }




}
