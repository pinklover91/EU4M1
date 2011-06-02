/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.block;

import smartblocks.utilities.SmartBlockUtilities;
import smartblocks.utilities.Vector2D;
import smartblocks.object.MovingObject;
import java.io.Serializable;
import java.util.EnumMap;
import java.util.Map;
import smartblocks.simulation.SimulationTerminatedException;

/**
 * Default implementation of the Block interface
 * @author David FUENMAYOR
 */
class BlockImpl implements Block, Serializable{

     /**
     * Coordinates of the upper-left point of the block
     */
    protected Vector2D offset;

    /**
     * height and width of the block
     */
    protected Vector2D size;

    /**
     * height and width of the block
     */
    protected Vector2D force;

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
        this(EnumBlocks.FREE,new Vector2D(0,0),new Vector2D(0,0));
    }

    /**
     * Creates a new Block with the specified position and size
     * @param type Type of the block
     * @param offset Position of the block
     * @param size Size of the block
     */
     BlockImpl(EnumBlocks type, Vector2D offset, Vector2D size){
        this.size=size;
        this.type=type;
        this.offset=offset;
        force=new Vector2D(0.0,0.0);
        params=new EnumMap(EnumBlockParams.class);
    }

     /**
      * Creates a new Block with the specified position, size and parameters
      * @param type Type of the block
      * @param offset Position of the block
      * @param size Size of the block
      * @param params
      */
    BlockImpl(EnumBlocks type, Vector2D offset, Vector2D size,Map<EnumBlockParams,Double> params){
        this(type,offset,size);
        this.params.putAll(params);        
    }

    //***************************Overriden methods********************

    @Override
    public void operate(MovingObject mo, double dt)  throws SimulationTerminatedException{
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
        return params!=null?(Double)params.get(param):param.defValue;
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
    public Vector2D getLastForce() {
        return this.force;
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
