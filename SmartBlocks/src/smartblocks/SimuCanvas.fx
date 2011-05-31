/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
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
import smartblocks.SimuStage;
import smartblocks.java.Simulation;
import smartblocks.java.SmartBlockUtilities;
import smartblocks.java.EnumBlocks;
import smartblocks.java.Block;
import smartblocks.java.SimulationTerminatedException;
import smartblocks.java.EnumObjects;
import java.util.Map;
/**
 * @author david
 */

public class SimuCanvas extends Scene {
    def TOOLBAR_WIDTH = 50;
    public var objects : VisualObject[];
    public var blocks : VisualBlock[];
    public var timeline : Timeline;
    public var dT:Duration=5ms;
    public var simulation:Simulation;
    

    public function deleteBlock(vb:VisualBlock):Void{
        delete vb from blocks;
    }

    public function createObject(objectParams:Map){
        insert VisualObject{
            mo: bind SmartBlockUtilities.createMovingObject(EnumObjects.PUNCTUAL,objectParams);
        } into objects;

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
                    (stage as SimuStage).toggleFullscreen()
                }
            }
        ]
    };

    postinit{
        reset();
    }


    function reset(){
        var i:Integer=0;
        var j:Integer;
        var numX:Double=(stage as SimuStage).getGuiParam(EnumParamsGUI.MATRIX_X);
        var numY:Double=(stage as SimuStage).getGuiParam(EnumParamsGUI.MATRIX_Y);
        var offset;
        var w:Double=(stage as SimuStage).getGuiParam(EnumParamsGUI.SURF_DIMENSION_X)/numX;
        var h:Double=(stage as SimuStage).getGuiParam(EnumParamsGUI.SURF_DIMENSION_Y)/numY;

        while (i < numX) {
            j=0;
            while (j < numY) {
                insert VisualBlock{
                    block: SmartBlockUtilities.createBlock(EnumBlocks.FREE,i*w,j*h,w,h,(stage as SimuStage).blockParams);
                }
                into blocks;
            }
        }
    }

    function play(){
        var b:Block;
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
                        simulation.nextStep(dT.toSeconds());
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
}