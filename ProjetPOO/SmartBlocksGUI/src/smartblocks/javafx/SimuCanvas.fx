/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.javafx;
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
import java.util.Map;
import smartblocks.block.EnumBlockParams;
import smartblocks.object.EnumObjectParams;
import smartblocks.object.ObjectFactory;
import smartblocks.block.BlockFactory;
import javafx.scene.image.Image;
import java.lang.System;
import java.util.EnumMap;
import smartblocks.simulation.SimulationFactory;
import smartblocks.utilities.EnumDirections;
import smartblocks.simulation.SimulationTerminated;
import smartblocks.shapes.EnumShapes;
import javafx.scene.image.ImageView;
import javafx.scene.text.Font;

/**
 * Canvas where all the objects involved in the Simulation are showed and animated
 * @author David FUENMAYOR
 */

public class SimuCanvas extends Scene {
    def TOOLBAR_WIDTH = 50;
    public var objects : VisualObject[];
    public var blocks : VisualBlock[];
    public var boundBlocks : VisualBlock[];
    public var timeline : Timeline;
    public var dT:Duration=5ms;
    public var simulation:Simulation;
    public var owner:SimuStage;
    public var images:Map=new EnumMap(EnumBlocks.class);
    public var message:Group;
    public var showMessage:Boolean;
    public var DEFAULT_MESSAGE="SmartBlocks Simulator\n\nClick on reset to begin";
    public var messageText:String=DEFAULT_MESSAGE;

    

    public function deleteBlock(b:Block):Void{
        simulation.deleteBlock(b);
    }

    public function insertBlock(b:Block):Void{
        simulation.insertBlock(b);
    }

    public function createObject(objectParams:Map){        
        insert VisualObject{
            mo: ObjectFactory.getInstance().createMovingObject(EnumShapes.CIRCLE,objectParams);
        } into objects;
    }
    
    postinit{
        showMessage=true;
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
        message=Group {
                content: [
                    ImageView {
                        image: bind Image {
                            url: "{__DIR__}images/SMARTBLOCKS.PNG"
                        }
                        fitWidth: bind owner.width;
                        fitHeight: bind owner.height;
                        translateX: 5;
                        translateY: 5;
                        visible: bind showMessage
                    }
                    Text {                        
                        translateX: 50
                        translateY: 200
                        font: Font { size: 40 }
                        content: "{messageText}"
                        visible: bind showMessage
                    }
                ]

            }
        
    }

