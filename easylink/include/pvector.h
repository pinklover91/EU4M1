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
#ifndef PVector_h
#define PVector_h
//---------------------------------------------------------------------------
#include "easylink.h"
//---------------------------------------------------------------------------
/** \ingroup BasicClass
 *
 * a pointer vector class.
 */
class PVector
{

protected:
    /// vector size
	int_T D;
    /// pointer on elements
	void **T;
    /// Is the vector shared ? (yes if the vector arises from Matlab)
	bool Shared;

public:
	
	// Constructors and affiliated methods ----------------------------------

    /** Construct a PVector and allocate a memory space for data. 
	* The PVector is not shared. 
    * \param dim the number of element */
	inline PVector(int_T dim);

    /** Construct a PVector using an existing array. 
	* Copy the address. This PVector is shared.
    * \param dim the number of element
    * \param t address of raw datas */
	inline PVector(int_T dim,void **t);

    /** Copy constructor. The PVector is not shared.
    * \param V the PVector to copy*/
	inline PVector(const PVector &V);

    /** Dummy constructor. 
	* Construct a PVector whose size is 0 and which points on NULL */
    inline PVector(void);

    /** Empty the PVector and allocate a memory space for data. 
	* The PVector is not shared. 
    * \param dim the number of element
    * \see PVector(int_T dim) which do the same job as constructor */
	inline void SetPVector(int_T dim);

	// Destructor and affiliated methods ------------------------------------

	/** Empty the PVector. Free the memory if not shared.
	* 	\see Empty() method. */
	inline ~PVector(void);

    /** Empty the PVector. Free the memory if not shared. */
    inline void Empty(void);

    // Sharing methods ------------------------------------------------------

    /** Empty the PVector and use the same data as another PVector. The PVector is shared.
    * \param V the source RVector */
    inline void ShareArray(PVector & V);

	// Operator = and initialization methods -------------------------------

    /** Affectation
    *
    * Impossible if PVector is shared and sizes don't match. */
  	inline void operator=(const PVector &V);

	// Read/write methods -------------------------------------------------------

    /** Access to the pointer i */
	inline void* & operator[](int_T i);

	// Size methods ------------------------------------------------

	/** Return vector size	as an integer */
	inline int_T Size(void);

	/** Return vector size	as an integer */
	inline int_T Length(void);
	
};

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
inline PVector::PVector(int_T dim)
{
	D=dim;
	T=new void*[D];//T contains the adress of the first component table which is a pointer void*
	Shared=false;
}
//---------------------------------------------------------------------------
inline PVector::PVector(int_T dim,void **t)
{
	D=dim;
	T=t;
	Shared=true;
}
//---------------------------------------------------------------------------
inline PVector::PVector(const PVector &V)
{
	D=V.D;
	T=new void*[D];
	
	memcpy((void*)T,(void*)V.T, D*sizeof(void*) );

	Shared=false;
}
//---------------------------------------------------------------------------
inline PVector::PVector(void)
{
    D=0;
	T=NULL;
	Shared=false;
}
//---------------------------------------------------------------------------
inline PVector::~PVector(void)
{
	Empty();
}
//---------------------------------------------------------------------------
inline void PVector::Empty(void)
{
    if (D!=0)
    {
        if (!Shared)
            delete [] T;
	    T=NULL;
        D=0;
		Shared=false;
    }
}
//---------------------------------------------------------------------------
inline void PVector::ShareArray(PVector & V)
{
    Empty();
	Shared=true;
	D=V.D;
	T=V.T;
}
//---------------------------------------------------------------------------
inline void PVector::SetPVector(int_T dim)
{
    Empty();
    D=dim;
	T=new void*[D];
}
//---------------------------------------------------------------------------
inline void PVector::operator=(const PVector &V)
{
    if (D==V.D)
 		memcpy((void*)T,(void*)V.T, D*sizeof(void*) );
    else
    {
        if (!Shared)
        {
            Empty();
			D=V.D;
            T=new void*[D];
			memcpy((void*)T,(void*)V.T, D*sizeof(void*) );
        }
        else
		{
    		sprintf(ERROR_MSG_BUFFER,"EasyLink error: Unable to affect a %i pvector to a %i pvector.\n",V.D,D);
			mexErrMsgTxt(ERROR_MSG_BUFFER);
		}
     }
}
//---------------------------------------------------------------------------
inline void* & PVector::operator[](int_T i)
{
	if ((i<0)||(i>=D))
	{
		sprintf(ERROR_MSG_BUFFER,"EasyLink error: PVector index overflow ! %i inferior to 0 or superior to %i.\n",i,D-1);
		mexErrMsgTxt(ERROR_MSG_BUFFER);
		//return PVectorErrorValue;
	}
	return(T[i]);
}
//---------------------------------------------------------------------------
inline int_T PVector::Size(void)
{
	return(D);
}
//---------------------------------------------------------------------------
inline int_T PVector::Length(void)
{
	return(D);
}
//---------------------------------------------------------------------------
#endif
