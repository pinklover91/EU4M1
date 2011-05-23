/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package smartblocks;
import javafx.scene.CustomNode;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import smartblocks.java.MovingObject;

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
       }
    };
    public function update(dt:Double): Void {
       mo.updatePosition(dt);
    }
}
