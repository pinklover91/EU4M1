/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package smartblocks;


import javafx.stage.Stage;


import java.util.Map;
import java.util.EnumMap;
import smartblocks.java.EnumBlockParams;
import smartblocks.java.EnumObjectParams;
import smartblocks.java.EnumBlocks;
import smartblocks.java.SmartBlockUtilities;
import smartblocks.java.EnumObjects;

/**
 * @author david
 */

var stage:SimuStage=SimuStage{

    scene: bind if (stage.showScene2) then stage.objectDialog
        else if (stage.showScene3) then stage.blockDialog
        else stage.canvas

    title : "SmartBlocks Simulator"
    width : 400
    height : 372
}


