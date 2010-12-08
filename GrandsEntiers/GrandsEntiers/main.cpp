#include "GrandsEntiers.h"
#include "globals.h"

int main(){
	bint a = bint_creerVide();
	bint_info(a);
	cout << endl;
	bint_assigner(a, 78);
	bint_info(a);

	cout << endl; attendeEcran();
	return 0;
}

#pragma warning( disable : 4996 )		// evite la depreciation de la fonction strcpy
#pragma warning( error : 4706 )			// signale une erreur pour l'affectation dans une expression conditionnelle (= au lieu de =)
#pragma warning( error : 4700 )			// signale une erreur pour variable non initialise