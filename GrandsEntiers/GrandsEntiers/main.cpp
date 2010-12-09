#include "GrandsEntiers.h"
#include "globals.h"

int main(){
	bint test = bint_creerVide();
	bint_info(test);
	bint_assigner(test, 53);
	bint_info(test);
	bint_setLongInter(test, 5);
	bint_info(test);

	cout << endl << "=====================" << endl;

	bint a = bint_creerVide();

	bint_info(a);

	bint_assigner(a, 18446744073709551615);
	bint_info(a);

	bint_ajouter(a, 1);
	bint_info(a);

	cout << endl; attendeEcran();
	return 0;
}

#pragma warning( disable : 4996 )		// evite la depreciation de la fonction strcpy
#pragma warning( error : 4706 )			// signale une erreur pour l'affectation dans une expression conditionnelle (= au lieu de =)
#pragma warning( error : 4700 )			// signale une erreur pour variable non initialise