/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.object;

import java.util.Map;
import smartblocks.shapes.EnumShapes;

/**
 * A mass with a disc-like shape moving over the smart surfaces
 * @author David FUENMAYOR
 */
class DiscMass extends ObjectImpl{

    /**
     * Default constructor
     */
    DiscMass(){
        super(EnumShapes.CIRCLE);
    }

    DiscMass(Map<EnumObjectParams,Object> params){
        super(EnumShapes.CIRCLE,params);
    }

}
