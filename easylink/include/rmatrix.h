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
#ifndef RMatrix_h
#define RMatrix_h
//---------------------------------------------------------------------------
#include "rvector.h"
//---------------------------------------------------------------------------
/** \ingroup BasicClass
 *
 *  A real matrix class.
 *
 * M[i][j] and M(i,j) refers to the element of the line i
 * and the column j (reading and writing).
 */
class RMatrix : public RVector
{
protected:

    /// number of lines
	int_T L;
    /// number of columns
	int_T C;
	/// Useful for operator[] member function where we need to use a RVector without constructing it
    RVector ExportRVector;

public:

	// Constructors and affiliated methods ----------------------------------

    /** Construct a RMatrix and allocate a memory space for data. 
	* The RMatrix is not shared. 
    * \param NbL number of lines
    * \param NbC number of columns */
	inline RMatrix(int_T NbL,int_T NbC);

    /** Construct a RMatrix using an existing array. 
	* Copy the address. This RMatrix is shared.
    * \param NbL number of lines
    * \param NbC number of columns
	* \param t address of raw datas */
	inline RMatrix(int_T NbL,int_T NbC,real_T *t);

    /** Copy constructor. The RMatrix is not shared.
    * \param M the RMatrix to copy */
	inline RMatrix(const RMatrix &M);

    /** Dummy constructor. 
    * Construct a matrix whose size is 0 lines and 0 columns and which points on NULL*/
    inline RMatrix(void);
 	
    /** Empty the RMatrix and allocate a memory space for data. 
	* The RMatrix is not shared. 
    * \param NbL number of lines
    * \param NbC number of columns
    * \see RMatrix(int_T NbL,int_T NbC) which do the same job as constructor */
    inline void SetRMatrix(int_T NbL,int_T NbC);
 
    /** Empty the RMatrix and use an existing array. 
	* Copy the address. This RMatrix is shared.
    * \param NbL number of lines
    * \param NbC number of columns
	* \param t address of raw datas
    * \see RMatrix(int_T NbL,int_T NbC,real_T *t) which do the same job as constructor */
    inline void SetRMatrix(int_T NbL,int_T NbC,real_T *t);

	/** Reshaped to a new size with the same elements 
    * \param NbL number of lines
    * \param NbC number of columns
	*
	* NbL*NbC must equal the RMatrix number of elements. */
	inline void Reshape(int_T NbL,int_T NbC);	

	// Destructor and affiliated methods ------------------------------------

    /** Empty the RMatrix. Free the memory if not shared.*/
    inline void Empty(void);
	
    // Sharing methods ------------------------------------------------------

    /** Empty the RMatrix and use the same data as another RMatrix. The RMatrix is shared.
    * \param V the source RMatrix */
    inline void ShareArray(const RMatrix & M);

	// Operator = -----------------------------------------------------------

    /** Affectation
    *
    * Impossible if the RMatrix is shared and sizes don't match. */
    inline void operator=(const RMatrix &M);

	// Matrix-Vector operation ----------------------------------------------
	
	/** Matrix-vector product */
	inline RVector operator*(const RVector & V);
	
	// Matrix-Matrix operation ----------------------------------------------

	/** Matrix-matrix addition */
	inline RMatrix operator+(const RMatrix & B);

	/** Matrix-matrix substraction */
	inline RMatrix operator-(const RMatrix & B);

	/** Matrix-matrix product (dummy algorithm! don't use for big matrix). */
	inline RMatrix operator*(RMatrix & B);

	// Read/write methods -------------------------------------------------------

    /** Access to the element of the line i */
	inline RVector & operator[](int_T i);

    /** Access to the element of the line l and of the column c */
	inline real_T & operator()(int_T l,int_T c);

	// Size methods ------------------------------------------------

	/** Return the number of lines of the matrix */
	inline int_T NbL(void);

    /** Return the number of columns of the matrix */
	inline int_T NbC(void);

	// Input/output methods -------------------------------------------------
	
	/** Print the matrix in the console window 
	* \param Format typesetting of elements */
	inline void Printf(char * Format="  %4.3e");

};

/** Vector-Matrix product */
inline RVector operator*(RVector & V, RMatrix & M);

/** Kronecker product for vector  (dummy algorithm! don't use for big matrix).*/
inline RMatrix KProd(RVector & V, RVector & U);

