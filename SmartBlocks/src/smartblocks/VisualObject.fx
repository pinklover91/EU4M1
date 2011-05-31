/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package smartblocks;
import javafx.scene.CustomNode;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import smartblocks.java.MovingObject;
import javafx.scene.input.MouseEvent;

/**
 * @author david
 */

public class VisualObject extends CustomNode {

    public var mo : MovingObject ;
    override var children= {
       Circle {
           centerX: bind mo.getX()
           centerY: bind mo.getY()
           radius: 10
           fill: Color.DARKBLUE
           onMouseDragged: function(event:MouseEvent) {
               mo.setPosition(event.sceneX, event.sceneY);
           }
       }
    };
    override var blocksMouse=true;
}
