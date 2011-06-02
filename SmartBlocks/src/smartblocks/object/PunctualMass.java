/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.object;

import java.util.Map;

/**
 * A punctual mass moving over the smart surfaces
 * @author David FUENMAYOR
 */
class PunctualMass extends ObjectImpl{
    
    /**
     * Default constructor
     */
    PunctualMass(){
        super(EnumObjects.PUNCTUAL);
    }

    PunctualMass(Map<EnumObjectParams,Double> params){
        super(EnumObjects.PUNCTUAL,params);
    }

}
