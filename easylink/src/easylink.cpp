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
#include "easylink.h" 
//---------------------------------------------------------------------------
// Mathematical errors management

extern int_T _matherr(struct _exception *e)
{
  const char *txt;

  switch (e->type)
  {
  case DOMAIN:
    txt = "Argument was not in domain of function, such as log(-1),";
    break;

  case SING:
    txt = "Argument would result in a singularity, such as pow(0, -2),";
    break;

  case OVERFLOW:
    txt = "Argument would produce a function result greater than DBL_MAX (or LDBL_MAX), such as exp(1000),";
    break;

  case UNDERFLOW:
    txt = "Argument would produce a function result less than DBL_MIN (or LDBL_MIN), such as exp(-1000),";
    break;

  case TLOSS:
    txt = "Argument would produce function result with total loss of significant digits, such as sin(10e70),";
    break;
    
  default: txt = "Unknown math error";
  }
  printf("EasyLink warning: (_matherr %i) %s in %s function.\n",e->type,txt,e->name);
  return 1;	
}
//---------------------------------------------------------------------------
