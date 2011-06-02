/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.simulation;

import smartblocks.object.EnumObjects;
import smartblocks.object.MovingObject;
import java.util.ArrayList;
import java.util.List;
import smartblocks.block.Block;
import smartblocks.block.BlockFactory;
import smartblocks.block.EnumBlocks;
import smartblocks.object.ObjectFactory;

/**
 * Default implementation of the Simulation interface
 * @author David FUENMAYOR
 */
public class SimulationImpl implements Simulation{

    List<Block> blocks;
    List<MovingObject> objects;

    SimulationImpl(){
        blocks=new ArrayList<Block>();
        objects=new ArrayList<MovingObject>();
    }

    @Override
    public void insertBlock(Block b) {
        blocks.add(b);
    }

    @Override
    public void insertMovingObject(MovingObject mo) {
        objects.add(mo);
    }

    @Override
    public MovingObject createMovingObject() {
        MovingObject mo=ObjectFactory.getInstance().createMovingObject(EnumObjects.PUNCTUAL, null);
        objects.add(mo);
        return mo;
    }

    @Override
    /**
     * TODO: Do not use
     */
    public Block createBlock() {
        Block b=BlockFactory.getInstance().createBlock(EnumBlocks.TARGET, 0,0,0,0, null); //TODO
        blocks.add(b);
        return b;
    }

    @Override
    public void nextStep(double dt) throws SimulationTerminatedException{
       int i = objects.size()-1;
        while( i >= 0 ) {
           objects.get(i).updatePosition(dt);           
           int j = blocks.size() - 1;
            while( j >= 0 ) {
                blocks.get(j).operate(objects.get(i),dt);
                j--;
             }
           i--;
        }    
    }

    @Override
    public List<Block> getBlocks() {
        return blocks;
    }

    @Override
    public List<MovingObject> getMovingObjects() {
        return objects;
    }

    @Override
    public boolean deleteBlock(Block block) {
        return blocks.remove(block);
    }

    @Override
    public boolean deleteMovingObject(MovingObject mo) {
        return objects.remove(mo);
    }
}
