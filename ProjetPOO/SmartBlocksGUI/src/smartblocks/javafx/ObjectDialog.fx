/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.javafx;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.TextBox;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.scene.text.Text;
import smartblocks.object.EnumObjectParams;

/**
 * Scene used to set the parameters of a new MovingObject
 * @author David FUENMAYOR
 */

public class ObjectDialog extends Scene {       

    function setObjectParam(e:EnumObjectParams, value:String){
        (stage as SimuStage).setObjectParam(e,Float.valueOf(value));
    }
    function setObjectParam(e:EnumObjectParams, value:Float){
        (stage as SimuStage).setObjectParam(e,value);
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
                        width: 80
                        height: 30
                        fill: Color.web("#CCCCCC")
                        stroke: Color.web("#BBBBBB")
                    }
                    Text {
                        translateX: 8
                        translateY: 20
                        content: "Create Object"
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
