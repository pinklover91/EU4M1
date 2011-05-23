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
#ifndef RVector_h
#define RVector_h
//---------------------------------------------------------------------------
#include "easylink.h"
#include "ivector.h"
//---------------------------------------------------------------------------
/** \ingroup BasicClass
 *
 * A real vector class
 *
 */
class RVector
{
protected:

    /// vector size
	int_T D;
    /// pointer on real elements
	real_T *T;
    /// Is the vector shared ? (yes if the vector arises from Matlab)
    bool Shared;

public:

	// Constructors and affiliated methods ----------------------------------

    /** Construct a RVector and allocate a memory space for data. 
	* The RVector is not shared. 
    * \param dim the number of element */
    inline RVector(int_T dim);

    /** Construct a RVector using an existing array. 
	* Copy the address. This RVector is shared.
    * \param dim the number of element
    * \param t address of raw datas */
	inline RVector(int_T dim,real_T *t);

    /** Copy constructor. The RVector is not shared.
    * \param V the RVector to copy*/
	inline RVector(const RVector &V);

    /** Copy constructor from IVector. The RVector is not shared.
    * \param V the IVector to copy*/
	inline RVector(IVector &V);

    /** Dummy constructor. 
	* Construct a RVector whose size is 0 and which points on NULL */
    inline RVector(void);

    /** Empty the RVector and allocate a memory space for data. 
	* The RVector is not shared. 
    * \param dim the number of element
    * \see RVector(int_T dim) which do the same job as constructor */
    inline void SetRVector(int_T dim);

    /** Empty the RVector and use an existing array. 
	* Copy the address. This RVector is shared.
    * \param dim the number of element
    * \param t address of raw datas
    * \see RVector(int_T dim,real_T *t) which do the same job as constructor */
    inline void SetRVector(int_T dim,real_T *t);
	
	// Destructor and affiliated methods ------------------------------------
	
	/** Empty the RVector. Free the memory if not shared.
	* 	\see Empty() method. */
	inline ~RVector(void);

    /** Empty the RVector. Free the memory if not shared. */
    inline void Empty(void);

    // Sharing methods ------------------------------------------------------

    /** Empty the RVector and use the same data as another RVector. The RVector is shared.
    * \param V the source RVector */
    inline void ShareArray(const RVector & V);
	
	/** Return true if the vector is shared, false if not. 
	* \return the state of vector */
    inline bool GetShared(void);

    /** Return the address of the data. 
	* \return the address of raw datas */
    inline real_T* GetArrayAddress(void);

	// Operator = and initialization methods -------------------------------
    
    /** Affectation
    *
    * Impossible if the RVector is shared and sizes don't match. */
	inline void operator=(const RVector &V);
	
	/** Initialization of all elements at the same value
    * \param x real value */
	inline void Init(real_T x);
	
	// Vector-Real operation ------------------------------------------------
	
	/** Add x to all elements of the RVector
    * \param x real value */
	inline void operator+=(real_T x);

	/** Substract x to all elements of the RVector
    * \param x real value */
	inline void operator-=(real_T x);

	/** Multiply all elements of the RVector by x
    * \param x real value */
	inline void operator*=(real_T x);

	/** Divide all elements of the RVector by x
    * \param x real value */
	inline void operator/=(real_T x);
	
	/** Vector-Real addition */
	inline RVector operator+(real_T x);
	
	/** Vector-Real subtraction */
	inline RVector operator-(real_T x);
	
	/** Vector-Real product */
	inline RVector operator*(real_T x);

	/** Vector-Real division */
	inline RVector operator/(real_T x);
	
	// Vector-Vector operation ----------------------------------------------

	/** All elements are added by the corresponding elements of V */
	inline void operator+=(const RVector & V);

	/** All elements are substracted by the corresponding elements of V */
	inline void operator-=(const RVector & V);

	/** All elements are multiplied by the corresponding elements of V */
	inline void operator*=(const RVector & V);

	/** All elements are divided by the corresponding elements of V */
	inline void operator/=(const RVector & V);

	/** Dot product */
	inline real_T operator*(const RVector & V);

	/** Vector-Vector addition */
	inline RVector operator+(const RVector & V);

	/** Vector-Vector substraction */
	inline RVector operator-(const RVector & V);
	
	// Comparison methods ---------------------------------------------------
	
	/** Compare two vectors*/
	inline bool operator==(const RVector &V);
	
    /** Return true if at least one element of the vector is equal to
	\param x real value */
	bool Include(real_T x);
	
	// Read/write methods -------------------------------------------------------
	
