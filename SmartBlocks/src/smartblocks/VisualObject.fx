/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks;
import javafx.scene.CustomNode;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import smartblocks.object.MovingObject;
import javafx.scene.input.MouseEvent;
import java.lang.System;
import javafx.scene.Node;

/**
 * @author David FUENMAYOR
 */

public class VisualObject extends CustomNode {

    public var mo : MovingObject ;
    public var cX:Float;
    public var cY:Float;

    postinit{
        update();
    }

    public function update(){
        cX=mo.getX()*EnumParamsGUI.PX_PER_METER.getDefValue();
        cY=mo.getY()*EnumParamsGUI.PX_PER_METER.getDefValue();
        toFront();
    }


    override function create(): Node {
       return
       Circle {
           centerX: bind cX
           centerY: bind cY
           radius: 20
           fill: Color.DARKBLUE

           onMouseDragged: function(event:MouseEvent) {
               System.out.println("Mouse on object event: x:{event.sceneX} y:{event.sceneY} dragX: {event.dragX} dragY: {event.dragY}");
               mo.setPosition(event.sceneX/EnumParamsGUI.PX_PER_METER.getDefValue(),
               event.sceneY/EnumParamsGUI.PX_PER_METER.getDefValue());
               update();
           }
       };
    };
    override var blocksMouse=true;
}
