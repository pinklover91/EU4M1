//---------------------------------------------------------------------------
//
// Copyright (c) 2005 FEMTO-ST / ENSMM / UFC / UTBM, Besan�on, France
//
// This file is part of EasyLink.
//
// EasyLink is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// EasyLink is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with EasyLink; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//
// See the included license: "license.txt"
//
//---------------------------------------------------------------------------
#ifndef EasyLink_h
#define EasyLink_h
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
/** \ingroup BasicClass
* String Size */
#define StringSize 255


/** \ingroup BasicClass
* String type */
typedef char String[StringSize+1];

/** \ingroup BasicClass
* Static string buffer for errors display */
static char ERROR_MSG_BUFFER[512];



#include <stdlib.h>
#include <stdio.h>

 #define SCILAB_XCOS_FILE

// block functions definition

#if defined(MATLAB_MEX_FILE)


#include "tools.h"
#include "rvector.h"
#include "ivector.h"
#include "pvector.h"
#include "rmatrix.h"
//---------------------------------------------------------------------------
// code for using easylink with Matlab (defines a wrapper on simulink interface)
//---------------------------------------------------------------------------
#include "simstruc.h"



#elif defined(SCILAB_XCOS_FILE)
//---------------------------------------------------------------------------
// code for using easylink with Scilab
//---------------------------------------------------------------------------


#include "scilab/scicos_block4.h"
#include "mex.h"
#include "scilab/api_scilab.h"


#define int_T int
#define real_T double
#define SimStruct scicos_block

#undef Abs                   // Avoids compilation problems among homonym macros


#include "tools.h"


#undef Max                     // Avoids compilation problems among homonym macros
#undef Min                     // Avoids compilation problems among homonym macros

#include "rvector.h"


#include "ivector.h"
#include "pvector.h"
#include "rmatrix.h"


// This avoids compilation problems among homonym macros
#undef REAL     // Defined in scilab/mex.h and later unadvertenly used in opencv2/core/core.hpp 
#undef COMPLEX  // Defined in mex.h
#undef getType  // Defined in stack-c.h
#undef getPrecision
#undef getNumberOfLines
#undef getNumberOfColumns
#undef isComplex
#undef getElementByAddress
#undef getDoubleDataAddress

static     void mdlInitializeSizes(SimStruct *S);
static  void mdlStart(SimStruct *S);
    
       static  void mdlOutputs(SimStruct *S, int_T tid);
        static void mdlTerminate(SimStruct *S);