     function reset(){
        showMessage=false;
        delete boundBlocks;
        delete blocks;
        delete objects;
        var i:Integer;
        var j:Integer;
        var numX:Float=owner.getGuiParam(EnumParamsGUI.MATRIX_X);
        var numY:Float=owner.getGuiParam(EnumParamsGUI.MATRIX_Y);
        var w:Float=owner.getGuiParam(EnumParamsGUI.SURF_DIMENSION_X)/(numX+2);
        var h:Float=owner.getGuiParam(EnumParamsGUI.SURF_DIMENSION_Y)/(numY+2);

        /////////////////////Bounding   Blocks!!!


        insert [  // Insert 4 corner bounding blocks
            VisualBlock{
                    block:BlockFactory.getInstance().createBoundingBlock(0,0,w,h,EnumDirections.ALL);
                    images: bind images
                    owner: bind owner
                    canvas: bind this
             }
             VisualBlock{
                    block:BlockFactory.getInstance().createBoundingBlock(w*(numX+1),0,w,h,EnumDirections.ALL);
                    images: bind images
                    owner: bind owner
                    canvas: bind this
             }
             VisualBlock{
                    block:BlockFactory.getInstance().createBoundingBlock(0,h*(numY+1),w,h,EnumDirections.ALL);
                    images: bind images
                    owner: bind owner
                    canvas: bind this
             }
             VisualBlock{
                    block:BlockFactory.getInstance().createBoundingBlock(w*(numX+1),h*(numY+1),w,h,EnumDirections.ALL);
                    images: bind images
                    owner: bind owner
                    canvas: bind this
             }
           ]
         into boundBlocks;

         i=1;
         // Insert upper bounding blocks
         while (i <= numX) {
                insert [
                    VisualBlock{
                        block:BlockFactory.getInstance().createBoundingBlock(i*w,0,w,h,EnumDirections.DOWN)
                        images: bind images
                        owner: bind owner
                        canvas: bind this
                    }
                    VisualBlock{
                        block:BlockFactory.getInstance().createBoundingBlock(i*w,(numY+1)*h,w,h,EnumDirections.UP)
                        images: bind images
                        owner: bind owner
                        canvas: bind this
                    }
                ]
                into boundBlocks;
                i++;
         }
         i=1;
         while (i <= numY) {
                insert [
                    VisualBlock{
                        block:BlockFactory.getInstance().createBoundingBlock(0,i*h,w,h,EnumDirections.RIGHT)
                        images: bind images
                        owner: bind owner
                        canvas: bind this
                    }
                    VisualBlock{
                        block:BlockFactory.getInstance().createBoundingBlock(w*(numX+1),i*h,w,h,EnumDirections.LEFT)
                        images: bind images
                        owner: bind owner
                        canvas: bind this
                    }
                ]
                into boundBlocks;
                i++
         }

        /////////////////////
        i=1;
        while (i <= numX) {
            j=1;
            while (j <= numY) {
                System.out.println("Insert block {i},{j} in {i*w},{j*h} width: {w} height: {h}");

                insert VisualBlock{
                    block:BlockFactory.getInstance().createBlock(EnumBlocks.FREE,i*w,j*h,w,h,owner.blockParams)
                    images: bind images
                    owner: bind owner
                    canvas: bind this
                }
                into blocks;
                j++
            }
            i++
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
                    }catch(ste:SimulationTerminated){
                         messageText="{ste.getMessage()} \n\n {DEFAULT_MESSAGE}";
                         print(messageText);
                         stop();
                    }
                }
            }
        };
    }

    function start(){
        var b:Block;
        simulation=SimulationFactory.getInstance().createSimulation();
        for (vblock in blocks){
            b=vblock.block;
            if(b.getType()!=EnumBlocks.FREE){
                simulation.insertBlock(b);
            }
        }
        for (vblock in boundBlocks){
            b=vblock.block;
                simulation.insertBlock(b);

        }
        for (vmo in objects){
            simulation.insertMovingObject(vmo.mo);
        }        
        timeline.playFromStart();
   }

    function stop() {
        timeline.stop();
        showMessage=true;
    }

    public var bottomButtonBox:HBox = HBox {
        translateX: bind (width - bottomButtonBox.layoutBounds.width)/2
        translateY: bind  5 + height - TOOLBAR_WIDTH
        spacing: 3
        content: [
            Group {
                content: [
                    Rectangle {
                        width: 80
                        height: 30
                        fill: Color.web("#CCCCCC")
                        stroke: Color.web("#BBBBBB")
                    }
                    Text {
                        translateX: 8
                        translateY: 20
                        content: "New Object"
                    }
                ]
                onMouseClicked:function(e) {                    
                    (stage as SimuStage).switchScenes(2);
                }
            }
            Group {
                content: [
                    Rectangle {
                        width: 80
                        height: 30
                        fill: Color.web("#CCCCCC")
                        stroke: Color.web("#BBBBBB")
                    }
                    Text {
                        translateX: 8
                        translateY: 20
                        content: "Options"
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
                        content: bind if (timeline.paused or not timeline.running) then " Play" else "Pause"
                    }
                ]
                onMouseClicked: function(e) {
                    if (timeline.running) {
                        if (timeline.paused) 
                                timeline.play() else timeline.pause();
                    }else{
                        start();
                    }

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
                        content: " Stop"
                    }
                ]
                onMouseClicked:function(e) {
                    stop();
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
                        content: "Reset"
                    }
                ]
                onMouseClicked:function(e) {
                    reset();
                }
            }
        ]
    };
}