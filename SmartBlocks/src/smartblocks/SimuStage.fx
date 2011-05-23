/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package smartblocks;
import javafx.stage.Stage;
import java.util.EnumMap;
import java.util.Map;
import smartblocks.java.EnumBlockParams;
import smartblocks.java.EnumBlocks;
import smartblocks.java.EnumObjectParams;
import smartblocks.java.EnumObjects;
import smartblocks.java.SmartBlockUtilities;
import java.lang.System;

/**
 * @author david
 */

public class SimuStage extends Stage {

    public var objects : VisualObject[]=[];
    public var blocks : VisualBlock[]=[];



    public var blockParams : Map = new EnumMap(EnumBlockParams.class);
    public var objectParams : Map = new EnumMap(EnumObjectParams.class);

    public var showScene1:Boolean=true;
    public var showScene2:Boolean=false;
    public var showScene3:Boolean=false;



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
        objects: bind objects with inverse
        blocks: bind blocks with inverse
        content: bind  [
             canvas.objects, canvas.blocks, canvas.bottomButtonBox
        ] ;
    }

    // save and restore old stage size
    public var oldStageX = 0.0;
    public var oldStageY = 0.0;
    public var oldStageW = 0.0;
    public var oldStageH = 0.0;
    public function toggleFullscreen():Void {
        if(not fullScreen) {
            oldStageX = x;
            oldStageY = y;
            oldStageW = width;
            oldStageH = height;
        }
        fullScreen = not fullScreen;
        if(not fullScreen) {
            x = oldStageX;
            y = oldStageY;
            width = oldStageW;
            height = oldStageH;
        }
    }

    public function createBlock(){
        insert VisualBlock{
            block:SmartBlockUtilities.createBlock(EnumBlocks.ACCELERATOR,blockParams);
        } into blocks;
    }

    public function createObject(){
        insert VisualObject{
            mo: SmartBlockUtilities.createMovingObject(EnumObjects.PUNCTUAL,objectParams);
        } into objects;
    }

    public function setBlockParam(e:EnumBlockParams,v:Double){
        System.out.println("Set block params");
        blockParams.put(e, v);
    }

    public function setObjectParam(e:EnumObjectParams,v:Double){
        System.out.println("Set object params");
        objectParams.put(e, v);
    }

    public function switchScenes(numScene:Integer):Void{
        if(numScene==1){
            showScene1=true;
            showScene2=false;
            showScene3=false;
        }else if(numScene==2){
            showScene1=false;
            showScene2=true;
            showScene3=false;
        }else{
            showScene1=false;
            showScene2=false;
            showScene3=true;
        }
    }
 }
