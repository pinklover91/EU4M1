#include "GrandsEntiers.h"

bint bint_creerVide(){
	const int origSize=3;
	bint n;
	n.b = new unsigned long long[origSize];
	n.nb=0;
	n.internal_nb=origSize;
	return n;
}

void bint_info(bint b){
	cout << endl;
	cout << "Longeur (bloques utilises): " << b.nb << endl;
	cout << "Longeur reel (array): " << b.internal_nb << endl;
	cout << "Indices n'utilises pas: ";
	for(int i=b.nb ; i<b.internal_nb ; i++) {
		cout << i;
		if(i!=b.internal_nb-1) cout << ", ";
	}
	for(int i=b.nb-1 ; i>=0 ; i--) cout << endl << "b[" << i << "] = " << b.b[i] << endl;
}

// bint b = bint_assigner(5);
void bint_assigner(bint &b, int n){
	//don't change its current size. Leave it like it is
	b.b[0]=n;
	b.nb=1;
}