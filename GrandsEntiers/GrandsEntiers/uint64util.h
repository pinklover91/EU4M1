#ifndef uint64util_h
#define uint64util_h

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <sstream>

using namespace std;

// NOTE : uint64 == unsigned long long

// obtenir un bit du uint64
bool uint64GetBit(unsigned long long N, unsigned char bit);

// convertir uint64 a string
string uint64ToBinStr(unsigned long long n);

// convertir uint64 a une string decimal
string uint64ToDecimal(unsigned long long n);

// obtenir a uin64 aleatoire
unsigned long long uint64Rnd(unsigned long long min, unsigned long long max);

// valeur maximum du uint64
const unsigned long long uint64MaxValue = 18446744073709551615;

#endif