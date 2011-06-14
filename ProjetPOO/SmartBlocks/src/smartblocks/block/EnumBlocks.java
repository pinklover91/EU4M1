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
    FREE("Applies no force to the moving object"),
    ACCELERATOR("Applies a constant force to the moving object"),
    ACCELERATOR_UP("Applies a constant upwards force to the moving object"),
    ACCELERATOR_LEFT("Applies a constant leftwards force to the moving object"),
    ACCELERATOR_DOWN("Applies a constant downwards force to the moving object"),
    ACCELERATOR_RIGHT("Applies a constant rightwards force to the moving object"),    
    VISCOUS("Applies a force to the moving object according to its velocity"),
    TARGET("Desired object's final location"),
    PROPORTIONAL("Block whose force is proportional to the object's distance"),
    FORBIDDEN("The object should never get to this location"),
    BOUNDING("Toggles object's velocity");
    

    String description;
   

    EnumBlocks(String d){
        description=d;
        
    }

    public String getDescription() {
        return description;
    }


}
