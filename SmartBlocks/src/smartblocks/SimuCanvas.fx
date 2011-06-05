/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks;
import javafx.scene.layout.HBox;
import javafx.scene.text.Text;
import javafx.animation.Timeline;
import javafx.scene.Scene;
import javafx.animation.KeyFrame;
import javafx.scene.Group;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import smartblocks.simulation.Simulation;
import smartblocks.block.EnumBlocks;
import smartblocks.block.Block;
import smartblocks.simulation.SimulationTerminatedException;
import smartblocks.object.EnumObjects;
import java.util.Map;
import smartblocks.block.EnumBlockParams;
import smartblocks.object.EnumObjectParams;
import smartblocks.object.ObjectFactory;
import smartblocks.block.BlockFactory;
import javafx.scene.image.Image;
import java.lang.System;
import java.util.EnumMap;
import smartblocks.simulation.SimulationFactory;
import smartblocks.object.MovingObject;

/**
 * @author David FUENMAYOR
 */

public class SimuCanvas extends Scene {
    def TOOLBAR_WIDTH = 50;
    public var objects : VisualObject[];
    public var blocks : VisualBlock[];
    public var timeline : Timeline;
    public var dT:Duration=5ms;
    public var simulation:Simulation;
    public var owner:SimuStage;
    public var images:Map=new EnumMap(EnumBlocks.class);
    

    public function deleteBlock(vb:VisualBlock):Void{
        delete vb from blocks;
    }

    public function createObject(objectParams:Map){        
        insert VisualObject{
            mo: bind ObjectFactory.getInstance().createMovingObject(EnumObjects.PUNCTUAL,objectParams);
            
            
        } into objects;

    }

     function reset(){
        for (e in EnumParamsGUI.values())
                    owner.setGUIParam(e,e.getDefValue());
        for (e in EnumBlockParams.values())
                    owner.setBlockParam(e,e.getDefValue());
        for (e in EnumObjectParams.values())
                    owner.setObjectParam(e,e.getDefValue());

        for (e in EnumBlocks.values()){
            var img:Image=Image {
                        url: "{__DIR__}images/{e.name()}.PNG"
            }
            images.put(e, img)
        }

        var i:Integer=0;
        var j:Integer;
        var numX:Float=owner.getGuiParam(EnumParamsGUI.MATRIX_X);
        var numY:Float=owner.getGuiParam(EnumParamsGUI.MATRIX_Y);
        var offset;
        var w:Float=owner.getGuiParam(EnumParamsGUI.SURF_DIMENSION_X)/numX;
        var h:Float=owner.getGuiParam(EnumParamsGUI.SURF_DIMENSION_Y)/numY;

        while (i < numX) {
            j=0;
            while (j < numY) {
                System.out.println("Insert block {i},{j} in {i*w},{j*h} width: {w} height: {h}");

                insert VisualBlock{
                    block:BlockFactory.getInstance().createBlock(EnumBlocks.FREE,i*w,j*h,w,h,owner.blockParams);
                    images: bind images
                    owner: bind owner;
                }
                into blocks;
                j++;
            }
            i++;
        }
    }

    function play(){
        var b:Block;
        simulation=SimulationFactory.getInstance().createSimulation();
        for (vblock in blocks){
            b=vblock.block;
            if(b.getType()!=EnumBlocks.FREE){
                simulation.insertBlock(b);
            }
        }
        for (vmo in objects){
            simulation.insertMovingObject(vmo.mo);
        }

        timeline = Timeline {
        repeatCount: Timeline.INDEFINITE
        keyFrames :
            KeyFrame {
                time : dT
                canSkip : true
                action: function() {
                    try{
                        simulation.nextStep(dT.toMillis()/1000);
                        for (vmo in objects){
                            vmo.update();
                        }
                    }catch(ste:SimulationTerminatedException){
                         stop();
                    }
                }
            }
        };
        timeline.playFromStart();
   }

    function stop() {
        timeline.stop();
        timeline = null;
    }

    public var bottomButtonBox:HBox = HBox {
        translateX: bind (width - bottomButtonBox.layoutBounds.width)/2
        translateY: bind  5 + height - TOOLBAR_WIDTH
        spacing: 3
        content: [
            Group {
                content: [
                    Rectangle {
                        width: 70
                        height: 30
                        fill: Color.web("#CCCCCC")
                        stroke: Color.web("#BBBBBB")
                    }
                    Text {
                        translateX: 8
                        translateY: 20
                        content: "Object Params"
                    }
                ]
                onMouseClicked:function(e) {                    
                    (stage as SimuStage).switchScenes(2);
                }
            }
            Group {
                content: [
                    Rectangle {
                        width: 70
                        height: 30
                        fill: Color.web("#CCCCCC")
                        stroke: Color.web("#BBBBBB")
                    }
                    Text {
                        translateX: 8
                        translateY: 20
                        content: "Block Params"
                    }
                ]
                onMouseClicked:function(e) {
                    (stage as SimuStage).switchScenes(3);
                }
            }
            Group {
                content: [
                    Rectangle {
                        width: 60
                        height: 30
                        fill: Color.web("#CCCCCC")
                        stroke: Color.web("#BBBBBB")
                    }
                    Text {
                        translateX: 8
                        translateY: 20
                        content: bind if (timeline.running) then " Stop" else "Replay"
                    }
                ]
                onMouseClicked: function(e) {
                    if (timeline.running) stop() else play();
                }
            }
            Group {
                content: [
                    Rectangle {
                        width: 79
                        height: 30
                        fill: Color.web("#CCCCCC")
                        stroke: Color.web("#BBBBBB")
                    }
                    Text {
                        translateX: 8
                        translateY: 20
                        content: bind if (stage.fullScreen) then " Normal " else "Full Screen"
                    }
                ]
                onMouseClicked:function(e) {
                    //(stage as SimuStage).toggleFullscreen()
                }
            }
        ]
    };

    postinit{
        reset();
    }


   
}