/** Identity matrix */
inline RMatrix Eye(int_T NbL);

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
inline RMatrix::RMatrix(int_T NbL,int_T NbC):RVector(NbL*NbC)
{
	L=NbL;
	C=NbC;
}
//---------------------------------------------------------------------------
inline RMatrix::RMatrix():RVector()
{
	L=0;
	C=0;
}
//---------------------------------------------------------------------------
inline RMatrix::RMatrix(int_T NbL,int_T NbC,real_T *t):RVector(NbL*NbC,t)
{
	L=NbL;
	C=NbC;
}

//---------------------------------------------------------------------------
inline RMatrix::RMatrix(const RMatrix &M):RVector(M)
{
	L=M.L;
	C=M.C;
}
//---------------------------------------------------------------------------
inline void RMatrix::Empty(void)
{
	RVector::Empty();
    L=0;
    C=0;
}
//---------------------------------------------------------------------------
inline void RMatrix::ShareArray(const RMatrix & M)
{
	RVector::ShareArray(M);
	L=M.L;
	C=M.C;
}
//---------------------------------------------------------------------------
inline void RMatrix::SetRMatrix(int_T NbL,int_T NbC)
{
	RVector::SetRVector(NbL*NbC);
    L=NbL;
	C=NbC;
}
//---------------------------------------------------------------------------
inline void RMatrix::SetRMatrix(int_T NbL,int_T NbC,real_T *t)
{
	RVector::SetRVector(NbL*NbC,t);
    L=NbL;
	C=NbC;
}
//---------------------------------------------------------------------------
inline void RMatrix::Reshape(int_T NbL,int_T NbC)
{
	if (NbL*NbC!=L*C)
	{
		sprintf(ERROR_MSG_BUFFER,"EasyLink error: unable to reshape a %ix%i RMatrix to %ix%ix.\n",L,C,NbL,NbC);
		mexErrMsgTxt(ERROR_MSG_BUFFER);
	}
	else
	{
		L=NbL;
		C=NbC;
	}
}
//---------------------------------------------------------------------------
inline void RMatrix::operator=(const RMatrix &M)
{
	RVector::operator=(M);
	L=M.L;
	C=M.C;
}
//---------------------------------------------------------------------------
inline RVector RMatrix::operator*(const RVector & V)
{
	RVector R(L);
	if (C!=V.D)
	{
		sprintf(ERROR_MSG_BUFFER,"EasyLink error: Unable to do the product between a %ix%i RMatrix with a %i RVector.\n",L,C,V.D);
		mexErrMsgTxt(ERROR_MSG_BUFFER);
	}
	else
	{
		
		int_T   i=C,j=L;
		real_T* P=T;
		real_T* S=V.T;
		real_T* Q=R.T;
		
		for (;j--;Q++,S=V.T,i=C)
		{
			*Q=0;
			for (;i--;P++,S++)
				(*Q)+=(*P)*(*S);
		}
	}
	return R;
}
//---------------------------------------------------------------------------
inline RMatrix RMatrix::operator+(const RMatrix & B) // improvable
{
	RMatrix		matrix(L,C);
	int_T i;
	if ((L!=B.L)||(C!=B.C))
	{
		sprintf(ERROR_MSG_BUFFER,"EasyLink error: Unable to sum a %ix%i RMatrix with a %ix%i RMatrix.\n",L,C,B.L,B.C);
		mexErrMsgTxt(ERROR_MSG_BUFFER);
	}
	else
	{
		for(i=0; i<D; i++)
			matrix.T[i] = T[i] + B.T[i];
	}
	return matrix;
}
//---------------------------------------------------------------------------
inline RMatrix RMatrix::operator-(const RMatrix & B) // improvable
{
	RMatrix		matrix(L,C);
	int_T i;
	if ((L!=B.L)||(C!=B.C))
	{
		sprintf(ERROR_MSG_BUFFER,"EasyLink error: Unable to substract a %ix%i RMatrix with a %ix%i RMatrix.\n",L,C,B.L,B.C);
		mexErrMsgTxt(ERROR_MSG_BUFFER);
	}
	else
	{
		for(i=0; i<D; i++)
			matrix.T[i] = T[i] - B.T[i];
	}
	return matrix;
}
//---------------------------------------------------------------------------
inline RMatrix RMatrix::operator*(RMatrix & B) 
{
	int_T		N = L;
	int_T		M = C;
	int_T		P = B.C;
	RMatrix		matrix(N,P);
	int_T		i,j,k;

	if (C!=B.L)
	{
		sprintf(ERROR_MSG_BUFFER,"EasyLink error: Unable to do the dot product of a RMatrix with %i rows with a RMatrix with %i lines.\n",C,B.L);
		mexErrMsgTxt(ERROR_MSG_BUFFER);
	}
	else
	{
		for(i=0; i<N; i++)
		{	for (j=0; j<P; j++)
			matrix[i][j] = 0;
		}

		for(i=0; i<N; i++)
		{	for (j=0; j<P; j++)
			{	for (k=0; k<M; k++)
				matrix[i][j] = (*this)[i][k] * B[k][j] + matrix[i][j];
			}
		}
	}
	return matrix;
}
//---------------------------------------------------------------------------
inline RVector & RMatrix::operator[](int_T i)
{
    if ((i<0)||(i>=L))
	{
		sprintf(ERROR_MSG_BUFFER,"EasyLink error: RMatrix index overflow ! %i inferior to 0 or superior to %i.\n",i,L-1);
		mexErrMsgTxt(ERROR_MSG_BUFFER);
	}
	else
	{
	    ExportRVector.T=T+i*C;
		ExportRVector.D=C;
	}
	ExportRVector.Shared=true;
	return ExportRVector;
}
//---------------------------------------------------------------------------
inline real_T & RMatrix::operator()(int_T l,int_T c)
{
	if ((l<0)||(l>=L))
	{
		sprintf(ERROR_MSG_BUFFER,"EasyLink error: RMatrix index overflow ! %i inferior to 0 or superior to %i.\n",l,L-1);
		mexErrMsgTxt(ERROR_MSG_BUFFER);
	}
	if ((c<0)||(c>=C))
	{
		sprintf(ERROR_MSG_BUFFER,"EasyLink error: RMatrix index overflow ! %i inferior to 0 or superior to %i.\n",c,C-1);
		mexErrMsgTxt(ERROR_MSG_BUFFER);
	}
	return *(T+l*C+c);
}
//---------------------------------------------------------------------------
inline int_T RMatrix::NbL(void)
{
	return L;
}
//---------------------------------------------------------------------------
inline int_T RMatrix::NbC(void)
{
	return C;
}
//---------------------------------------------------------------------------
inline void RMatrix::Printf(char * Format)
{
	printf("[");
	for (int_T i=0;i<D-1;i++)
	{
		printf(Format,T[i]);
		if (i%C==C-1)
			printf("\n ");
	}
	printf(Format,T[D-1]);
	printf("]\n");
}
//---------------------------------------------------------------------------
inline RVector operator*(RVector & V, RMatrix & M)// improvable
{
	RVector		vect(M.NbC());

	int_T		i,j;

	if (V.Size()!=M.NbL())
	{
		sprintf(ERROR_MSG_BUFFER,"EasyLink error: Unable to do the product of a RVector of size %i with a RMatrix with %i lines.\n",V.Size(),M.NbL());
		mexErrMsgTxt(ERROR_MSG_BUFFER);
	}
	else
	{	
		for(i=0; i<M.NbC(); i++)
			vect[i] = 0;
		for(i=0; i<M.NbC(); i++)
		{	for (j=0; j<V.Size(); j++)
			vect[i] = V[j] * M[j][i] + vect[i];
		}
	}
	return vect;
}
//---------------------------------------------------------------------------
inline RMatrix KProd(RVector & V, RVector & U)// improvable
{
	RMatrix		mat(V.Size(),U.Size());
	int_T		i,j;
	
	for(i=0; i<V.Size(); i++)
	{	for (j=0; j<U.Size(); j++)
			mat[i][j] = V[i] * U[j];
	}

	return mat;
}
//---------------------------------------------------------------------------
inline RMatrix Eye(int_T NbL)
{
	RMatrix	mat(NbL,NbL);
	int_T	i;
	
	mat.Init(0);
	for(i=0; i<NbL; i++)
	{	mat[i][i] = 1;
	}

	return mat;
}
//---------------------------------------------------------------------------
#endif
