/*
 * Ecole Nationale Superieure de Mecanique et des Microtechniques ENSMM
 * Besancon - France
 * 2011
 */

package smartblocks.block;

import smartblocks.utilities.Vector2D;
import java.util.Map;
import smartblocks.object.MovingObject;
import smartblocks.utilities.EnumDirections;


/**
 * Block with a constant force all along its surface
 * @author David FUENMAYOR
 */
strictfp class AcceleratorBlock extends BlockImpl {

    /**
     * Constant force exerted by this block
     */
    protected Vector2D force;

    protected EnumDirections direction;

    AcceleratorBlock(Vector2D offset, Vector2D size, Map<EnumBlockParams,Object> params,EnumDirections direction){
        super(EnumBlocks.ACCELERATOR,offset,size,params);
        this.direction=direction;
        float fx=(Float)getParam(EnumBlockParams.CONSTANT_FORCE_X);
        float fy=(Float)getParam(EnumBlockParams.CONSTANT_FORCE_Y);
        float afx=Math.abs(fx);
        float afy=Math.abs(fy);
        switch(direction){
            case UP:
                force.x=0;
                force.y=-afy;
                break;
            case LEFT:
                force.x=-afx;
                force.y=0;
                break;
            case DOWN:
                force.x=0;
                force.y=afy;
                break;
            case RIGHT:
                force.x=afx;
                force.y=0;
                break;
            default:
                force.x=fx;
                force.y=fy;
                break;
        }
        
    }
    
    @Override
    public Vector2D[] computeForces(MovingObject mo, Vector2D[] contacts){
        Vector2D[] forces= new Vector2D[contacts.length];
        int n=contacts.length;        
        for(int i=0;i<n;i++){
            forces[i]=new Vector2D(force.x/n,force.y/n);
        }
        return forces;
    }

    @Override
    public Vector2D getForce(){
        return force;
    }
}