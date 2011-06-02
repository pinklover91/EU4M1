/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks;

import smartblocks.EnumParamsGUI;

/**
 * @author David FUENMAYOR
 */

var stage:SimuStage=SimuStage{
    
    scene: bind if (stage.showObjectDialog) then stage.objectDialog
        else if (stage.showBlockDialog) then stage.blockDialog
        else stage.canvas

    title : "SmartBlocks Simulator"
    width : bind (stage.guiParams.get(EnumParamsGUI.SURF_DIMENSION_X) as Number)*EnumParamsGUI.PX_PER_METER.getDefValue();
    height : bind (stage.guiParams.get(EnumParamsGUI.SURF_DIMENSION_Y) as Number)*EnumParamsGUI.PX_PER_METER.getDefValue();
}