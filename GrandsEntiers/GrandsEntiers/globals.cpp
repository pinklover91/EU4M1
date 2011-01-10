#include "globals.h"

#include <stdlib.h>

void attendeEcran(){
	cout << endl << endl << endl << endl;
	system("pause");
}

void effacerEcran(void) {
	system("cls");
}

void afficherMenu() {
	cout << "0 Quitter le programme" << endl << endl ;

	cout << "1 Obtenir info galaxie" << endl ;
	cout << "2 Afficher toutes les etoiles" << endl;
	cout << "3 Afficher une etoile" << endl;

	cout << "4 Ajouter une etoile aleatoire" << endl ;
	cout << "5 Ajouter une etoile definie" << endl ;
	cout << "6 Ajouter X etoiles aleatoires" << endl;
	cout << "7 Supprimer une etoile" << endl;

	cout << endl << "Choix : " ;
}
