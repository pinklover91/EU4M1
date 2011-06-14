/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.simulation;

/**
 * A factory of Simulations implemented as a singleton
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

   /**
    * Returns a reference to the SimulationFactory
    * @return
    */
   public static SimulationFactory getInstance(){
       return SingletonHolder.INSTANCE;
   }

   /**
    * Creates a new Simulation
    * @return new Simulation
    */
   public Simulation createSimulation(){
        return new SimulationImpl();
   }
}
