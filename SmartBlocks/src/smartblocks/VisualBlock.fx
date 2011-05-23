/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package smartblocks;
import javafx.scene.CustomNode;
import javafx.scene.Group;
import javafx.scene.Node;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.scene.text.Text;
import smartblocks.java.Block;
import smartblocks.java.MovingObject;
import javafx.scene.input.MouseButton;
import java.lang.System;

/**
 * @author david
 */

public class VisualBlock extends CustomNode{
    public var block : Block;
    override function create(): Node {
       return
       Group {
           translateX: bind block.getX()
           translateY: bind block.getY()
            content: [
                Rectangle{
                       x: 0
                       y: 0
                       height: bind block.getHeight();
                       width: bind block.getWidth();
                       fill: Color.CHARTREUSE
                },
                Text {
                    translateX: bind block.getWidth()/2
                    translateY: bind block.getHeight()/2
                    content: bind block.getType().getSymbol()
                }
            ]
            onMouseClicked: function(e) {
                if(e.button==MouseButton.SECONDARY and e.clickCount>1){
                    block=null;
                    (scene as SimuCanvas).deleteBlock(this);
                }                
            }
        }
    }
    public function update(mo,dt:Double): Void {
       System.out.println("Operate in block x: {block.getX()}  y: {block.getY()}");
       block.operate(mo as MovingObject,dt);
    }
}
