#include "uint64util.h"

bool uint64GetBit(unsigned long long N, unsigned char bit){
	return (N>>bit)&1 == 1;
}

string uint64ToBinStr(unsigned long long n){
	string s = "";
	for(int i=63; i >=0; i--) {
		if(uint64GetBit(n, i)) s+="1";
		else s+="0";
	}
	return s;
}

string uint64ToDecimal(unsigned long long n){
	stringstream ss;
	ss << n;
	return ss.str();
}

unsigned long long uint64Rnd(unsigned long long min, unsigned long long max){
	return (unsigned long long)((max - min) * rand()/(float)RAND_MAX + min);
}
