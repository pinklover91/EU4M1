/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.javafx;
import javafx.scene.CustomNode;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import smartblocks.object.MovingObject;
import javafx.scene.Node;
import smartblocks.shapes.Shape;
import smartblocks.shapes.EnumShapes;
import javafx.scene.input.MouseEvent;
import javafx.scene.shape.Polygon;
import smartblocks.utilities.SmartBlockUtilities;

/**
 * GUI wrapper of a simulation moving object
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
    var pix:Float=EnumParamsGUI.PX_PER_METER.getDefValue();


    public function update(){
        shape=mo.getShape();
        
        if(mo.getType()==EnumShapes.PUNCTUAL or mo.getType()==EnumShapes.CIRCLE){
            cX=shape.getCentroid(true).x*pix;
            cY=shape.getCentroid(true).y*pix;
            radius=(shape as smartblocks.shapes.Circle).getRadius()*pix;
       }else{
            vertices= SmartBlockUtilities.asArray(shape.getVertices(true));
            for(v in vertices){
                v*pix;
            }

       }
        toFront();
    }
     public function mouseDragged(event:MouseEvent) {
       //System.out.println("Mouse on object event: x:{event.sceneX} y:{event.sceneY} dragX: {event.dragX} dragY: {event.dragY}");
       mo.getShape().setPosition(event.sceneX/pix,event.sceneY/pix);
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