	/** Access to the element i */
	inline real_T & operator[](int_T i);

    /** Access to the element i */
	inline real_T & operator()(int_T i);

	// Min/Max methods ------------------------------------------------------
	
	/** Return the max value of the vector */
	inline real_T Max(void);

	/** Return the min value of the vector */
	inline real_T Min(void);

    /** Return a int vector with positions of max values of *this between [0; N-1]*/
	inline IVector ArgMax(void); 

    /** Return a int vector with positions of min values of *this between [0; N-1]*/
	inline IVector ArgMin(void); 

	/** Return the position of the first max value of the vector */
	inline int_T FirstArgMax(void);

	/** Return the position of the first max value of the vector */
	inline int_T FirstArgMin(void);

	// Norm and size methods ------------------------------------------------
	
	/** Return vector size as an integer */
	inline int_T Size(void);

	/** Return vector size as an integer (same as Size) */
	inline int_T Length(void);

	/** Return the Manhattan norm */
    inline real_T Norm1();

	/** Return the Euclidean norm */
    inline real_T Norm2();

	// Output methods -------------------------------------------------
	
	/** Print the RVector elements in the console window 
	* \param Format typesetting of elements */
	inline void Printf(char * Format="  %4.3e");
	
	// ----------------------------------------------------------------

	friend class RMatrix;
    
};

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
inline RVector::RVector(int_T dim)
{
	D=dim;
	T=new real_T[D];
	Shared=false;
}
//---------------------------------------------------------------------------
inline RVector::RVector(void)
{
	D=0;
	T=NULL;
	Shared=false;
}
//---------------------------------------------------------------------------
inline RVector::RVector(int_T dim,real_T *t)
{
    D=dim;
	T=t;
	Shared=true;
}

