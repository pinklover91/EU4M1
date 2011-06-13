/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.simulation;

import smartblocks.object.MovingObject;
import java.util.ArrayList;
import java.util.List;
import smartblocks.block.Block;
import smartblocks.block.BlockFactory;
import smartblocks.block.EnumBlocks;
import smartblocks.object.ObjectFactory;
import smartblocks.shapes.EnumShapes;
import smartblocks.utilities.Collider;
import smartblocks.utilities.CollisionOcurred;
import smartblocks.utilities.SmartBlockUtilities;
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
    /**
     * TODO: Creates a moving object and inserts it, only works with punctual type
     */
    public MovingObject createMovingObject() {
        MovingObject mo=ObjectFactory.getInstance().createMovingObject(EnumShapes.PUNCTUAL, null);
        objects.add(mo);
        return mo;
    }

    @Override
    /**
     * TODO: Creates a block and inserts it, do not use yet
     */
    public Block createBlock() {
        Block b=BlockFactory.getInstance().createBlock(EnumBlocks.TARGET, 0f,0f,0f,0f, null); //TODO
        blocks.add(b);
        return b;
    }

    @Override
    public void nextStep(float dt) throws SimulationTerminated{       
       int i = 0;
       Collider collider;
       Vector2D[] vertices;
        while( i < objects.size()) {
           int j=i+1;
           MovingObject o1=objects.get(i);
           o1.resetForces();
           try{
               while( j < objects.size()) {
                    MovingObject o2=objects.get(j); 
                    //SmartBlockUtilities.getCollider(o2.getType(), o1.getType())
                    //collider.collide(o2.computeForces(collider.getCollidingVertices(o2, o1)));
                    j++;
               }
               j = 0;
               while( j < blocks.size()) {
                    Block b=blocks.get(j);
                    collider=SmartBlockUtilities.getCollider(b.getType(), o1.getType());
                    vertices=collider.getCollidingVertices(b, o1);
                    collider.collide(o1,b.computeForces(o1,vertices),vertices);
                    j++;
               }
               i++;
               o1.applyForces(dt);
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