/*
       static   void mdlSetInputPortWidth(SimStruct *S, int_T port,int_T proposedwidth);
       static void mdlCheckParameters(SimStruct *S);
        static    void mdlSetOutputPortWidth(SimStruct *S,int_T port,int_T proposedwidth);
        static        void mdlInitializeSampleTimes(SimStruct *S);
       
       static  void mdlInitializeConditions(SimStruct *S);
    
          
        inline mxArray* ssGetSFcnParam(SimStruct *S,int port);
        inline real_T** ssGetInputPortRealSignalPtrs(SimStruct *S,int_T port);
        inline real_T* ssGetOutputPortRealSignal(SimStruct *S,int_T port);
        inline real_T* ssGetRWork(SimStruct* S);
        inline int_T* ssGetIWork(SimStruct* S);
        inline void** ssGetPWork(SimStruct* S);
        inline int_T ssGetNumRWork(SimStruct* S);
        inline int_T ssGetNumIWork(SimStruct* S);
        inline int_T ssGetNumPWork(SimStruct* S);
        inline void ssSetNumRWork(SimStruct *S, int_T DimVR);
        inline void ssSetNumIWork(SimStruct *S, int_T DimVI);
        inline void ssSetNumPWork(SimStruct *S, int_T DimVP);
        inline bool ssSetNumInputPorts(SimStruct *S, int_T nInPorts);
        inline void ssSetInputPortWidth(SimStruct *S, int_T inPort, int_T width);
        inline bool ssSetNumOutputPorts(SimStruct *S, int_T nOutPorts);
        inline void ssSetOutputPortWidth(SimStruct *S, int_T outPort, int_T width);
        inline void ssSetNumSFcnParams(SimStruct *S, int_T numSFcnParams);
        inline void ssSetNumContStates(SimStruct *S, int_T numContStates);
        inline void ssSetNumDiscStates(SimStruct *S, int_T numDiscStates);
      
       */
        

        /**
         * Function's entry point needs to be declared as a C function using extern "C"
         * */

        extern "C"{
            void S_FUNCTION_NAME(SimStruct *S, int flag);
        }
       
        
        //---------------------------------------------------------------------------

        /// \ingroup InterfaceClass
        /// Define input characterictics
        inline void InputInit(SimStruct *S,int_T Nb,int_T *Dim,int_T *DFT);
        /// \ingroup InterfaceClass
        /// Define output characterictics
        inline void	OutputInit(SimStruct *S,int_T Nb,int_T *Dim);
        /// \ingroup InterfaceClass
        /// Define parameter characterictics
        inline void ParamInit(SimStruct *S,int_T Nb,int_T *Dim,int_T *Fix);
        /// \ingroup InterfaceClass
        /// Define work vector characterictics
        inline void WorkVectorInit(SimStruct *S,int_T DimVR,int_T DimVI,int_T DimVP);
        /// \ingroup InterfaceClass
        /// Define state vector characterictics
        inline void StateInit(SimStruct *S,int_T DimEC,int_T DimED);

        //---------------------------------------------------------------------------
        /// Encapsulation of inputs, outputs and parameters with one component

        /// \ingroup InterfaceClass
        /// Return the first value of an input port vector
        inline real_T InputValue(SimStruct *S,int_T port);
        /// \ingroup InterfaceClass
        /// Write the first value of an output port vector
        inline void WriteOutputValue(SimStruct *S,int_T port,real_T val);
        /// \ingroup InterfaceClass
        /// Return the first value of a parameter port 
        inline real_T ParamValue(SimStruct *S,int_T port);


        //---------------------------------------------------------------------------
        /// Encapsulation of parameters in the string (chain) type

        /// \ingroup InterfaceClass
        /// C receives the string (chain) contained in the parameter port
        inline void ParamString(SimStruct *S,int_T port,String &C);

        //---------------------------------------------------------------------------
        /// Encapsulation for input, output and parameter sizes 

        /// Return the input port vector size
        inline int_T InputWidth(SimStruct *S,int_T port);
        /// Return the output port vector size
        inline int_T OutputWidth(SimStruct *S,int_T port);
        /// Return the parameter port vector size 
        inline int_T ParamWidth(SimStruct *S,int_T port);
        //inline void mexErrMsgTxt(char * Error_MSG);

        
inline void mexErrMsgTxt(char * Error_MSG)
{
    FILE *f;
    f=fopen("truc.log","a");
	fprintf(f,Error_MSG);
    fclose(f);
	exit(1);        
}
 

struct _XCosWorkStruct {
    int_T RWorkWidth;
    int_T IWorkWidth;
    int_T PWorkWidth;
    real_T* RWorkPtrs;
    int_T* IWorkPtrs;
    void** PWorkPtrs;
};

typedef struct _XCosWorkStruct* XCosWorkStruct;


/// Aliases

#define InputRealPtrsType real_T**

#define ssGetOutputPortWidth(S,port) GetOutPortRows(S,(port)+1)
#define ssGetInputPortWidth(S,port) GetInPortRows(S,(port)+1)
#define ssGetSFcnParamsCount(S) GetNopar(S)  
#define ssGetErrorStatus(S) NULL
#define ssGetNumContStates(S) GetNstate(S)
#define ssGetContStates(S) GetState(S)
#define ssGetdX(S)  (S->xd)                           
#define ssGetNumDiscStates(S) GetNdstate(S)
#define ssGetDiscStates(S) GetDstate(S)
#define ssSetNumSampleTimes(S, n)                               // does nothing
#define ssSetInputPortDirectFeedThrough(S,inputPortIdx,dirFeed) // does nothing
#define ssSetSFcnParamNotTunable(S,index)                       // does nothing
#define ssSetNumSampleTimes(S, n)                               // does nothing
#define ssSetOffsetTime(S,st_index,value)                       // does nothing
#define ssSetErrorStatus(S,str)                                 // does nothing

inline mxArray* ssGetSFcnParam(SimStruct *S,int port){
    return (mxArray*)GetOparPtrs(S,(port)+1);   // Returns object parameters
}

inline InputRealPtrsType ssGetInputPortRealSignalPtrs(SimStruct *S,int_T port){
    if (port>=0&port<(S->nin)){
        return (InputRealPtrsType) ((S->inptr)+port); 
    }else return NULL;
}

inline real_T* ssGetOutputPortRealSignal(SimStruct *S,int_T port){
     if (port>=0&port<(S->nout)){
        // &GetRealInPortPtrs pointer to pointer?
        return (real_T*)(S->outptr[port]);  //&GetRealOutPortPtrs
    }else return NULL;    
}

