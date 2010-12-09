#include "GrandsEntiers.h"

bint bint_creerVide(){
	const int origSize=1;
	bint n;
	n.b = new unsigned long long[origSize];
	n.nb=0;
	n.internal_nb=origSize;
	for(int i=0 ; i<n.internal_nb ; i++) n.b[i]=0; // init valeurs
	return n;
}

void bint_info(bint &b){
	cout << endl << endl;
	cout << "Longeur (bloques utilises) : " << b.nb << endl;
	cout << "Longeur reel (array) : " << b.internal_nb << endl;
	cout << "Indices n'utilises pas : ";
	for(int i=b.nb ; i<b.internal_nb ; i++) {
		cout << i;
		if(i!=b.internal_nb-1) cout << ", ";
	}
	cout << endl;
	for(int i=b.internal_nb-1 ; i>=0 ; i--) cout << "b[" << i << "] = " << b.b[i] << endl;
	cout << "Valeur binaire : " << endl << bint_getBin(b) << endl;
	cout << endl;
}

// bint b = bint_assigner(5);
void bint_assigner(bint &b, unsigned long long n){
	//don't change its current size. Leave it like it is
	b.b[0]=n;
	b.nb=1;
}

void bint_ajouter(bint &a, int b){
	if(b>0) bint_ajouter(a, (unsigned long long)b);
	//else if(b==0) return;
	else if (b<0) bint_sustraire(a, (unsigned long long)abs(b)); // si nombre negative, sustraire le valeur absolute
}

void bint_sustraire(bint &a, int b){
	if(b>0) bint_sustraire(a, (unsigned long long)b);
	else if(b<0) bint_ajouter(a, (unsigned long long)abs(b)); // si nombre negative, ajoute le valeur absolute
}

void bint_ajouter(bint &a, unsigned long long b){
	bint_ajouter(a, b, 0);
}

void bint_ajouter(bint &a, unsigned long long b, int pos){
	// si l'array interne est tres petit
	if(pos>a.internal_nb-1) bint_setLongInter(a, pos+1);

	unsigned long long antVal = a.b[pos];
	a.b[pos]+=b;

	// si la pos predec pas utilisee
	if(pos > ((signed long)a.nb)-1) a.nb=pos+1;

	// si surcharge/overload
	if(a.b[pos]<antVal) bint_ajouter(a, 1, pos+1);
}

void bint_sustraire(bint &a, unsigned long long b){
	cout << "NOT IMPLEMENTED: bint_sustraire" << endl;
	system("pause");
	exit(1);
}

// changer la longeur interieure de bint
void bint_setLongInter(bint &a, unsigned int L){
	unsigned long long *antArray = a.b;
	unsigned long long *nouvArray = new unsigned long long[L];
	for(unsigned int i=0 ; i<a.nb ; i++) {
		nouvArray[i]=antArray[i];
	}
	for(unsigned int i=a.nb ; i<L ; i++){
		nouvArray[i]=0;
	}
	a.internal_nb=L;
	delete a.b;
	a.b=nouvArray;
}

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

string bint_getBin(bint &b){
	string s = "";
	for(long i=b.nb-1; i>=0; i--) {
		s+=uint64ToBinStr(b.b[i]);
	}
	return s;
}