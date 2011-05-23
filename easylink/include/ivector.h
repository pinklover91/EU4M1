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
#ifndef IVector_h
#define IVector_h
//---------------------------------------------------------------------------
#include "easylink.h"
//---------------------------------------------------------------------------
/** \ingroup BasicClass
 *
 * An integer vector class.
 */
class IVector
{

protected:
    /// vector size
	int_T D;
    /// pointer on integer elements
	int_T *T;
    /// Is the vector shared ? (yes if the vector arises from Matlab)
	bool Shared;

public:

	// Constructors and affiliated methods ----------------------------------

    /** Construct a IRVector and allocate a memory space for data. 
	* The IVector is not shared. 
    * \param dim the number of element */
	inline IVector(int_T dim);

    /** Construct a IVector using an existing array. 
	* Copy the address. This IVector is shared.
    * \param dim the number of element
    * \param t address of raw datas */
	inline IVector(int_T dim,int_T *t);

    /** Copy constructor. The IVector is not shared.
    * \param V the IVector to copy*/
	inline IVector(const IVector &V);

    /** Dummy constructor. 
	* Construct a IVector whose size is 0 and which points on NULL */
    inline IVector(void);
 	
    /** Empty the IVector and allocate a memory space for data. 
	* The IVector is not shared. 
    * \param dim the number of element
    * \see IVector(int_T dim) which do the same job as constructor */
	inline void SetIVector(int_T dim);
	
	// Destructor and affiliated methods ------------------------------------

	/** Empty the IVector. Free the memory if not shared.
	* 	\see Empty() method. */
	inline ~IVector(void);

    /** Empty the IVector. Free the memory if it is not shared.*/
    inline void Empty(void);

    // Sharing methods ------------------------------------------------------

    /** IVector points on (is) a shared vector V
    * \see IVector(int_T dim,real_T *t) which is the same but which is a constructor*/
    inline void ShareArray(IVector & V);

	// Operator = and initialization methods -------------------------------

	/** Affectation
    *
    * Impossible if IVector is shared and sizes don't match. */
	inline void operator=(const IVector &V);

	/** Initialization of all elements at the same value
    * \param x real value */
	inline void Init(int_T x);
	
	// IVector-Integer operation ------------------------------------------------
	
    /** Return a vector such as
    * \param x has been substracted to each of its coefficient */
    inline IVector operator-(int_T x);

     /** Return a vector such as
    * \param x has been summed to each of its coefficient */
    inline IVector operator+(int_T x);

	// Read/write methods -------------------------------------------------------

    /** Access to the coefficient i */
	inline int_T & operator[](int_T i);

	// Size methods ------------------------------------------------

    /** Return vector size as an integer */
	inline int_T Size(void);

    /** Return vector size as an integer (same as Size) */
	inline int_T Length(void);

	// Comparison methods ---------------------------------------------------
	
    /** Compare two vectors*/
	inline bool operator==(const IVector &V);

	/** Return true if
	* \param x integer value belongs to the IVector */
	inline bool Include(int_T x);

	// Output methods -------------------------------------------------
	
	/** Print the IVector elements in the console window 
	* \param Format typesetting of elements */
	inline void Printf(char * Format="  %i");

	// ----------------------------------------------------------------

	friend class IMatrix;

};

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
inline IVector::IVector(int_T dim)
{
	D=dim;
	T=new int_T[D];
	Shared=false;
}
//---------------------------------------------------------------------------
inline IVector::IVector(int_T dim,int_T *t)
{
	D=dim;
	T=t;
	Shared=true;
}
//---------------------------------------------------------------------------
inline IVector::IVector(const IVector &V)
{
	D=V.D;
	T=new int_T[D];

	memcpy((void*)T,(void*)V.T, D*sizeof(int_T) );

	Shared=false;
}
//---------------------------------------------------------------------------
inline IVector::IVector(void)
{
    D=0;
    T=NULL;
    Shared=false;
}
//---------------------------------------------------------------------------
inline IVector::~IVector(void)
{
	Empty();
}
//---------------------------------------------------------------------------
inline void IVector::Empty(void)
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
inline void IVector::ShareArray(IVector & V)
{
	Empty();
	Shared=true;
    D=V.D;
    T=V.T;
}
//---------------------------------------------------------------------------
inline void IVector::Init(int_T x)
{
	int_T i=D;
	int_T* P=T;
	for (;i--;P++)
		*P=x;
}
//---------------------------------------------------------------------------
inline void IVector::SetIVector(int_T dim)
{
    Empty();
    D=dim;
	T=new int_T[D];
}
//---------------------------------------------------------------------------
inline void IVector::operator=(const IVector &V)
{
    if (D==V.D)
 		memcpy((void*)T,(void*)V.T, D*sizeof(int_T) );
    else
    {
        if (!Shared)
        {
            Empty();
			D=V.D;
            T=new int_T[D];
            memcpy((void*)T,(void*)V.T, D*sizeof(int_T) );

        }
        else
		{
    		sprintf(ERROR_MSG_BUFFER,"EasyLink error: Unable to affect a %i IVector to a shared %i IVector.\n",V.D,D);
			mexErrMsgTxt(ERROR_MSG_BUFFER);
		}

     }
}
//---------------------------------------------------------------------------
inline bool IVector::operator==(const IVector &V) // improvable
{
	int_T i=0;
	bool res;
	if (V.D==D)
	{
		while ((i<D)&&(T[i]==V.T[i])) i++;
		res=(i==D);
	}
	else
		res=false;
	return(res);
}
//---------------------------------------------------------------------------
inline bool IVector::Include(int_T x) // improvable
{	
	int_T i=0;
	bool res;
	
	while ((i<D)&&(T[i]!=x)) 
		i++;
	res=(i<D);
	return res;
}
//---------------------------------------------------------------------------
inline int_T & IVector::operator[](int_T i)
{
	if ((i<0)||(i>=D))
	{
		sprintf(ERROR_MSG_BUFFER,"EasyLink error: IVector Index overflow ! %i inferior to 0 or superior to %i.\n",i,D-1);
		mexErrMsgTxt(ERROR_MSG_BUFFER);
	}

	return T[i];
}
//---------------------------------------------------------------------------
int_T IVector::Size(void)
{
	return D;
}
//---------------------------------------------------------------------------
int_T IVector::Length(void)
{
	return D;
}
//---------------------------------------------------------------------------
inline void IVector::Printf(char * Format)
{
	printf("[");
	for (int_T i=0;i<D;i++)
	{
		printf(Format,T[i]);
	}
	printf("]\n");
}
//---------------------------------------------------------------------------
#endif