inline real_T* ssGetRWork(SimStruct* S){
    XCosWorkStruct wstruct=*((XCosWorkStruct*)S->work);
    return wstruct->RWorkPtrs;
}

inline int_T* ssGetIWork(SimStruct* S){
    XCosWorkStruct wstruct=*((XCosWorkStruct*)S->work);
    return wstruct->IWorkPtrs;
}

//TODO: Set inline again
 void** ssGetPWork(SimStruct* S){
     XCosWorkStruct wstruct=*((XCosWorkStruct*)S->work);
    return wstruct->PWorkPtrs;   
}

inline int_T ssGetNumRWork(SimStruct* S){
    XCosWorkStruct wstruct=*((XCosWorkStruct*)S->work);
    return wstruct->RWorkWidth; 
}

inline int_T ssGetNumIWork(SimStruct* S){
    XCosWorkStruct wstruct=*((XCosWorkStruct*)S->work);
    return wstruct->IWorkWidth; 
}

inline int_T ssGetNumPWork(SimStruct* S){
    XCosWorkStruct wstruct=*((XCosWorkStruct*)S->work);
    return wstruct->PWorkWidth; 
}

/** 
 * Creates RWorkPtrs vector \n
 * If RWorkPtrs!=NULL deletes the current values stored as parameters
 */
void ssSetNumRWork(SimStruct *S, int_T DimVR){
    if(S->work==NULL||*((XCosWorkStruct*)(S->work))==NULL){
         S->work=(void**)calloc(1,sizeof(void*));
         XCosWorkStruct wstruct= *((XCosWorkStruct*)(S->work));
         wstruct= (XCosWorkStruct)calloc(1,sizeof(_XCosWorkStruct));
         wstruct->RWorkPtrs=(real_T*)calloc(DimVR,sizeof(real_T));
         wstruct->RWorkWidth=DimVR;         
    }else{
         XCosWorkStruct wstruct=*((XCosWorkStruct*)(S->work));
         free(wstruct->RWorkPtrs);         
         wstruct->RWorkPtrs=(real_T*)calloc(DimVR,sizeof(real_T));
         wstruct->RWorkWidth=DimVR;
    }
}
/**
 * Creates IWorkPtrs vector \n
 * If IWorkPtrs!=NULL deletes the current values stored as parameters
 * 
 */
void ssSetNumIWork(SimStruct *S, int_T DimVI){
    if(S->work==NULL||*((XCosWorkStruct*)(S->work))==NULL){
         S->work=(void**)calloc(1,sizeof(void*));
         XCosWorkStruct wstruct= *((XCosWorkStruct*)(S->work));
         wstruct= (XCosWorkStruct)calloc(1,sizeof(_XCosWorkStruct));
         wstruct->IWorkPtrs=(int_T*)calloc(DimVI,sizeof(int_T));
         wstruct->IWorkWidth=DimVI; 
    }else{
         XCosWorkStruct wstruct= *((XCosWorkStruct*)(S->work));
         free(wstruct->IWorkPtrs);
         wstruct->IWorkPtrs=(int_T*)calloc(DimVI,sizeof(int_T));
         wstruct->IWorkWidth=DimVI;
    }
}

/**
 * Creates PWorkPtrs vector \n
 * If PWorkPtrs!=NULL deletes the current values stored as parameters
 * @param S
 * @param DimVP
 */
void ssSetNumPWork(SimStruct *S, int_T DimVP){
    //if(S->work==NULL){
    FILE *f;
    f=fopen("billes.log","w");
    fprintf(f,"qwertyuiop");
        
         S->work=(void**)calloc(1,sizeof(void*));
         XCosWorkStruct wstruct;
         wstruct= (XCosWorkStruct)calloc(1,sizeof(_XCosWorkStruct));
         wstruct->PWorkPtrs=(void**)calloc(DimVP,sizeof(void*));
         wstruct->PWorkWidth=DimVP; 
         *(S->work)=(void*) wstruct;
              
   // }else{
         //XCosWorkStruct wstruct= (XCosWorkStruct)(*(S->work));
         /*for(int i=0;i<wstruct->PWorkWidth;i++){
             free((wstruct->PWorkPtrs)[i]);
         }       
         free(wstruct->PWorkPtrs);*/
         //wstruct->PWorkPtrs=(void**)calloc(DimVP,sizeof(void*));
        // wstruct->PWorkWidth=DimVP;
    //}
}

