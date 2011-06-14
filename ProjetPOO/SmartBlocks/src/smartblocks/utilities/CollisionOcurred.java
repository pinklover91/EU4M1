/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.utilities;

import smartblocks.simulation.SimulationObject;

/**
 * Generated when two objects collide
 * @author David FUENMAYOR
 */
public class CollisionOcurred extends Throwable{

    /**
     * Direction of collision
     */
    private EnumDirections direction;
    /**
     * Object that collided
     */
    private SimulationObject source;

    public CollisionOcurred(SimulationObject source,EnumDirections direction) {
        this.direction=direction;
        this.source=source;
    }

    public EnumDirections getDirection() {
        return direction;
    }

    public SimulationObject getSource() {
        return source;
    }
}