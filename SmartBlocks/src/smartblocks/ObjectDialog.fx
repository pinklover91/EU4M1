/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package smartblocks;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.TextBox;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.scene.text.Text;
import smartblocks.java.EnumObjectParams;
import smartblocks.SimuStage;
import java.lang.System;

/**
 * @author david
 */

public class ObjectDialog extends Scene {       

    function setObjectParam(e:EnumObjectParams, value:String){
        (stage as SimuStage).setObjectParam(e,Double.valueOf(value));
    }
    function setObjectParam(e:EnumObjectParams, value:Double){
        (stage as SimuStage).setObjectParam(e,value);
    }

    init{
        for (e in EnumObjectParams.values())
                    setObjectParam(e,e.getDefValue());
    }

       public var inGroup:Group =Group{
            content: [
                for (e in EnumObjectParams.values()){  
                    VBox {
                        translateX: 8
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
                                        columns: 6
                                        selectOnFocus: true
                                        action: function() {
                                            setObjectParam(e,tx)
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
                            content: "Create New Object"
                        }
                    ]
                    onMouseClicked:function(e) {
                        (stage as SimuStage).createObject();
                        (stage as SimuStage).switchScenes(1);
                    }
                }
            ];

    }
}
