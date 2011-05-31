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
    
    
    CONSTANT_FORCE_X("Constant Force in X direction of acc. blocks",1.0,1),
    CONSTANT_FORCE_Y("Constant Force in Y direction of  acc. blocks",1.0,2),
    VISCOUS_COEF("Coeficient of viscous force in all directions",1.0,3),
    RIGID_COEF("Coeficient of the distant dependent force in all directions",1.0,4);

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
