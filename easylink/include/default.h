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
//------------------------------------------------------------------------------

#ifndef InputNb
#define InputNb					0
enum    InputName				{  };
int_T   InputsWidth[1] =		{ -1  };
int_T   DirectFeedThrough[1] =	{   1 };
#endif

#ifndef OutputNb
#define OutputNb			0
enum    OutputName			{  };
int_T   OutputsWidth[1] =	{ -1  };
#endif

#ifndef ParamNb
#define ParamNb				0
enum    OutputName			{  };
int_T   OutputsWidth[1] =	{ -1  };
int_T   ParamsFixes[1] =	{  1  }; // 1 for "not tunable"
#endif

#ifndef WorkRVectorWidth
#define WorkRVectorWidth	  			0
#endif

#ifndef WorkIVectorWidth
#define WorkIVectorWidth 				0
#endif

#ifndef WorkPVectorWidth
#define WorkPVectorWidth 				0
#endif

#ifndef ContStateWidth
#define ContStateWidth					0
#endif

#ifndef DiscStateWidth
#define DiscStateWidth					0
#endif




//------------------------------------------------------------------------------
#ifdef  MATLAB_MEX_FILE  

/** \ingroup InterfaceClass 
* Default mdlInitializeSizes(SimStruct *S)
*
* Ports initializations using InputNb, InputName,InputsWidth, 
*   DirectFeedThrough, OutputNb, OutputName, OutputsWidth, ParamNb,
*   ParamName, ParamsWidth, ParamsFixes, WorkRVectorWidth, WorkIVectorWidth,
*   WorkPVectorWidth, ContStateWidth and DiscStateWidth values.
*/
#ifndef MDL_INITIALIZE_SIZES
#define MDL_INITIALIZE_SIZES
static void mdlInitializeSizes(SimStruct *S)
{
	ParamInit(S,ParamNb,ParamsWidth,ParamsFixes);
	InputInit(S,InputNb,InputsWidth,DirectFeedThrough);
	OutputInit(S,OutputNb,OutputsWidth);
	WorkVectorInit(S,WorkRVectorWidth,WorkIVectorWidth,WorkPVectorWidth);
	StateInit(S,ContStateWidth,DiscStateWidth);
    ssSetNumSampleTimes(S, 1);
}
#endif

//---------------------------------------------------------------------------

/** \ingroup InterfaceClass 
* Default  mdlSetInputPortWidth(SimStruct *S,int port,int width)
*
* Check if the proposed width for a dynamically sized input port is acceptable.
* 
*/
#ifndef MDL_SET_INPUT_PORT_WIDTH
#define MDL_SET_INPUT_PORT_WIDTH
static void mdlSetInputPortWidth(SimStruct *S, int_T port,int_T proposedwidth)
{
	ssSetInputPortWidth(S,port,proposedwidth);
}
#endif

//---------------------------------------------------------------------------

/** \ingroup InterfaceClass 
* Default  mdlSetOutputPortWidth(SimStruct *S,int port,int width)
*
* Check if the proposed width for a dynamically sized output port is acceptable.
*/
#ifndef MDL_SET_OUTPUT_PORT_WIDTH
#define MDL_SET_OUTPUT_PORT_WIDTH
static void mdlSetOutputPortWidth(SimStruct *S,int_T port,int_T proposedwidth)
{
	ssSetOutputPortWidth(S,port,proposedwidth);
}
#endif

//------------------------------------------------------------------------------

/** \ingroup InterfaceClass 
* Default mdlInitializeSampleTimes(SimStruct *S)
*
* Default sample time mode = discrete sample time
*/
#ifndef MDL_INITIALIZE_SAMPLE_TIME
#define MDL_INITIALIZE_SAMPLE_TIME
static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
	ssSetOffsetTime(S, 0, FIXED_IN_MINOR_STEP_OFFSET);
}
#endif

//------------------------------------------------------------------------------

