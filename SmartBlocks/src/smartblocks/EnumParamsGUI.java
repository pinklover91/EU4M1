/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package smartblocks;

/**
 *
 * @author david
 */
public enum EnumParamsGUI {

    
    PX_PER_METER("Pixels per meter, for conversions inside GUI",100.0,1),
    MATRIX_X("Number of blocks in X direction",8,2),
    MATRIX_Y("Number of blocks in Y direction",6,3),
    SURF_DIMENSION_X("X dimension of smarblocks' surface",6,4),
    SURF_DIMENSION_Y("Y dimension of smarblocks' surface",4,5);


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

