/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.object;

import java.util.Map;
import smartblocks.shapes.EnumShapes;

/**
 * A punctual mass moving over the smart surfaces
 * @author David FUENMAYOR
 */
class PunctualMass extends ObjectImpl{
    
    /**
     * Default constructor
     */
    PunctualMass(){
        super(EnumShapes.CIRCLE);
    }

    PunctualMass(Map<EnumObjectParams,Object> params){
        super(EnumShapes.CIRCLE,params);
    }

}