/**
 * Deletes the current ports and creates new ones using calloc()
 * 
 * @param SimStruct *S
 * @param int_T inputPorts
 */
inline bool ssSetNumInputPorts(SimStruct *S, int_T nInPorts){   //TODO: See if this works
    
   if(nInPorts<0) return 0;
   void** auxptr=(void**)calloc(nInPorts,sizeof(void*));   
   if(auxptr==NULL) return 0;
   if(S->inptr!=NULL){
      for(int i=0;i<S->nin;i++){
         free(S->inptr[i]);
      }
      free(S->inptr); 
   }         
   S->inptr=auxptr;
   S->nin=nInPorts;        
    
   return 1;  
}

/**
 * Deletes the current port and creates a new one using calloc()
 * @param S
 * @param inPort
 * @param width
 */
inline void ssSetInputPortWidth(SimStruct *S, int_T inPort, int_T width){
   if(inPort>=0&inPort<S->nin){       
      if(S->inptr[inPort]!=NULL) free(S->inptr[inPort]);  
       S->inptr[inPort]=(real_T*)calloc(width,sizeof(real_T));
   }
}

/**
 * Deletes the current ports and creates new ones using calloc()
 * @param SimStruct *S
 * @param int_T outputPorts
 */
inline bool ssSetNumOutputPorts(SimStruct *S, int_T nOutPorts){   //TODO: See if this works
    
   if(nOutPorts<0) return 0;
   void** auxptr=(void**)calloc(nOutPorts,sizeof(void*));   
   if(auxptr==NULL) return 0;
   if(S->outptr!=NULL){
      for(int i=0;i<S->nout;i++){
         free(S->outptr[i]);
      }
      free(S->outptr); 
   }         
   S->outptr=auxptr;
   S->nout=nOutPorts;        
     
   return 1;  
}

/**
 * Deletes the current port and creates a new one using calloc()
 * @param S
 * @param outPort
 * @param width
 */
inline void ssSetOutputPortWidth(SimStruct *S, int_T outPort, int_T width){ // TODO: Modify outz
   if(outPort>=0&outPort<S->nin){       
      if(S->outptr[outPort]!=NULL) free(S->outptr[outPort]);  
       S->outptr[outPort]=(real_T*)calloc(width,sizeof(real_T));
   }
}

/**
 * Creates PWorkPtrs vector \n
 * If PWorkPtrs!=NULL deletes the current values stored as parameters
 * @param S
 * @param DimVP
 */
inline void ssSetNumSFcnParams(SimStruct *S, int_T numSFcnParams){
    if(numSFcnParams<0) return;
    if(S->oparptr!=NULL&&*(S->oparptr)!=NULL){      
         for(int i=0;i<S->nopar;i++){
             free((S->oparptr)[i]);
         }         
         free(S->oparptr);
    }
    S->oparptr=(void**)calloc(numSFcnParams,sizeof(void*));
    S->nopar=numSFcnParams;    
}

/**
 * Initializes continuous state, state derivatives and residuals.
 * All are set to zero by default
 * @param S
 * @param numContStates
 */
inline void ssSetNumContStates(SimStruct *S, int_T numContStates){
   if(numContStates<0) return;
    if(S->x!=NULL){      
         free(S->x);
         free(S->xd);
         free(S->res);
    }
    S->x=(real_T*)calloc(numContStates,sizeof(real_T));
    S->xd=(real_T*)calloc(numContStates,sizeof(real_T));
    S->res=(real_T*)calloc(numContStates,sizeof(real_T));
    S->nx=numContStates;  
}

/**
 * Initializes discrete states. Set to zero by default
 * @param S
 * @param numDiscStates
 */
inline void ssSetNumDiscStates(SimStruct *S, int_T numDiscStates){
   if(numDiscStates<0) return;
    if(S->z!=NULL){      
         free(S->z);
    }
    S->z=(real_T*)calloc(numDiscStates,sizeof(real_T));
    S->nz=numDiscStates;  
}



// XCos function's entry point
void S_FUNCTION_NAME(SimStruct *S, int flag){
    switch (flag)
    {
        case 0:     // compute the derivative of the continuous time state
            break;
        case 1:     // compute the outputs of the block
            mdlOutputs(S, -1);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:     // initialization       TODO: Initialisations     
            //mdlInitializeConditions(S);
            //mdlInitializeSampleTimes(S);
            mdlInitializeSizes(S);
            mdlStart(S);
            break;
        case 5:     // ending
            mdlTerminate(S);
            break;
        case 9:     // compute zero crossing surfaces and set modes
        default :
            break;
    }
}
#else
//---------------------------------------------------------------------------
// code for using easylink just for testing purposes
//---------------------------------------------------------------------------
#define int_T int
#define real_T double

