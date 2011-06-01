/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package smartblocks.java;

import java.io.Serializable;
import java.util.EnumMap;
import java.util.Map;

/**
 *
 * @author david
 */
public class BlockImpl implements Block, Serializable{

     /**
     * Coordinates of the upper-left point of the block
     */
    protected Vector2D offset;

    /**
     * height and width of the block
     */
    protected Vector2D size;

    /**
     * Type of behavior of the block
     */
    EnumBlocks type;

    /**
     * Parameters of the block
     */
    Map<EnumBlockParams,Double> params;

    /**
     * Default constructor
     */
    BlockImpl(){
        size=new Vector2D(0,0);
        offset=new Vector2D(0,0);
        params=new EnumMap(EnumBlockParams.class);
        type=EnumBlocks.FREE;
    }

     BlockImpl(Vector2D offset, Vector2D size){
        this.size=size;
        this.offset=offset;
        type=EnumBlocks.FREE;
    }

    BlockImpl(EnumBlocks type, Vector2D offset, Vector2D size,Map<EnumBlockParams,Double> params){
        this.params=new EnumMap(EnumBlockParams.class);
        this.params.putAll(params);
        this.size=size;
        this.offset=offset;
        this.type=type;
    }

    //***************************Overriden methods********************

    @Override
    public void operate(MovingObject mo, double dt) {
        // Does nothing
    }

    @Override
    public double getX() {
        return offset.x;
    }

    @Override
    public double getY() {
        return offset.y;
    }

    @Override
    public double getWidth() {
        return size.x;
    }

    @Override
    public double getHeight() {
        return size.y;
    }

    public Vector2D getSize(){
        return size;
    }

    public Vector2D getOffset(){
        return offset;
    }

    @Override
    public void setPosition(double x, double y) {
        this.offset.x=x;
        this.offset.y=y;
    }

    @Override
    public Map<EnumBlockParams,Double> getParams(){
        return params;
    }

    @Override
    public Double getParam(EnumBlockParams param){
        return (Double)params.get(param);
    }

    @Override
    public void setParam(String paramName, Double value){
        params.put(EnumBlockParams.valueOf(paramName), value);
    }

    @Override
    public EnumBlocks getType() {
        return this.type;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final AcceleratorBlock other = (AcceleratorBlock) obj;
        if (SmartBlockUtilities.overlaps(this,other)) {
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
        hash = 71 * hash + (this.offset != null ? this.offset.hashCode() : 0);
        hash = 71 * hash + (this.size != null ? this.size.hashCode() : 0);
        hash = 71 * hash + (this.type != null ? this.type.hashCode() : 0);
        hash = 71 * hash + (this.params != null ? this.params.hashCode() : 0);
        return hash;
    }

    


}