/** \ingroup InterfaceClass 
* Default mdlStart(SimStruct *S)
*
* Nothing is done !
*/
#ifndef MDL_START
#define MDL_START
static void mdlStart(SimStruct *S)
{
/*	for (int i=0;i<InputNb;i++)
	{
		if (!ssGetInputPortConnected(S,i)) 
		{
			sprintf(ERROR_MSG_BUFFER,"EasyLink error: Input port %i is not connected",i);
			ssSetErrorStatus(S,ERROR_MSG_BUFFER);
			return;
		}
	}*/
}
#endif

//------------------------------------------------------------------------------

/** \ingroup InterfaceClass 
* Default mdlInitializeConditions(SimStruct *S)
*
* Nothing is done !
*/
#ifndef MDL_INITIALIZE_CONDITIONS
#define MDL_INITIALIZE_CONDITIONS
static void mdlInitializeConditions(SimStruct *S)
{
}
#endif

//------------------------------------------------------------------------------

/** \ingroup InterfaceClass 
* Default mdlOutputs(SimStruct *S, int_T tid)
*
* Nothing is done !
*/
#ifndef MDL_OUTPUTS
#define MDL_OUTPUTS
static void mdlOutputs(SimStruct *S, int_T tid)
{
}
#endif

//------------------------------------------------------------------------------

/** \ingroup InterfaceClass 
* Default mdlTerminate(SimStruct *S)
*
* Nothing is done !
*/
#ifndef MDL_TERMINATE
#define MDL_TERMINATE
static void mdlTerminate(SimStruct *S)
{
}
#endif

//---------------------------------------------------------------------------

/** \ingroup InterfaceClass 
* DefaultmdlCheckParameters(SimStruct *S)
*
* Check if parameters have the right type and the right size according to
* ParamsWidth values.
*/
#ifndef MDL_CHECK_PARAMETERS
#define MDL_CHECK_PARAMETERS
static void mdlCheckParameters(SimStruct *S)
{
	String C;
 	for (int_T i=0;i<ParamNb;i++)
	{
		if ((ParamsWidth[i]==STRING_PARAM)||(ParamsWidth[i]==IDENTIFIER_PARAM))	
		{
			// check if it is really a string 
			if (!mxIsChar(ssGetSFcnParam(S,i)))
			{ 
				sprintf(ERROR_MSG_BUFFER,"EasyLink error: Parameter port %i must be a string",i);
				ssSetErrorStatus(S,ERROR_MSG_BUFFER);
				return;
			}
			if (ParamsWidth[i]==IDENTIFIER_PARAM)
			{ 
				// check if it is really a identifier
				ParamString(S,i,C);
				if (!IsIdentificator(C))
				{
					sprintf(ERROR_MSG_BUFFER,"EasyLink error: Parameter port %i must be a valid identifer",i);
					ssSetErrorStatus(S,ERROR_MSG_BUFFER);
					return;
				}
			}
		}
		else 
		{
			// check if it is a scalar or a vector
			if (mxIsSparse(ssGetSFcnParam(S,i))||
				mxIsComplex(ssGetSFcnParam(S,i))||
				!mxIsNumeric(ssGetSFcnParam(S,i)))
			{ 
				sprintf(ERROR_MSG_BUFFER,"EasyLink error: Parameter port %i must be a scalar or a vector",i);
				ssSetErrorStatus(S,ERROR_MSG_BUFFER);
				return;
			}

			// check the size
			if ((ParamsWidth[i]>=1)&&(mxGetNumberOfElements(ssGetSFcnParam(S,i))!=ParamsWidth[i]))
			{
			    sprintf(ERROR_MSG_BUFFER,"EasyLink error: Size of parameter port %i must be %i",i,ParamsWidth[i]);
				ssSetErrorStatus(S,ERROR_MSG_BUFFER);
				return;
			}
		}
	}
}
#endif
#include "simulink.c" 
#elif defined(SCILAB_XCOS_FILE)
#ifndef MDL_INITIALIZE_SIZES
#define MDL_INITIALIZE_SIZES
static void mdlInitializeSizes(SimStruct *S)
{	
        //ParamInit(S,ParamNb,ParamsWidth,ParamsFixes);
	WorkVectorInit(S,WorkRVectorWidth,WorkIVectorWidth,WorkPVectorWidth);	
}
#endif
#else
#include "cg_sfun.h"       
#endif
//------------------------------------------------------------------------------