inline void mexErrMsgTxt(char * Error_MSG)
{
	printf(Error_MSG);
	exit(1);
}
//---------------------------------------------------------------------------
#endif


/** \ingroup InterfaceClass 
* Convention to define type and size of parameters
*
*  >0 : fixed size RVector
*  -1 : dynamical size RVector
*  -2 : string
*  -3 : identifier
*/
#define DYN_RVECTOR_PARAM -1
/** \ingroup InterfaceClass 
* Convention to define type and size of parameters
*
*  >0 : fixed size RVector
*  -1 : dynamical size RVector
*  -2 : string
*  -3 : identifier
*/
#define STRING_PARAM -2
/** \ingroup InterfaceClass 
* Convention to define type and size of parameters
*
*  >0 : fixed size RVector
*  -1 : dynamical size RVector
*  -2 : string
*  -3 : identifier
*/
#define IDENTIFIER_PARAM -3


	
//---------------------------------------------------------------------------
 
 	/** \ingroup InterfaceClass 
    * ParamVector class.
    *
    * Encapsulation of parameter vectors*/
class ParamVector : public RVector
{
	/// Parameter vector Recovery  (no creation, copy of the adress, possibility of writing)
public:
	inline ParamVector(SimStruct *S,int_T port);
	inline void operator=(const RVector & V);
};

 	/** \ingroup InterfaceClass 
    * InputVector class.
    *
    * Encapsulation of real input vectors*/
class InputVector : public RVector
{
	/// Real input vector Recovery  (copy of values, impossibility of writing)
public:
	inline InputVector(SimStruct *S,int_T port);
	inline void operator=(const RVector & V);
};

 	/** \ingroup InterfaceClass 
    * InputIVector class.
    *
    * Encapsulation of integer real vectors*/
class InputIVector : public IVector
{
	/// Integer input vector Recovery  (copy of values, impossibility of writing)
public:
	inline InputIVector(SimStruct *S,int_T port);
	inline void operator=(const IVector & V);
};

 	/** \ingroup InterfaceClass 
    * OutputVector class.
    *
    * Encapsulation of real output vectors*/
class OutputVector : public RVector
{
	/// Output vector Recovery  (no creation, copy of the adress, possibility of writing)
public:
	inline OutputVector(SimStruct *S,int_T port);
	inline void operator=(const RVector & V);
};


	
//---------------------------------------------------------------------------
  	/** \ingroup InterfaceClass 
    * WorkRVector class.
    *
    * Encapsulation of real work vectors*/
class WorkRVector : public RVector
{	
/// Real work vector Recovery  (no creation, copy of the adress, possibility of writing)

public:
	inline WorkRVector(SimStruct *S);
	inline void operator=(const RVector & V);
};

	/** \ingroup InterfaceClass 
    * WorkIVector class.
    *
    * Encapsulation of integer work vectors*/
class WorkIVector : public IVector
{	
/// Integer work vector Recovery  (no creation, copy of the adress, possibility of writing)
public:
	inline WorkIVector(SimStruct *S);
	inline void operator=(const IVector & V);
};

    /** \ingroup InterfaceClass 
    * WorkPVector class.
    *
    * Encapsulation of pointer work vectors*/
class WorkPVector : public PVector
{	
/// Pointer work vector Recovery  (no creation, copy of the adress, possibility of writing)
public:
	inline WorkPVector(SimStruct *S);
	inline void operator=(const PVector & V);
};

    /** \ingroup InterfaceClass 
    * ContStateVector class.
    *
    * Encapsulation of continuous state vectors*/
class ContStateVector : public RVector
{	
/// Continuous state vector Recovery  (no creation, copy of the adress, possibility of writing)
public:
	inline ContStateVector(SimStruct *S);
	inline void operator=(const RVector & V);
};

    /** \ingroup InterfaceClass 
    * DeriveStateVector class.
    *
    * Encapsulation of continuous derived state vectors*/
class DeriveStateVector : public RVector
{
/// Continuous derived state vector Recovery  (no creation, copy of the adress, possibility of writing)
public:
	inline DeriveStateVector(SimStruct *S);
	inline void operator=(const RVector & V);
};

    /** \ingroup InterfaceClass 
    * DiscStateVector class.
    *
    * Encapsulation of discret state vectors*/