//---------------------------------------------------------------------------
inline RVector::RVector(const RVector &V)
{
	D=V.D;
	T=new real_T[D];

	memcpy((void*)T,(void*)V.T, D*sizeof(real_T) );

	Shared=false;
}
//---------------------------------------------------------------------------
inline RVector::RVector(IVector &V)
{
	D=V.Size();
	T=new real_T[D];
	for (int_T i=0;i<D;i++)
		T[i]=V[i];
	Shared=false;
}
//---------------------------------------------------------------------------
inline void RVector::Empty(void)
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
inline RVector::~RVector(void)
{
    Empty();
}
//---------------------------------------------------------------------------
inline void RVector::ShareArray(const RVector & V)
{
    Empty();
	Shared=true;
	D=V.D;
	T=V.T;
}
//---------------------------------------------------------------------------
inline void RVector::SetRVector(int_T dim)
{
	Empty();
	D=dim;
	T=new real_T[D];
}
//---------------------------------------------------------------------------
inline void RVector::SetRVector(int_T dim,real_T *t)
{
	Empty();
	D=dim;
	T=t;
	Shared=true;
}
//---------------------------------------------------------------------------
inline bool RVector::GetShared(void)
{
    return Shared;
}
//---------------------------------------------------------------------------
inline void RVector::operator=(const RVector &V)
{
	if (D==V.D)
		memcpy((void*)T,(void*)V.T, D*sizeof(real_T) );
	else
    {
	  if (!Shared)
      {
		Empty();
		D=V.D;
	    T=new real_T[D];
		memcpy((void*)T,(void*)V.T, D*sizeof(real_T) );
      }
      else
	  {
		sprintf(ERROR_MSG_BUFFER,"EasyLink error: Unable to affect a %i RVector to a shared %i RVector.\n",V.D,D);
		mexErrMsgTxt(ERROR_MSG_BUFFER);
	  }


    }
}
//---------------------------------------------------------------------------
inline real_T* RVector::GetArrayAddress(void)
{
    return T;
}
//---------------------------------------------------------------------------
inline void RVector::Init(real_T x)
{
	int_T i=D;
	real_T* P=T;
	for (;i--;P++)
		*P=x;
}
//---------------------------------------------------------------------------
inline void RVector::operator+=(real_T x)
{
	int_T i=D;
	real_T* P=T;
	for (;i--;P++)
		*P+=x;
}
//---------------------------------------------------------------------------
inline void RVector::operator-=(real_T x)
{
	int_T i=D;
	real_T* P=T;
	for (;i--;P++)
		*P-=x;
}
//---------------------------------------------------------------------------
inline void RVector::operator*=(real_T x)
{
	int_T i=D;
	real_T* P=T;
	for (;i--;P++)
		*P*=x;
}
//---------------------------------------------------------------------------
inline void RVector::operator/=(real_T x)
{
	int_T i=D;
	real_T* P=T;
	for (;i--;P++)
		*P/=x;
}
//---------------------------------------------------------------------------
inline void RVector::operator+=(const RVector & V)
{
    if (D!=V.D)
	{
		sprintf(ERROR_MSG_BUFFER,"EasyLink error: Unable to add a RVector of size %i to a RVector of size %i.\n",V.D,D);
		mexErrMsgTxt(ERROR_MSG_BUFFER);
	}
	else
	{
		int_T   i=D;
		real_T* P=T;
		real_T* S=V.T;
		for (;i--;P++,S++)
			*P+=(*S);
	}
}
//---------------------------------------------------------------------------
inline void RVector::operator-=(const RVector & V)
{
    if (D!=V.D)
	{
		sprintf(ERROR_MSG_BUFFER,"EasyLink error: Unable to substract a RVector of size %i to a RVector of size %i.\n",V.D,D);
		mexErrMsgTxt(ERROR_MSG_BUFFER);
	}
	else
	{
		int_T   i=D;
		real_T* P=T;
		real_T* S=V.T;
		for (;i--;P++,S++)
			*P-=(*S);
	}
}
//---------------------------------------------------------------------------
inline void RVector::operator*=(const RVector & V)
{
    if (D!=V.D)
	{
		sprintf(ERROR_MSG_BUFFER,"EasyLink error: Unable to multiply a RVector of size %i to a RVector of size %i.\n",V.D,D);
		mexErrMsgTxt(ERROR_MSG_BUFFER);
	}
	else
	{
		int_T   i=D;
		real_T* P=T;
		real_T* S=V.T;
		for (;i--;P++,S++)
			*P*=(*S);
	}
}
//---------------------------------------------------------------------------
inline void RVector::operator/=(const RVector & V)
{
    if (D!=V.D)
	{
		sprintf(ERROR_MSG_BUFFER,"EasyLink error: Unable to divide a RVector of size %i to a RVector of size %i.\n",V.D,D);
		mexErrMsgTxt(ERROR_MSG_BUFFER);
	}
	else
	{
		int_T   i=D;
		real_T* P=T;
		real_T* S=V.T;
		for (;i--;P++,S++)
			*P/=(*S);
	}
}
//---------------------------------------------------------------------------
inline real_T RVector::operator*(const RVector & V)
{
    real_T  R=0;
	if (D!=V.D)
	{
		sprintf(ERROR_MSG_BUFFER,"EasyLink error: Unable to do the dot product of a RVector of size %i with a RVector of size %i.\n",V.D,D);
		mexErrMsgTxt(ERROR_MSG_BUFFER);
	}
	else
	{	
		int_T   i=D;
		real_T* P=T;
		real_T* S=V.T;
		
		for (;i--;P++,S++)
			R+=(*P)*(*S);
	}
	return R;
}
//---------------------------------------------------------------------------
inline RVector RVector::operator+(const RVector & V) // improvable
{
	RVector		result(D);
	int_T		i;
	
	if (D!=V.D)
	{
		sprintf(ERROR_MSG_BUFFER,"EasyLink error: Unable to add a RVector of size %i to a RVector of size %i.\n",V.D,D);
		mexErrMsgTxt(ERROR_MSG_BUFFER);
	}
	else
	{	
		for(i=0; i<D; i++)
			result[i] = T[i] + V.T[i];
	}
	return result;
}
//---------------------------------------------------------------------------
inline RVector RVector::operator-(const RVector & V) // improvable
{
	RVector		result(D);
	int_T		i;
	
	if (D!=V.D)
	{
		sprintf(ERROR_MSG_BUFFER,"EasyLink error: Unable to substract a RVector of size %i to a RVector of size %i.\n",V.D,D);
		mexErrMsgTxt(ERROR_MSG_BUFFER);
	}
	else
	{	
		for(i=0; i<D; i++)
			result[i] = T[i] - V.T[i];
	}
	return result;
}
//---------------------------------------------------------------------------
inline RVector RVector::operator+(real_T x)
{
	RVector result(*this);
	result+=x;
	return result;
}
//---------------------------------------------------------------------------
inline RVector RVector::operator-(real_T x)
{
	RVector result(*this);
	result-=x;
	return result;
}
//---------------------------------------------------------------------------
inline RVector RVector::operator*(real_T x)
{
	RVector result(*this);
	result*=x;
	return result;
}
//---------------------------------------------------------------------------
inline RVector RVector::operator/(real_T x)
{
	RVector result(*this);
	result/=x;
	return result;
}
//---------------------------------------------------------------------------
inline bool RVector::operator==(const RVector &V)  // improvable
{
	int_T i=0;
	bool res;
	if (V.D==D)
	{
		while ((i<D)&&(EqualityReal(T[i],V.T[i]))) 
			i++;
		res=(i==D);
	}
	else
		res=false;
	return res;
}

