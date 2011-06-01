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
import smartblocks.EnumParamsGUI;

/**
 * @author david
 */

public class VisualObject extends CustomNode {

    public var mo : MovingObject ;
    override var children= {
       Circle {
           centerX: bind mo.getX()*EnumParamsGUI.PX_PER_METER.getDefValue();
           centerY: bind mo.getY()*EnumParamsGUI.PX_PER_METER.getDefValue();
           radius: 10
           fill: Color.DARKBLUE
           onMouseDragged: function(event:MouseEvent) {
               mo.translate(event.dragX/EnumParamsGUI.PX_PER_METER.getDefValue(),
               event.dragY/EnumParamsGUI.PX_PER_METER.getDefValue());
           }
       }
    };
    override var blocksMouse=true;
}
