/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.block;

import smartblocks.simulation.SimulationTerminatedException;
import smartblocks.utilities.Vector2D;
import smartblocks.object.MovingObject;
import java.util.Map;
import smartblocks.shapes.Shape;
import smartblocks.simulation.SimulationObject;

/**
 *
 * @author David FUENMAYOR
 */
public interface Block extends SimulationObject{

    

    /**
     * Returns the shape of this block
     * @return
     */
    public Shape getShape();

    /**
     * 
     * @param x
     * @param y
     */
    public void setPosition(Vector2D r);

    /**
     *
     * @return
     */
    public Map<EnumBlockParams,Object> getParams();

    /**
     *
     * @param paramName
     * @return
     */
    public Object getParam(EnumBlockParams param);

    /**
     *
     * @param paramName
     * @param value
     */
    public void setParam(String paramName, Object value);

    /**
     * Returns the type of block
     * @return Type of this block
     */
    public EnumBlocks getType();
    

}
