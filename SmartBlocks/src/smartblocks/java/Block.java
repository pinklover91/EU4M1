/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package smartblocks.java;

import java.util.Map;

/**
 *
 * @author david
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
     *
     * @return
     */
    public EnumBlocks getType();

}
