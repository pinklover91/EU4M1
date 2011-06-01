/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package smartblocks;

import smartblocks.EnumParamsGUI;

/**
 * @author david
 */

var stage:SimuStage=SimuStage{
    
    scene: bind if (stage.showObjectDialog) then stage.objectDialog
        else if (stage.showBlockDialog) then stage.blockDialog
        else stage.canvas

    title : "SmartBlocks Simulator"
    width : bind (stage.guiParams.get(EnumParamsGUI.SURF_DIMENSION_X) as Number)*EnumParamsGUI.PX_PER_METER.getDefValue();
    height : bind (stage.guiParams.get(EnumParamsGUI.SURF_DIMENSION_Y) as Number)*EnumParamsGUI.PX_PER_METER.getDefValue();
}