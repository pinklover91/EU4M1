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

/**
 *
 * @author David FUENMAYOR
 */
public interface Block {

    /**
     *
     * @param mo
     * @param dt
     */
    public void operate(MovingObject mo, double dt) throws SimulationTerminatedException;

    /**
     * Returns the upper-left point of the block
     * @return
     */
    public double getX();

    /**
     * Returns the upper-left point of the block
     * @return
     */
    public double getY();

    /**
     * Returns the width of the block (left-right)
     * Used to compute the influence area of the block
     * @return
     */
    public double getWidth();

    /**
     * Returns the height of the block (up-down)
     * Used to compute the influence area of the block
     * @return
     */
    public double getHeight();


    /**
     * Returns the offset of the block as a vector
     * Used to compute the influence area of the block
     * @return
     */
    public Vector2D getOffset();

    /**
     * Returns the size of the block as a vector
     * Used to compute the influence area of the block
     * @return
     */
    public Vector2D getSize();

    /**
     * 
     * @param x
     * @param y
     */
    public void setPosition(double x, double y);

    /**
     *
     * @return
     */
    public Map<EnumBlockParams,Double> getParams();

    /**
     *
     * @param paramName
     * @return
     */
    public Double getParam(EnumBlockParams param);

    /**
     *
     * @param paramName
     * @param value
     */
    public void setParam(String paramName, Double value);

    /**
     * Returns the type of block
     * @return Type of this block
     */
    public EnumBlocks getType();

    /**
     * Returns the last force exerced by this block on a moving object
     * @return force vector
     */
    public Vector2D getLastForce();

}
