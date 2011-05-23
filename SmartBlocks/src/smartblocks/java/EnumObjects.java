/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package smartblocks.java;

/**
 * Types of blocks supported by Smart Blocks Simulator
 * @author david
 */
public enum EnumObjects {
    PUNCTUAL("Punctual mass"),
    RECTANGLE("Rectangular shape mass"),
    CIRCLE("Circular shape mass"),
    POLYGON("Free shape mass");

    String description;

    EnumObjects(String s){
        description=s;
    }

    public String getDescription() {
        return description;
    }

}
