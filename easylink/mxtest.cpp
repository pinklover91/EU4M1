//------------------------------------------------------------------------------
// S-Fonction mxtest
//
// Created by Guillaume: 2005
//------------------------------------------------------------------------------
#define S_FUNCTION_NAME  mxtest
#define S_FUNCTION_LEVEL 2
//------------------------------------------------------------------------------
#include "easylink.h"
//------------------------------------------------------------------------------
#define InputNb 						2
enum    InputName						{ IN1, IN2 };
int_T   InputsWidth[InputNb] =			{  -1,   1 }; // -1 for dynamic size
int_T   DirectFeedThrough[InputNb] =	{   1,   1 };
//------------------------------------------------------------------------------
#define OutputNb						2
enum    OutputName						{ OUT1, OUT2 };
int_T   OutputsWidth[OutputNb] =	 	{   -1,    1 };
//------------------------------------------------------------------------------
#define ParamNb 						3
enum    ParamName						{ GAIN, OFFSET, NAME };
int_T   ParamsWidth[ParamNb] =			{    2,      1,   -3 }; // -1 for dynamic size
int_T   ParamsFixes[ParamNb] =			{    1,      0,    1 }; // 1 => "not tunable"
//------------------------------------------------------------------------------
#define WorkRVectorWidth	  			0
#define WorkIVectorWidth 				0
#define WorkPVectorWidth 				0
//------------------------------------------------------------------------------
#define ContStateWidth					0
#define DiscStateWidth					0
//------------------------------------------------------------------------------
#define MDL_START
static void mdlStart(SimStruct *S)
{
	MatlabMatrix M(S,NAME,2,3,0.1);
	M[0][1]=2;
}
//------------------------------------------------------------------------------
#define MDL_OUTPUTS
static void mdlOutputs(SimStruct *S, int_T  tid)
{
    int_T          i;
    InputVector   U1(S,IN1);
    OutputVector  Y(S,OUT1);
    ParamVector   G(S,GAIN);
    real_T         U2=InputValue(S,IN2);
	real_T         O=ParamValue(S,OFFSET);
	MatlabMatrix  M(S,NAME);

	M[0][0]=M[0][0]+1.0;

    for (i=0; i<Y.Size(); i++) 
        Y[i] = G[0] * U1[i]+O; 
		
	WriteOutputValue(S,OUT2,U2);
}
//------------------------------------------------------------------------------
#include "Default.h"
//------------------------------------------------------------------------------
