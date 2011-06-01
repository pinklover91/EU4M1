/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package smartblocks;
import javafx.scene.control.TextBox;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import smartblocks.java.EnumBlockParams;
import javafx.scene.text.Text;
import javafx.scene.Group;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.scene.Scene;
import smartblocks.SimuStage;

/**
 * @author david
 */

public class BlockDialog extends Scene {   

    function setBlockParam(e:EnumBlockParams, value:String){
        (stage as SimuStage).setBlockParam(e,Double.valueOf(value));
    }
    function setBlockParam(e:EnumBlockParams, value:Double){
        (stage as SimuStage).setBlockParam(e,value);
    }  

    function setGUIParam(e:EnumParamsGUI, value:String){
        (stage as SimuStage).setGUIParam(e,Double.valueOf(value));
    }
    function setGUIParam(e:EnumParamsGUI, value:Double){
        (stage as SimuStage).setGUIParam(e,value);
    } 
     
        
       public var inGroup:Group =Group{
            content: [
                for (e in EnumBlockParams.values()){                                       
                    VBox {
                        translateX: 10
                        translateY: 40*e.getIndex();
                        spacing: 10
                        content: [
                            HBox {
                                translateX: 10
                                translateY: 0
                                spacing: 10
                                content: [
                                    Text {
                                        translateX: 8
                                        translateY: 20
                                        content: e.name()
                                    }
                                    TextBox{
                                        var tx:String= "{e.getDefValue()}";
                                        text: bind tx with inverse
                                        columns: 10
                                        selectOnFocus: true
                                        action: function() {                                            
                                            setBlockParam(e,tx)
                                        }
                                    }
                                    Text {
                                        translateX: 8
                                        translateY: 20
                                        content: e.getDescription()
                                    }
                                ]
                             }
                        ]
                    }
                }
                for (e in EnumParamsGUI.values()){
                    VBox {
                        translateX: 10
                        translateY: 40*e.getIndex()+40*EnumBlockParams.values().length;
                        spacing: 10
                        content: [
                            HBox {
                                translateX: 10
                                translateY: 0
                                spacing: 10
                                content: [
                                    Text {
                                        translateX: 8
                                        translateY: 20
                                        content: e.name()
                                    }
                                    TextBox{
                                        var tx:String= "{e.getDefValue()}";
                                        text: bind tx with inverse
                                        columns: 10
                                        selectOnFocus: true
                                        action: function() {
                                            setGUIParam(e,tx)
                                        }
                                    }
                                    Text {
                                        translateX: 8
                                        translateY: 20
                                        content: e.getDescription()
                                    }
                                ]
                             }
                        ]
                    }
                }
                Group {
                    content: [
                        Rectangle {
                            width: 65
                            height: 30
                            fill: Color.web("#CCCCCC")
                            stroke: Color.web("#BBBBBB")
                        }
                        Text {
                            translateX: 8
                            translateY: 20
                            content: "Close"
                        }
                    ]
                    onMouseClicked:function(e) {                   
                        (stage as SimuStage).switchScenes(1);
                    }
                }
            ];
   
    }
}