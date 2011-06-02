/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.simulation;

/**
 * Enumeration of causes indicating why the simulation has finished
 * @author David FUENMAYOR
 */
public enum EnumSimulation {
    FORBIDDEN_BLOCK,
    TARGET_BLOCK,
    TIME_OVER,
    EXTERNAL,
    ERROR;
}