//---------------------------------------------------------------------------
inline bool RVector::Include(real_T x)  // improvable
{	
	int_T i=0;
	bool res;
	
	while ((i<D)&&(!EqualityReal(T[i],x))) 
		i++;
	res=(i<D);
	return res;
}
//---------------------------------------------------------------------------
inline real_T & RVector::operator[](int_T i)
{
	if ((i<0)||(i>=D))
	{
		sprintf(ERROR_MSG_BUFFER,"EasyLink error: RVector index overflow ! %i inferior to 0 or superior to %i.\n",i,D-1);
		mexErrMsgTxt(ERROR_MSG_BUFFER);
	}
	return T[i];
}
//---------------------------------------------------------------------------
inline real_T & RVector::operator()(int_T i)
{
	if ((i<0)||(i>=D))
	{
		sprintf(ERROR_MSG_BUFFER,"EasyLink error: RVector index overflow ! %i inferior to 0 or superior to %i\n",i,D-1);
		mexErrMsgTxt(ERROR_MSG_BUFFER);
	}
	return T[i];
}
//---------------------------------------------------------------------------
inline int_T RVector::Size(void)
{
	return D;
}
//---------------------------------------------------------------------------
inline int_T RVector::Length(void)
{
	return D;
}
//---------------------------------------------------------------------------
inline real_T RVector::Max(void)  // improvable
{
	int_T i;
    real_T m=T[0];
	for (i=1; i<D; i++)
		if (T[i]>m)
			m=T[i];
	return m;
}
//---------------------------------------------------------------------------
inline real_T RVector::Min(void)  // improvable
{
	int_T i;
    real_T m=T[0];
	for (i=1; i<D; i++)
		if (T[i]<m)
			m=T[i];
	return m;
}
//---------------------------------------------------------------------------
inline IVector RVector::ArgMax(void)  // improvable
{
  	int_T max,i,nb;
 	int_T *Choix;
	Choix=new int_T[D];

  	max=0;
  	Choix[0]=0;
	nb=1;
	for (i=1;i<D;i++)
		if (EqualityReal(T[i],T[max]))
		{
        	Choix[nb]=i;
			nb++;
		}
      	else if (T[i]>T[max])
        {
        	Choix[0]=i;
			nb=1;
        	max=i;
        }
	IVector C(nb);
	for (int_T j=0;j<C.Size();j++)
		C[j]=Choix[j];

	delete [] Choix;
	return C;
}
//---------------------------------------------------------------------------
inline IVector RVector::ArgMin(void)  // improvable
{
  	int_T min,i,nb;
 	int_T *Choix;
	Choix=new int_T[D];

  	min=0;
  	Choix[0]=0;
	nb=1;
	for (i=1;i<D;i++)
		if (EqualityReal(T[i],T[min]))
		{
        	Choix[nb]=i;
			nb++;
		}
      	else if (T[i]<T[min])
        {
        	Choix[0]=i;
			nb=1;
        	min=i;
        }
	IVector C(nb);
	for (int_T j=0;j<C.Size();j++)
		C[j]=Choix[j];

	delete [] Choix;
	return C;
}
//---------------------------------------------------------------------------
inline int_T RVector::FirstArgMax(void)  // improvable
{
 	int_T i,imax;
	real_T max;
	
	max=T[0];
	imax=0;
	for (i=1;i<D;i++)
		if (T[i]>max)
		{
			max=T[i];
			imax=i;
		}
	
	return imax;
}
//---------------------------------------------------------------------------
inline int_T RVector::FirstArgMin(void)  // improvable
{
 	int_T i,imin;
	real_T min;
	
	min=T[0];
	imin=0;
	for (i=1;i<D;i++)
		if (T[i]>min)
		{
			min=T[i];
			imin=i;
		}
	
	return imin;
}
//---------------------------------------------------------------------------
inline real_T RVector::Norm1()  // improvable
{
   real_T n=0;
   for (int_T i=0;i<D;i++)
        n+=Abs(T[i]);
   return n;
}
//---------------------------------------------------------------------------
inline real_T RVector::Norm2()  // improvable
{
   real_T n=0;
   for (int_T i=0;i<D;i++)
        n+=T[i]*T[i];
   return sqrt(n);
}
//---------------------------------------------------------------------------
inline void RVector::Printf(char * Format)
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
