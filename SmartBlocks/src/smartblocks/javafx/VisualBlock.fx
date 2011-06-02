/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package smartblocks.javafx;
import javafx.scene.CustomNode;
import javafx.scene.Group;
import javafx.scene.Node;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.scene.text.Text;
import smartblocks.block.Block;
import javafx.scene.input.MouseButton;
import smartblocks.block.EnumBlocks;
import smartblocks.utilities.SmartBlockUtilities;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.util.Math;
import smartblocks.block.EnumBlockParams;
import smartblocks.block.BlockFactory;

/**
 * @author david
 */

public class VisualBlock extends CustomNode{
    public var block : Block;
    var blockTypes: EnumBlocks[]=EnumBlocks.values();
    var i:Integer;
    public var image:Image=Image {
          url: "{__DIR__}images/rightArrow.PNG"
        }

    override function create(): Node {
       return
       Group {
           translateX: bind block.getX()*EnumParamsGUI.PX_PER_METER.getDefValue();
           translateY: bind block.getY()*EnumParamsGUI.PX_PER_METER.getDefValue();
            content: [
                /*Rectangle{
                       x: 0
                       y: 0
                       height: bind block.getHeight()*EnumParamsGUI.PX_PER_METER.getDefValue();
                       width: bind block.getWidth()*EnumParamsGUI.PX_PER_METER.getDefValue();
                       fill: Color.BLUEVIOLET
                },
                Text {
                    translateX: bind block.getWidth()*EnumParamsGUI.PX_PER_METER.getDefValue()/2
                    translateY: bind block.getHeight()*EnumParamsGUI.PX_PER_METER.getDefValue()/2
                    content: bind block.getType().getSymbol()
                },*/
                ImageView {
                    image: bind image                    
                    fitWidth: bind block.getWidth()*EnumParamsGUI.PX_PER_METER.getDefValue()/2;
                    fitHeight: bind block.getHeight()*EnumParamsGUI.PX_PER_METER.getDefValue()/2;
                    rotate: bind Math.toDegrees(Math.atan2(block.getParam(EnumBlockParams.CONSTANT_FORCE_X),
                        block.getParam(EnumBlockParams.CONSTANT_FORCE_Y)));
                    visible: true;
                    /*clip: Rectangle{
                       x: bind block.getX()*EnumParamsGUI.PX_PER_METER.getDefValue();
                       y: bind block.getY()*EnumParamsGUI.PX_PER_METER.getDefValue();
                       height: bind block.getHeight()*EnumParamsGUI.PX_PER_METER.getDefValue();
                       width: bind block.getWidth()*EnumParamsGUI.PX_PER_METER.getDefValue();                       
                    }*/

                }
            ]
            onMouseClicked: function(e) {
                if(e.button==MouseButton.PRIMARY and e.clickCount==1){
                    if(i<blockTypes.size()-1)i++;
                } 
                if(e.button==MouseButton.SECONDARY and e.clickCount>1){
                    if(i>0) i--;
                }
                changeType();
            }
        }
    }
    public function changeType(): Void {
       block=BlockFactory.getInstance().createBlock(blockTypes.get(i),block.getOffset(),block.getSize(),(scene.stage as SimuStage).blockParams);
    }
}
