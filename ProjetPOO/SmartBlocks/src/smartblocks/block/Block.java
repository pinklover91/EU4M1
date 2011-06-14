/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.block;

import smartblocks.utilities.Vector2D;
import java.util.Map;
import smartblocks.shapes.Shape;
import smartblocks.simulation.SimulationObject;

/**
 * Interface for every block in the simulation
 * @author David FUENMAYOR
 */
public interface Block extends SimulationObject{

    /**
     * Get block parameters
     * @return Map with the block's parameters
     */
    public Map<EnumBlockParams,Object> getParams();

    /**
     * Gets the specified parameter
     * @param param
     * @return block parameter
     */
    public Object getParam(EnumBlockParams param);

    /**
     * Sets the specified parameter to its value
     * @param paramName
     * @param value
     */
    public void setParam(String paramName, Object value);

    /**
     * Returns the type of block
     * @return enum type of this block
     */
    public EnumBlocks getType();

    /**
     * Returns last force exerted by this block
     * @return
     */
    public Vector2D getForce();
    

}
