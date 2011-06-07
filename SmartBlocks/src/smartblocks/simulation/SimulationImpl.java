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
import smartblocks.utilities.CollisionOcurred;
import smartblocks.utilities.EnumDirections;
import smartblocks.utilities.Vector2D;

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
        Block b=BlockFactory.getInstance().createBlock(EnumBlocks.TARGET, 0f,0f,0f,0f, null); //TODO
        blocks.add(b);
        return b;
    }

    @Override
    public void nextStep(float dt) throws SimulationTerminated{
       Vector2D force=new Vector2D();
       float torque=0f;
       int i = 0;
        while( i < objects.size()) {
           int j=i+1;
           MovingObject o1=objects.get(i);
           try{
               while( j < objects.size()) {
                    MovingObject o2=objects.get(j);
                    if (o2.operate(o1,dt)){
                        force.add(o2.getLastForce());
                        torque+=o2.getLastTorque();
                    }
                    j++;
               }
               j = 0;
               while( j < blocks.size()) {
                    Block b=blocks.get(j);
                    if(b.operate(o1,dt)){
                        force.add(b.getLastForce());
                        torque+=b.getLastTorque();
                    }
                    j++;
               }
               i++;
               o1.applyForce(force.x,force.y, dt);
               o1.applyTorque(torque, dt);
            }
           catch(CollisionOcurred c){
               o1.bounce(c.getDirection());
           }
           o1.updatePosition(dt);
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
