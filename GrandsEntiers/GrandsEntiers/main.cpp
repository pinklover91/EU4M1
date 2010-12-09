#include "GrandsEntiers.h"
#include "globals.h"

int main(){
	bint a = bint_creerVide();
	bint b = bint_creerVide();

	bint_assigner(a, 5);
	bint_assigner(b, 647);

	bint_pow(a, b);
	bint_info(a);

	cout << endl; attendeEcran();
	return 0;
}

//#pragma warning( disable : 4996 )		// evite la depreciation de la fonction strcpy
//#pragma warning( error : 4706 )			// signale une erreur pour l'affectation dans une expression conditionnelle (= au lieu de =)
//#pragma warning( error : 4700 )			// signale une erreur pour variable non initialise