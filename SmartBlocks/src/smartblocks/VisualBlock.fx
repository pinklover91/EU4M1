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
import javafx.scene.input.MouseButton;
import smartblocks.java.EnumBlocks;
import smartblocks.java.SmartBlockUtilities;

/**
 * @author david
 */

public class VisualBlock extends CustomNode{
    public var block : Block;    
    public var blockTypes: EnumBlocks[]=EnumBlocks.values();
    public var i:Integer;

    override function create(): Node {
       return
       Group {
           translateX: bind block.getX()*EnumParamsGUI.PX_PER_METER.getDefValue();
           translateY: bind block.getY()*EnumParamsGUI.PX_PER_METER.getDefValue();
            content: [
                Rectangle{
                       x: 0
                       y: 0
                       height: bind block.getHeight()*EnumParamsGUI.PX_PER_METER.getDefValue();;
                       width: bind block.getWidth()*EnumParamsGUI.PX_PER_METER.getDefValue();;
                       fill: Color.BLUEVIOLET
                },
                Text {
                    translateX: bind block.getWidth()*EnumParamsGUI.PX_PER_METER.getDefValue()/2
                    translateY: bind block.getHeight()*EnumParamsGUI.PX_PER_METER.getDefValue()/2
                    content: bind block.getType().getSymbol()
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
       block=SmartBlockUtilities.createBlock(blockTypes.get(i),block.getOffset(),block.getSize(),(scene.stage as SimuStage).blockParams);
    }
}
