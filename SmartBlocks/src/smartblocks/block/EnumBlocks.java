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
    BOUNDING("Toggles object's velocity"),
    VISCOUS("Applies a force to the moving object according to its velocity"),
    TARGET("Desired object's final location"),
    PROPORTIONAL("Block whose force is proportional to the object's distance"),
    FORBIDDEN("The object should never get to this location");
    

    String description;
   

    EnumBlocks(String d){
        description=d;
        
    }

    public String getDescription() {
        return description;
    }


}