class DiscStateVector : public RVector
{	
/// Discret state vector Recovery  (no creation, copy of the adress, possibility of writing)
public:
	inline DiscStateVector(SimStruct *S);
	inline void operator=(const RVector & V);
};

//---------------------------------------------------------------------------
 	/** \ingroup InterfaceClass
    * MatlabMatrix class.
    *
    * Encapsulation of Matlab matrices : the matrix is adapted from the Matlab command window*/

class MatlabMatrix : public RMatrix
{

public:
	/** Recover an existing Matlab matrix
	* \param Name: name of the matrix
	* \param Site : "base" designs Matlab workspace */
	inline MatlabMatrix(String Name,String Site);

 	/** Like the first constructor but recover directly the name in one of the port parameters
	*
    * The Site is still "base"  */
	inline MatlabMatrix(SimStruct *S,int_T port);

    /** If a similar matrix (same name, same site and same sizes) exists, the constructor will
    * copy the existing matrix adress.
    *
    * Otherwise, the matrix is created and initialised with the value
	* \param Name: name of the matrix
    * \param Site: "base" designs Matlab workspace
	* \param nbl: number of lines
	* \param nbc: number of columns
    * \param valini: initial value */
	inline MatlabMatrix(String Name,String Site,int_T nbl,int_T nbc,real_T valini);

	/** Like the third constructor  but recover directly the name in one of the port parameters
    *
    * The Site is still "base"  */
	inline MatlabMatrix(SimStruct *S,int_T port,int_T  nbl,int_T nbc,real_T valini);

    /** Affectation */
	inline void operator=(const RMatrix & M);
};


//---------------------------------------------------------------------------
InputVector::InputVector(SimStruct *S,int_T port)
	: RVector(ssGetInputPortWidth(S,port))
{
	int_T i;
    InputRealPtrsType uPtrs = ssGetInputPortRealSignalPtrs(S,port);
	for (i=0;i<D;i++)
		T[i]=(*uPtrs[i]);
}
//---------------------------------------------------------------------------
void InputVector::operator=(const RVector & V)
{
	RVector::operator =(V);
}
//--------------------------------------------------------------------------
inline InputIVector::InputIVector(SimStruct *S,int_T port)
	: IVector(ssGetInputPortWidth(S,port))
{
	int_T i;
    InputRealPtrsType uPtrs = ssGetInputPortRealSignalPtrs(S,port);
	for (i=0;i<D;i++)
		T[i]=Round(*uPtrs[i]);
}
//---------------------------------------------------------------------------
inline void InputIVector::operator=(const IVector & V)
{
	IVector::operator =(V);
}
//---------------------------------------------------------------------------
inline OutputVector::OutputVector(SimStruct *S,int_T port)
	: RVector(ssGetOutputPortWidth(S,port),ssGetOutputPortRealSignal(S,port))
{
}
//---------------------------------------------------------------------------
inline void OutputVector::operator=(const RVector & V) 
{ 
	RVector::operator =(V); 
}
//---------------------------------------------------------------------------
inline ParamVector::ParamVector(SimStruct *S,int_T port)
	: RVector(mxGetNumberOfElements(ssGetSFcnParam(S,port)),mxGetPr(ssGetSFcnParam(S,port)))
{
}
//---------------------------------------------------------------------------
inline void ParamVector::operator=(const RVector & V)
{ 
	RVector::operator =(V); 
}
//---------------------------------------------------------------------------
inline real_T  InputValue(SimStruct *S,int_T port)
{
	return *(ssGetInputPortRealSignalPtrs(S,port)[0]);
}
//---------------------------------------------------------------------------

