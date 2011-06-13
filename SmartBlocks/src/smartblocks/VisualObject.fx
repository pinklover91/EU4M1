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
import javafx.scene.Node;
import smartblocks.shapes.Shape;
import smartblocks.shapes.EnumShapes;
import javafx.scene.input.MouseEvent;
import java.lang.System;
import javafx.scene.shape.Polygon;
import smartblocks.utilities.SmartBlockUtilities;

/**
 * @author David FUENMAYOR
 */

public class VisualObject extends CustomNode {

    public var mo : MovingObject ;
    public var cX:Float;
    public var cY:Float;
    public var radius:Float;
    public var vertices:Float[];
    public var shape:Shape;    
    public var node:Node;


    public function update(){
        shape=mo.getShape();
        if(mo.getType()==EnumShapes.PUNCTUAL or mo.getType()==EnumShapes.CIRCLE){
            cX=shape.getCentroid(true).x*EnumParamsGUI.PX_PER_METER.getDefValue();
            cY=shape.getCentroid(true).y*EnumParamsGUI.PX_PER_METER.getDefValue();
            radius=(shape as Circle).radius;
       }else{
            vertices= SmartBlockUtilities.asArray(shape.getVertices(true));

       }
        toFront();
    }
     public function mouseDragged(event:MouseEvent) {
       System.out.println("Mouse on object event: x:{event.sceneX} y:{event.sceneY} dragX: {event.dragX} dragY: {event.dragY}");
       mo.getShape().setPosition(event.sceneX/EnumParamsGUI.PX_PER_METER.getDefValue(),
            event.sceneY/EnumParamsGUI.PX_PER_METER.getDefValue());
       mo.setMomentum(0,0);
       update();
   }

    postinit{
        update();
    }

    override function create(): Node {
       return if (mo.getType()==EnumShapes.PUNCTUAL or mo.getType()==EnumShapes.CIRCLE)
           then Circle {
               centerX: bind cX
               centerY: bind cY
               radius: bind radius
               fill: Color.DARKBLUE
               onMouseDragged: mouseDragged
           }
       else Polygon {
                points: bind vertices;
                fill: Color.DARKBLUE
                onMouseDragged: mouseDragged
            }
    }
    override var blocksMouse=true;
}
