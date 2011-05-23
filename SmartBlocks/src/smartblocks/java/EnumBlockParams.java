/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package smartblocks.java;

/**
 * Parameters of the blocks supported by Smart Blocks Simulator
 * @author david
 */
public enum EnumBlockParams {
    
    POS_X("Horizontal position",0.0,1),
    POS_Y("Vertical position",0.0,2),
    WIDTH("Horizontal Width",10,3),
    HEIGHT("Vertical Height",10,4),
    CONSTANT_FORCE_X("Constant Force in X direction",0.0,5),
    CONSTANT_FORCE_Y("Constant Force in Y direction",0.0,6),
    VISCOUS_COEF("Coeficient of Viscous Force in all directions",0.0,7),
    RIGID_COEF("Coeficient of the distant dependent force in all directions",0.0,8);

    String description;
    double defValue;
    int index;

    EnumBlockParams(String s, double d,int in){
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
