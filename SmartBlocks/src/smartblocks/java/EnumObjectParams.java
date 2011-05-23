/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package smartblocks.java;

/**
 * Parameters of the blocks supported by Smart Blocks Simulator
 * @author david
 */
public enum EnumObjectParams {

    
    X_0("Initial X coordenate",0.0,1),
    Y_0("Initial Y coordenate",0.0,2),
    PX_0("Initial X momentum",0.0,3),
    PY_0("Initial Y momentum",0.0,4),
    MASS("Mass of moving object",1.0,5),
    INERTIA("Momentum of inertia of moving object",1.0,6);

    String description;
    int index;
    double defValue;

    EnumObjectParams(String s, double d,int in){
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
