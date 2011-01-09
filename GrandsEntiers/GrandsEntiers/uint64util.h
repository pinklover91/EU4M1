#ifndef uint64util_h
#define uint64util_h

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <sstream>

using namespace std;

bool uint64GetBit(unsigned long long N, unsigned char bit);
string uint64ToBinStr(unsigned long long n);
string uint64ToDecimal(unsigned long long n);
unsigned long long uint64Rnd(unsigned long long min, unsigned long long max);
const unsigned long long uint64MaxValue = 18446744073709551615;

#endif