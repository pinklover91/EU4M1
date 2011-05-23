//---------------------------------------------------------------------------
//
// Copyright (c) 2005 FEMTO-ST / ENSMM / UFC / UTBM, Besançon, France
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
#ifndef Tools_h
#define Tools_h
//---------------------------------------------------------------------------
#include "easylink.h"
//---------------------------------------------------------------------------
#include <time.h>
#include <math.h>
#include <float.h>
#include <string.h>
#include <stdlib.h>
//---------------------------------------------------------------------------
#define PrecisionDouble     0.000000000000001
#define NombreChiffreDouble 15
//---------------------------------------------------------------------------

/** \ingroup BasicClass 
 * Return the nearest whole number of the real x  */
inline int_T Round(real_T x);

/** \ingroup BasicClass 
 * Return the absolute value of a real x
 * \param x real */
inline real_T Abs(real_T x);

/** \ingroup BasicClass 
 * Return the absolute value of a integer x
 * \param x integer */
inline int_T Abs(int_T x);

/** \ingroup BasicClass 
 * Test the equality between x and y, taking account of the real precision
 * \param x real
 * \param y real */
inline bool EqualityReal(real_T x,real_T y);

//---------------------------------------------------------------------------
/** \ingroup BasicClass 
 * Initialize the generator of random number thanks to time machine */
inline void InitRandom(void);

/** \ingroup BasicClass 
 * Return a random real value in [0,1[*/
inline real_T RandomReal(void);

/** \ingroup BasicClass 
 * Return a random integer value between 0 and n-1 included */
inline int_T RandomInt(int_T n);

//---------------------------------------------------------------------------
/** \ingroup BasicClass 
 * Return true if the literal (chaine) has the shape of a variable identificator */
inline bool IsIdentificator(String C);

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
inline int_T Round(real_T x) 
{ 
	if (x>-0.5)                 //i=(int)x i est la partie entière de x
		return((int_T)(x+0.5)); //on prend la partie entière de x+0.5
	else
		return((int_T)(x-0.5)); 
}
//---------------------------------------------------------------------------
inline real_T Abs(real_T x)
{ if (x>=0) return(x);
  else return(-x);
}
//---------------------------------------------------------------------------
inline int_T Abs(int_T x)
{ if (x>=0) return(x);
  else return(-x);
}
//---------------------------------------------------------------------------
inline bool EqualityReal(real_T x,real_T y)
{
  real_T mx,my;
  int_T ex,ey;
  mx=frexp(x,&ex);
  my=frexp(y,&ey);
  return( ( (ex==ey) && (mx<my+PrecisionDouble) && (mx>my-PrecisionDouble) ) );
}
//---------------------------------------------------------------------------
inline void InitRandom(void)
{
   time_t t;
   srand((unsigned) time(&t));
   printf("EasyLink message: Standart generator of random number reinitialized.\n");
}
//---------------------------------------------------------------------------
inline real_T RandomReal(void)
{
    return(rand()*1.0/(RAND_MAX+1));
}
//---------------------------------------------------------------------------
inline int_T RandomInt(int_T n)
{
	return(rand()*n/(RAND_MAX+1));
}
//---------------------------------------------------------------------------
inline bool IsIdentificator(String C)
{
	unsigned int i;
	bool valide;
	valide=( ( (C[0]>='a')&&(C[0]<='z') ) || ( (C[0]>='A')&&(C[0]<='Z') ) );
	i=1;
	while ((i<strlen(C))&&valide)
	{
		valide= ( ( (C[i]>='a')&&(C[i]<='z') ) || ( (C[i]>='A')&&(C[i]<='Z') ) || ( (C[i]>='0')&&(C[i]<='9') || (C[i]=='_') ) );
		i++;
	}
	return(valide);
}
//---------------------------------------------------------------------------
#endif