// TODO: Function changed!
inline void WriteOutputValue(SimStruct *S,int_T port,real_T val)
{
	/*InputRealPtrsType x=ssGetOutputPortRealSignal(S,port);
	*(x[0])=val;*/
        real_T* x=ssGetOutputPortRealSignal(S,port);
        x[0]=val;
}
//---------------------------------------------------------------------------
inline real_T  ParamValue(SimStruct *S,int_T port)
{
	return mxGetPr(ssGetSFcnParam(S,port))[0];
}
//---------------------------------------------------------------------------
inline void ParamString(SimStruct *S,int_T port,String &C)
{
	if (mxGetString(ssGetSFcnParam(S,port), C, StringSize))
	{
		sprintf(ERROR_MSG_BUFFER,"EasyLink error: Parameter port %i must be a string",port);
		mexErrMsgTxt(ERROR_MSG_BUFFER);
		return;
	}
}
//---------------------------------------------------------------------------
inline int_T InputWidth(SimStruct *S,int_T port)
{
	return ssGetInputPortWidth(S,port);
}
//---------------------------------------------------------------------------
inline int_T OutputWidth(SimStruct *S,int_T port)
{
	return ssGetOutputPortWidth(S,port);
}
//---------------------------------------------------------------------------
inline int_T ParamWidth(SimStruct *S,int_T port)
{
	return mxGetNumberOfElements(ssGetSFcnParam(S,port));
}
//---------------------------------------------------------------------------
inline WorkRVector::WorkRVector(SimStruct *S)
	: RVector(ssGetNumRWork(S),ssGetRWork(S))
{
}
//---------------------------------------------------------------------------
inline void WorkRVector::operator=(const RVector & V) 
{ 
	RVector::operator =(V); 
}
//---------------------------------------------------------------------------
inline WorkIVector::WorkIVector(SimStruct *S)
	: IVector(ssGetNumIWork(S),ssGetIWork(S)) 
{
}
//---------------------------------------------------------------------------
inline void WorkIVector::operator=(const IVector & V) 
{ 
	IVector::operator =(V); 
}
//---------------------------------------------------------------------------
inline WorkPVector::WorkPVector(SimStruct *S)
	: PVector(ssGetNumPWork(S),ssGetPWork(S))
{
}
//---------------------------------------------------------------------------
inline void WorkPVector::operator=(const PVector & V) 
{ 
	PVector::operator =(V); 
}
//---------------------------------------------------------------------------
inline ContStateVector::ContStateVector(SimStruct *S)
	: RVector(ssGetNumContStates(S),ssGetContStates(S))
{
}
//---------------------------------------------------------------------------
inline void ContStateVector::operator=(const RVector & V) 
{ 
	RVector::operator =(V); 
}
//---------------------------------------------------------------------------
inline DeriveStateVector::DeriveStateVector(SimStruct *S)
	: RVector(ssGetNumContStates(S),ssGetdX(S))
{
}
//---------------------------------------------------------------------------
inline void DeriveStateVector::operator=(const RVector & V) 
{ 
	RVector::operator =(V); 
}
//---------------------------------------------------------------------------
inline DiscStateVector::DiscStateVector(SimStruct *S)
	: RVector(ssGetNumDiscStates(S),ssGetDiscStates(S))
{
}
//---------------------------------------------------------------------------
inline void DiscStateVector::operator=(const RVector & V) 
{ 
	RVector::operator =(V); 
}
//---------------------------------------------------------------------------
inline const mxArray * ExistMatlabMatrix(String Name,String Site)
{
	const mxArray *A;
	const mxArray *B;

	A=mexGetVariablePtr(Site,Name); 

	if (A && mxIsDouble(A))
		B=A;
	else
		B=NULL;
	return B;
}
//---------------------------------------------------------------------------
inline const mxArray * ExistMatlabMatrix(String Name,String Site,int_T  nbl,int_T nbc)
{
	const mxArray *A;
	const mxArray *B;

	A=mexGetVariablePtr(Site,Name); 

	if (A && mxIsDouble(A))
		B=A;
	else
		B=NULL;
	return B;
}
//---------------------------------------------------------------------------
inline const mxArray * CreateMatlabMatrix(String Name,String Site,int_T  nbl,int_T nbc)
{
	mxArray *A;
	const mxArray *B;
	A=mxCreateDoubleMatrix(nbc,nbl, mxREAL);
	if (!A)
	{
		sprintf(ERROR_MSG_BUFFER,"EasyLink error: Could not create double matrix named '%s'.\n",Name);
		mexErrMsgTxt(ERROR_MSG_BUFFER);
        }
        
        //////////        
        SciErr sciErr = createNamedMatrixOfDouble(pvApiCtx,Name,nbl,nbc, (double* )A); /* pvApiCtx is a global variable */
        //////////////////
	if (sciErr.iErr)
	{
		sprintf(ERROR_MSG_BUFFER,"EasyLink error: Could not put variable '%s' in '%s' workspace.\n",Name,Site);
		mexErrMsgTxt(ERROR_MSG_BUFFER);
    }

	mxDestroyArray(A);

	B=mexGetVariablePtr(Site,Name); 

	return B;
}
//---------------------------------------------------------------------------
inline MatlabMatrix::MatlabMatrix(String Name,String Site) : RMatrix(0,0,NULL)
{
    const mxArray *A=ExistMatlabMatrix(Name,Site);
    
	if (A)
	{
		T=mxGetPr(A);
		L=mxGetN(A);
		C=mxGetM(A);
	}
	else
	{
		sprintf(ERROR_MSG_BUFFER,"EasyLink error: No double matrix named '%s' exists !.\n",Name);
		mexErrMsgTxt(ERROR_MSG_BUFFER);
	}
}
//---------------------------------------------------------------------------
inline MatlabMatrix::MatlabMatrix(SimStruct *S,int_T port) : RMatrix(0,0,NULL)
{
	const mxArray *A;	
	String Name;
	ParamString(S,port,Name);
	
	A=ExistMatlabMatrix(Name,"base");
	if (A)
	{
		T=mxGetPr(A); 
		L=mxGetN(A);
		C=mxGetM(A);
	}
	else
	{
		sprintf(ERROR_MSG_BUFFER,"EasyLink error: No double matrix named '%s' exists !.\n",Name);
		mexErrMsgTxt(ERROR_MSG_BUFFER);
	}
}
//---------------------------------------------------------------------------
inline MatlabMatrix::MatlabMatrix(String Name,String Site,int_T nbl,int_T nbc,real_T valini) : RMatrix(nbl,nbc,NULL)
{
	const mxArray *A=ExistMatlabMatrix(Name,Site,nbl,nbc);

	if (A)
	{   // The matrix exists
		T=mxGetPr(A);
	}
	else
	{	// The matrix doesn't exist
		A=CreateMatlabMatrix(Name,Site,nbl,nbc);
		T=mxGetPr(A);
		Init(valini);
	}
}
//---------------------------------------------------------------------------
inline MatlabMatrix::MatlabMatrix(SimStruct *S,int_T port,int_T  nbl,int_T nbc,real_T valini) : RMatrix(nbl,nbc,NULL)
{
	const mxArray *A;
	String Name;
	ParamString(S,port,Name);
	
	A=ExistMatlabMatrix(Name,"base",nbl,nbc);
    if (A)
	{   // The matrix exists
		T=mxGetPr(A);
	}
	else
	{	// The matrix doesn't exist
		A=CreateMatlabMatrix(Name,"base",nbl,nbc);
		T=mxGetPr(A);
		Init(valini);
	}
}
//---------------------------------------------------------------------------
inline void MatlabMatrix::operator=(const RMatrix & M)
{
	RMatrix::operator =(M);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
inline void InputInit(SimStruct *S,int_T Nb,int_T *Dim,int_T *DFT)
{
	int_T i;
    if (!ssSetNumInputPorts(S,Nb)) return;

	for (i=0;i<Nb;i++)
	{
		ssSetInputPortWidth(S, i, Dim[i]);
		ssSetInputPortDirectFeedThrough(S, i, DFT[i]);
	}
}
//---------------------------------------------------------------------------
inline void	OutputInit(SimStruct *S,int_T Nb,int_T *Dim)
{
	int_T i;
    if (!ssSetNumOutputPorts(S,Nb)) return;
	for (i=0;i<Nb;i++)
		ssSetOutputPortWidth(S, i, Dim[i]);
}

inline void ParamInit(SimStruct *S,int_T Nb,int_T *Dim,int_T *Fix)
{
	int_T i;

	ssSetNumSFcnParams(S, Nb);
   	for (i=0;i<Nb;i++)
	{
		if (Fix[i]==1)
			ssSetSFcnParamNotTunable(S,i);
	}

	if (ssGetSFcnParamsCount(S) != Nb)
	{
		sprintf(ERROR_MSG_BUFFER,"EasyLink error: %i parameters are expected",Nb);
		mexErrMsgTxt(ERROR_MSG_BUFFER);
		return;
	}

	//mdlCheckParameters(S);
	if (ssGetErrorStatus(S)!=NULL)
		return;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
inline void WorkVectorInit(SimStruct *S,int_T DimVR,int_T DimVI,int_T DimVP)
{
    //if(DimVR>0)ssSetNumRWork(S, DimVR);
   // if(DimVI>0)ssSetNumIWork(S, DimVI);
    if(DimVP>0) ssSetNumPWork(S, DimVP);
}
//---------------------------------------------------------------------------
inline void StateInit(SimStruct *S,int_T DimEC,int_T DimED)
{
	ssSetNumContStates(S,DimEC);
	ssSetNumDiscStates(S,DimED);
}

#endif