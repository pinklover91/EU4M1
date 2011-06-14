/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.shapes;

/**
 * Enumeration of the different types of shapes supported by this application
 * @author David FUENMAYOR
 */
public enum EnumShapes {
    PUNCTUAL(0,0,0.05f),
    POLYGON(0,0,1),
    CIRCLE(0,0,0.2f),
    BOX(0,0,0.2f);

    /**
     * Default value used in the x position
     */
    float posx;
    /**
     * Default value used in the y position
     */
    float posy;
    /**
     * Default value used in the size
     */
    float size;

    private EnumShapes(float posx, float posy, float size) {
        this.posx = posx;
        this.posy = posy;
        this.size = size;
    }

    public float getPosx() {
        return posx;
    }

    public float getPosy() {
        return posy;
    }

    public float getSize() {
        return size;
    }
}
