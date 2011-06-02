/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.block;

/**
 * Parameters of the blocks supported by Smart Blocks Simulator
 * @author David FUENMAYOR
 */
public enum EnumBlockParams {
    
    
    CONSTANT_FORCE_X("Constant Force in X direction",1.0,1),
    CONSTANT_FORCE_Y("Constant Force in Y direction",1.0,2),
    VISCOUS_COEF("Coeficient of viscous force -friction-",1.0,3),
    RIGID_COEF("Coeficient of spring-like force in all directions",1.0,4);

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
