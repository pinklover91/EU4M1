/**
* \mainpage 
*
* \section Introduction
*
* Easylink is a library of classes that makes easier the development of C-mex S-function for Simulink.
*
* \section License
*
* This library is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
*
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with the library; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*
* See the included license: "LICENSE.TXT"
*
* Copyright (c) 2007 FEMTO-ST / ENSMM / UFC / UTBM, Besançon, France
*
* Adress: Institut FEMTO-ST, 24 rue Alain Savary, 25000 Besançon, France
*
* \section Development
*
* This library is written by students and researchers and is under development! Chances are good there's a crucial step that hasn't made it into the documentation. You can ask for help (please provide enough information to work with, and preferably be aware of what you're doing!) and keep track of major changes to the software. Latest release of the library is available at http://www.lab.cnrs.fr/openblockslib/
* 
* Please, send bug reports to: guillaume.laurent---AT---ens2m.fr
*
* \section Required Required softwares
*
* EasyLink requires Matlab/simulink 5.3 or higher to build C-mex S-function, but some basic classes as RVector, RMatrix, etc. can be used without Matlab for other purpose.
*
* EasyLink is developed and tested mainly on Windows platforms, but should work on Unix/Linux as well.
*
* \section Installation Installation procedure
*
* 	-# Unpack the files to a local directory, for example: C:\\easylink 
*	-# Open Matlab
*	-# Set Matlab current directory to C:\\easylink
*
* \section Building Building procedure
*
* To build the mxtest.cpp C-mex S-function follow these instructions:
*
*	-# Execute the command \code mex -setup \endcode in Matlab command window and follow instructions, an installed C++ compiler is required (MS Visual from 2005 version is prefered)
*	-# Execute the command \code build mxtest.cpp \endcode
*	-# Open Simulink
*	-# Open the test file (test.mdl) and run it to check the process
*
* \section Acknowledgments
*
* Thanks to Richard J. Wagner for his efficient Mersenne Twister random number generator.
*
*/

/// \defgroup BasicClass Basic classes and functions
/// \defgroup InterfaceClass Classes and functions for C-mex S-function
