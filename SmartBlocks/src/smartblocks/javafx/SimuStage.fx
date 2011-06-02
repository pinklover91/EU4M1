/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package smartblocks.javafx;
import javafx.stage.Stage;
import java.util.EnumMap;
import java.util.Map;
import smartblocks.block.EnumBlockParams;
import smartblocks.block.EnumBlocks;
import smartblocks.object.EnumObjectParams;
import java.lang.System;

/**
 * @author david
 */

public class SimuStage extends Stage {

    //public var objects : VisualObject[]=[];
    //public var blocks : VisualBlock[]=[];


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
             canvas.objects, canvas.blocks, canvas.bottomButtonBox
        ] ;
    }

    public function setBlockParam(e:EnumBlockParams,v:Double){
        System.out.println("Set block params");
        blockParams.put(e, v);
    }

    public function setGUIParam(e:EnumParamsGUI,v:Double){
        System.out.println("Set GUI params");
        guiParams.put(e, v);
    }

    public function setObjectParam(e:EnumObjectParams,v:Double){
        System.out.println("Set object params");
        objectParams.put(e, v);
    }

    public function getBlockParam(e:EnumBlockParams):Double{
        return blockParams.get(e) as Double;
    }

    public function getGuiParam(e:EnumParamsGUI):Double{
        return guiParams.get(e) as Double;
    }

    public function getObjectParam(e:EnumObjectParams):Double{
        return objectParams.get(e) as Double;
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
