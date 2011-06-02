/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.block;

/**
 * Types of blocks supported by Smart Blocks Simulator
 * @author David FUENMAYOR
 */
public enum EnumBlocks {
    FREE("Applies no force to the moving object","f"),
    ACCELERATOR("Applies a constant force to the moving object","a"),
    BOUNCING("Toggles object's velocity","B"),
    VISCOUS("Applies a force to the moving object according to its velocity","v"),
    TARGET("Desired object's final location","T"),
    FORBIDDEN("The object should never get to this location","X");
    

    String description;
    String symbol;

    EnumBlocks(String d, String s){
        description=d;
        symbol=s;
    }

    public String getDescription() {
        return description;
    }

    public String getSymbol() {
        return symbol;
    }

}
