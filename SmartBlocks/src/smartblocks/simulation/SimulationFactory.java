/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.simulation;

/**
 *
 * @author David FUENMAYOR
 */
public class SimulationFactory {   

    private SimulationFactory() {
    }

   /**
    * SingletonHolder is loaded on the first execution of Singleton.getInstance()
    * or the first access to SingletonHolder.INSTANCE, not before.
    */
   private static class SingletonHolder {
     public static final SimulationFactory INSTANCE = new SimulationFactory();
   }

   public static SimulationFactory getInstance(){
       return SingletonHolder.INSTANCE;
   }

   public Simulation createSimulation(){
        return new SimulationImpl();
   }
}
