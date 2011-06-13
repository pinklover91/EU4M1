/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks;
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

/**
 * @author David FUENMAYOR
 */

public class VisualBlock extends CustomNode{
    public var block : Block;
    var blockTypes: EnumBlocks[]=EnumBlocks.values();
    var i:Integer;
    public var images:Map;
    public var owner:SimuStage;
    public var canvas:SimuCanvas;

    override function create(): Node {
       return       
          ImageView {
                image: bind images.get(block.getType()) as Image;
                fitWidth: bind block.getShape().getWidth()*EnumParamsGUI.PX_PER_METER.getDefValue();
                fitHeight: bind block.getShape().getHeight()*EnumParamsGUI.PX_PER_METER.getDefValue();
                translateX: bind block.getShape().getX()*EnumParamsGUI.PX_PER_METER.getDefValue();
                translateY: bind block.getShape().getY()*EnumParamsGUI.PX_PER_METER.getDefValue();
                rotate: bind if(block.getType()==EnumBlocks.ACCELERATOR) then Math.toDegrees(Math.atan2(block.getForce().y,
                    block.getForce().x)) else 0.0;
                visible: true;                

                onMouseClicked: function(e) {
                    if(e.button==MouseButton.PRIMARY and e.clickCount==1){
                        if(i<blockTypes.size()-1)i++;
                    }
                    if(e.button==MouseButton.SECONDARY and e.clickCount==1){
                        if(i>0) i--;
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
