/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.javafx;
import javafx.stage.Stage;
import java.util.EnumMap;
import java.util.Map;
import smartblocks.block.EnumBlockParams;
import smartblocks.object.EnumObjectParams;
import java.lang.System;

/**
 * Root of the GUI for the Simulation
 * @author David Fuenmayor
 */

public class SimuStage extends Stage {
    

    public var guiParams : Map = new EnumMap(EnumParamsGUI.class);
    public var blockParams : Map = new EnumMap(EnumBlockParams.class);
    public var objectParams : Map = new EnumMap(EnumObjectParams.class);

    
    public var showCanvas:Boolean=true;
    public var showObjectDialog:Boolean=false;
    public var showBlockDialog:Boolean=false;    

    public var blockDialog : BlockDialog=BlockDialog{
        content : bind [
            blockDialog.inGroup
        ]
    }

    public var objectDialog : ObjectDialog=ObjectDialog{
        content : bind [
            objectDialog.inGroup
        ]
    }

     public var canvas:SimuCanvas= SimuCanvas{
        owner: bind this;
        content: bind  [
              canvas.boundBlocks, canvas.blocks, canvas.objects, canvas.message, canvas.bottomButtonBox
        ] ;
    }

    public function setBlockParam(e:EnumBlockParams,v:Float){
        System.out.println("Set block params");
        blockParams.put(e, v);
    }

    public function setGUIParam(e:EnumParamsGUI,v:Float){
        System.out.println("Set GUI params");
        guiParams.put(e, v);
    }

    public function setObjectParam(e:EnumObjectParams,v:Float){
        System.out.println("Set object params");
        objectParams.put(e, v);
    }

    public function getBlockParam(e:EnumBlockParams):Float{
        return blockParams.get(e) as Float;
    }

    public function getGuiParam(e:EnumParamsGUI):Float{
        return guiParams.get(e) as Float;
    }

    public function getObjectParam(e:EnumObjectParams):Float{
        return objectParams.get(e) as Float;
    }

    public function createObject(){
        canvas.createObject(objectParams);
    }

    public function switchScenes(numScene:Integer):Void{
        if(numScene==1){
            showCanvas=true;
            showObjectDialog=false;
            showBlockDialog=false;
        }else if(numScene==2){
            showCanvas=false;
            showObjectDialog=true;
            showBlockDialog=false;
        }else{
            showCanvas=false;
            showObjectDialog=false;
            showBlockDialog=true;
        }
    }
 }
