#include "bint.h"

bint bint_creerVide(){
	const int origSize=1;
	bint n;
	n.b = new unsigned long long[origSize];
	n.nb=0;
	n.internal_nb=origSize;
	for(int i=0 ; i<n.internal_nb ; i++) n.b[i]=0; // init valeurs
	return n;
}

bint bint_creer(unsigned long long valeur){
	bint b = bint_creerVide();
	bint_ajouter(b, valeur);
	return b;
}

bint bint_copier(const bint &a){
	bint n;
	n.internal_nb=a.internal_nb;
	n.nb=a.nb;
	n.b = new unsigned long long[a.internal_nb];
	for(unsigned int i=0; i<n.internal_nb; i++){
		n.b[i]=a.b[i];
	}
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
	cout << "Bits : " << bint_compterBits(b) << endl;
	cout << "Valeur environ : " << bint_valEnviron(b) << endl;
	cout << "Valeur binaire : " << endl << bint_getBin(b) << endl;
	cout << endl;
}

// bint b=5 [invalid] === bint_assigner(b, 5) [valid]
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

void bint_ajouter(bint &a, const bint &b){
	for(unsigned int i=0; i<b.nb; i++){
		bint_ajouter(a, b.b[i], i);
	}
}

void bint_sustraire(bint &a, unsigned long long b){
	bint_sustraire(a, b, 0);
}

void bint_sustraire(bint &a, unsigned long long b, int pos){
	unsigned long long andVal=a.b[pos];
	a.b[pos]-=b;

	// nombres negatives
	if(a.nb==1 && pos==0 && b>a.b[pos]) throw "bint underload";

	// underload
	if(a.b[pos]>andVal) bint_sustraire(a, 1, pos+1);

	while(a.b[a.nb-1]==0) a.nb--;
}

void bint_multiplier(bint &a, unsigned int b){
	if(b==0) bint_assigner(a, 0);
	else {
		bint orig = bint_copier(a);
		for(unsigned int i=0; i<b-1; i++) {
			bint_ajouter(a, orig);
		}
	}
}

void bint_multiplier(bint &a, const bint &b){
	if(bint_egal(b, 0)) bint_assigner(a, 0);
	else {
		bint orig = bint_copier(a);
		for(bint temp = bint_copier(b); bint_plusGrandQue(temp, 1); bint_sustraire(temp, 1)){
			bint_ajouter(a, orig);
		}
	}
}

void bint_pow(bint &base, unsigned long long exp){
	bint exp2 = bint_creerVide();
	bint_assigner(exp2, exp);
	return bint_pow(base, exp2);
}

void bint_pow(bint &base, const bint &exp){
	// base^0=1
	if(bint_egal(exp, 0)) bint_assigner(base, 1);

	// base^1=base
	else if(bint_egal(exp, 1)) return;

	else {
		bint orig = bint_copier(base);
		for(bint temp = bint_copier(exp); bint_plusGrandQue(temp, 1); bint_sustraire(temp, 1)){
			bint_multiplier(base, orig);
		}
	}
}

bool bint_estVide(const bint &a){
	if(a.nb==0 || (a.nb==1 && a.b[0]==0)) return true;
	else return false;
}

bool bint_plusGrandQue(const bint &a, unsigned long long b){
	bint c = bint_creerVide();
	bint_assigner(c, b);
	return bint_plusGrandQue(a, c);
}

bool bint_plusGrandQue(const bint &a, const bint &b){
	if(a.nb>b.nb) return true;
	if(a.nb<b.nb) return false;

	//a.nb == b.nb :
	for(long i=a.nb-1; i>=0; i--) {
		if(a.b[i]>b.b[i]) return true;
	}
	return false;
}

bool bint_egal(const bint &a, unsigned long long b){
	if(a.nb==1 && a.b[0]==b) return true;
	else return false;
}


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

string bint_getBin(bint &b){
	string s = "";
	for(long i=b.nb-1; i>=0; i--) {
		s+=uint64ToBinStr(b.b[i]);
	}
	return s;
}

unsigned long long bint_compterBits(bint &b){
	unsigned long long bits = b.nb * sizeof(unsigned long long) * 8;
	for(int i=sizeof(unsigned long long) * 8 - 1 ; i>=0 ; i--){
		if(uint64GetBit(b.b[b.nb-1], i) == false) bits--;
		else break;
	}
	return bits;
}

string bint_valEnviron(bint &b){
	unsigned long long bits = bint_compterBits(b);
	string s = "entre 2^"+uint64ToDecimal(bits-1)+" et (2^"+uint64ToDecimal(bits)+")-1";
	return s;
}

string bint_toString(bint &b){
	string s="";
	if(b.nb==0) s="0";
	else if(b.nb==1) s=uint64ToDecimal(b.b[0]);
	else s=bint_valEnviron(b);
	return s;
}