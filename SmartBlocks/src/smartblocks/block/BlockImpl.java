/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.block;

import smartblocks.utilities.SmartBlockUtilities;
import smartblocks.utilities.Vector2D;
import java.io.Serializable;
import java.util.EnumMap;
import java.util.Map;
import smartblocks.simulation.SimulationTerminatedException;
import smartblocks.shapes.Shape;
import smartblocks.shapes.Box;
import smartblocks.simulation.SimulationObject;

/**
 * Default implementation of the Block interface
 * @author David FUENMAYOR
 */
class BlockImpl implements Block, Serializable{

     /**
     * Shape with the bounds of this block
     */
    protected Shape shape;

    /**
     * Last force exerted by this block
     */
    protected Vector2D force;

    /**
     * Last torque exerted by this block
     */
    protected Float torque;

    /**
     * Type of behavior of the block
     */
    EnumBlocks type;

    /**
     * Parameters of the block
     */
    Map<EnumBlockParams,Object> params;

    /**
     * Default constructor
     */
    BlockImpl(){
        this(EnumBlocks.FREE,new Vector2D(0f,0f),new Vector2D(0f,0f));
    }

    /**
     * Creates a new Block with the specified position and size
     * @param type Type of the block
     * @param offset Position of the block
     * @param size Size of the block
     */
     BlockImpl(EnumBlocks type, Vector2D offset, Vector2D size){
        this.shape=new Box(offset,size);
        this.type=type;        
        force=new Vector2D();
        torque=0f;
        params=new EnumMap(EnumBlockParams.class);
    }

     /**
      * Creates a new Block with the specified position, size and parameters
      * @param type Type of the block
      * @param offset Position of the block
      * @param size Size of the block
      * @param params
      */
    BlockImpl(EnumBlocks type, Vector2D offset, Vector2D size,Map<EnumBlockParams,Object> params){
        this(type,offset,size);
        this.params.putAll(params);        
    }

    //***************************Overriden methods********************

    @Override
    public void operate(SimulationObject mo, float dt)  throws SimulationTerminatedException{
        // Does nothing
    }

    @Override
    public Vector2D getLastForce() {
        return this.force;
    }

    @Override
    public float getLastTorque(){
        return this.torque;
    }

    @Override
    public Shape getShape(){
        return shape;
    }

    @Override
    public void setPosition(Vector2D r) {
        this.shape.setPosition(r);    
    }

    @Override
    public Map<EnumBlockParams,Object> getParams(){
        return params;
    }

    @Override
    public Float getParam(EnumBlockParams param){
        return params!=null?(Float)params.get(param):param.defValue;
    }

    @Override
    public void setParam(String paramName, Object value){
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
        hash = 53 * hash + (this.shape != null ? this.shape.hashCode() : 0);
        hash = 53 * hash + (this.type != null ? this.type.hashCode() : 0);
        return hash;
    }

    

    


}
