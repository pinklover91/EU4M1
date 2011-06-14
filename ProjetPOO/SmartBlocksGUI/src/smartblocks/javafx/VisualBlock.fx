/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.javafx;
import javafx.scene.CustomNode;
import javafx.scene.Node;
import smartblocks.block.Block;
import javafx.scene.input.MouseButton;
import smartblocks.block.EnumBlocks;
import javafx.scene.image.ImageView;
import javafx.util.Math;
import smartblocks.block.BlockFactory;
import java.util.Map;
import javafx.scene.image.Image;
import smartblocks.shapes.Shape;
import java.lang.System;

/**
 * GUI wrapper of a simulation block
 * @author David FUENMAYOR
 */

public class VisualBlock extends CustomNode{
    public var block : Block;
    var blockTypes: EnumBlocks[]=EnumBlocks.values();
    var i:Integer;
    public var images:Map;
    public var owner:SimuStage;
    public var canvas:SimuCanvas;
    var pix:Float;

    override function create(): Node {
        pix=EnumParamsGUI.PX_PER_METER.getDefValue();
       return       
          ImageView {
                image: bind images.get(block.getType()) as Image;
                fitWidth: bind block.getShape().getWidth()*pix;
                fitHeight: bind block.getShape().getHeight()*pix;
                translateX: bind block.getShape().getX()*pix;
                translateY: bind block.getShape().getY()*pix;
                rotate: bind if(block.getType()==EnumBlocks.ACCELERATOR) then
                        Math.toDegrees(Math.atan2(block.getForce().y,
                        block.getForce().x)) else 0.0;
                visible: true;                

                onMouseClicked: function(e) {
                    System.out.println("click!");
                    if(e.button==MouseButton.PRIMARY and e.clickCount==1){
                        if(i<blockTypes.size()-2)i++
                        else i=0;
                    }
                    if(e.button==MouseButton.SECONDARY and e.clickCount==1){
                        if(i>0) i-- else i=blockTypes.size()-2;
                    }
                    changeType();
                }
            }
    }
    public function changeType(): Void {
       var shape:Shape=block.getShape();
       canvas.deleteBlock(block);
       block=BlockFactory.getInstance().createBlock(
                    blockTypes.get(i),shape.getX(),shape.getY(),
                    shape.getWidth(),shape.getHeight(),owner.blockParams);

        canvas.insertBlock(block);
    }
}
