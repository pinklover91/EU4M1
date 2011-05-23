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
/**
 * @author david
 */

public class SimuCanvas extends Scene {
    def TOOLBAR_WIDTH = 50;
    public var objects : VisualObject[];
    public var blocks : VisualBlock[];
    public var timeline : Timeline;

    public function deleteBlock(vb:VisualBlock):Void{
        delete vb from blocks;
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
                        width: 70
                        height: 30
                        fill: Color.web("#CCCCCC")
                        stroke: Color.web("#BBBBBB")
                    }
                    Text {
                        translateX: 8
                        translateY: 20
                        content: "New Block"
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

    function play(){
        timeline = Timeline {
        repeatCount: Timeline.INDEFINITE
        keyFrames :
            KeyFrame {
                time : 5ms
                canSkip : true
                action: function() {
                    update();
                }
            }
        };
        timeline.play();
   }


    function stop() {
        timeline.stop();
        timeline = null;
    }

    function update(): Void {
       var i = sizeof objects - 1;
        while( i >= 0 ) {
           objects[i.intValue()].update(timeline.keyFrames.get(0).time.toSeconds());
           i--;
           var j = sizeof blocks - 1;
            while( j >= 0 ) {
                blocks[j.intValue()].update(objects[i.intValue()].mo,timeline.keyFrames.get(0).time.toSeconds());
                j--;
             }
        }
    }
}