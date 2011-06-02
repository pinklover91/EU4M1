/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.object;

/**
 * Types of blocks supported by Smart Blocks Simulator
 * @author David FUENMAYOR
 */
public enum EnumObjects {
    PUNCTUAL("Punctual mass"),
    RECTANGLE("Rectangular shape mass"),
    CIRCLE("Circular shape mass"),
    POLYGON("Free shape mass");

    String description;

    EnumObjects(String s){
        description=s;
    }

    public String getDescription() {
        return description;
    }

}
