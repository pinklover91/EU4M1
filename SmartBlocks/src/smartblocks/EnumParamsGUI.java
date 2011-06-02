/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks;

/**
 *
 * @author David FUENMAYOR
 */
public enum EnumParamsGUI {

    
    PX_PER_METER("Pixels per meter, for conversions inside GUI",100.0,1),
    MATRIX_X("Number of blocks in X direction",6,2),
    MATRIX_Y("Number of blocks in Y direction",4,3),
    SURF_DIMENSION_X("X dimension of smarblocks' surface",8,4),
    SURF_DIMENSION_Y("Y dimension of smarblocks' surface",6,5);


    String description;
    double defValue;
    int index;

    EnumParamsGUI(String s, double d,int in){
        description=s;
        index=in;
        defValue=d;
    }

    public String getDescription() {
        return description;
    }

    public int getIndex() {
        return index;
    }

    public double getDefValue() {
        return defValue;
    }
}

