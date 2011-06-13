/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.shapes;

/**
 *
 * @author David FUENMAYOR
 */
public enum EnumShapes {
    PUNCTUAL(0,0,1),
    POLYGON(0,0,1),
    CIRCLE(0,0,1),
    BOX(0,0,1);
    
    float posx;
    float posy;
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
