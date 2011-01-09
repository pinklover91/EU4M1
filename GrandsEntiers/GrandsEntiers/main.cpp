#include "bint.h"
#include "uint64util.h"
#include "globals.h"
#include "etoile.h"
#include "galaxie.h"

int main(){
	/*
	TESTING BINT

	bint a = bint_creerVide();
	bint b = bint_creerVide();

	bint_assigner(a, 5);
	bint_assigner(b, 647);

	bint_pow(a, b);
	bint_info(a);*/

	//-------------

	/*
	TESTING STARS

	cout << endl << endl;
	etoile e1 = etoile_demander();
	etoile_info(e1);
	
	cout << endl; attendeEcran();
	*/

	//etoile plus proche au centre du galaxie
	collEtoiles plusProcheEtoile = collEtoiles_creerVide();
	etoile nouveauEtoile;
	unsigned long int q=0;
	bool finProg=false;
	char choix;
	while(!finProg){
		effacerEcran();
		afficherMenu();
		cin >> choix;
		effacerEcran();
		switch(choix){
			case '0':
			case 'x':
			case 'X':
				finProg=true;
				break;
			case '1':
				// Obtenir info galaxie
				collEtoiles_afficherInfo(plusProcheEtoile);
				attendeEcran();
				break;
			case '2':
				// Afficher toutes les toiles
				cout << "TOUTES LES ETOILES (distance au centre galaxie croissant) :" << endl <<endl;
				collEtoiles_afficherToutes(plusProcheEtoile);
				attendeEcran();
				break;
			case '3':
				// Afficher info etoile
				cout << "Choisir etoile ID pour afficher : " ;
				cin >> q;
				effacerEcran();
				if(q>=0 && q<collEtoiles_quantiteEtoiles(plusProcheEtoile)){
					cout << "Etoile #" << q << endl << endl;
					etoile_info(collEtoiles_getEtoile(plusProcheEtoile, q));
					attendeEcran();
				} else {
					cout << "L'etoile #" << q << " n'exite pas" << endl;
					attendeEcran();
				}
				break;
			case '4':
				// Ajouter une etoile aleatoire
				nouveauEtoile = etoile_creerRnd();
				cout << "Etoile cree :" << endl;
				etoile_info(nouveauEtoile);
				collEtoiles_ajouterEtoile(plusProcheEtoile, nouveauEtoile);
				cout << endl;
				collEtoiles_afficherQuantEtoiles(plusProcheEtoile);
				attendeEcran();
				break;
			case '5':
				// Ajouter une etoile definie
				nouveauEtoile = etoile_demander();
				collEtoiles_ajouterEtoile(plusProcheEtoile, nouveauEtoile);
				cout << endl << "Nouveau etoile ajoutee" << endl << endl;
				collEtoiles_afficherQuantEtoiles(plusProcheEtoile);
				attendeEcran();
				break;
			case '6':
				// Ajouter X etoiles aleatoires
				cout << "Quantite d'etoiles a ajouter : ";
				cin >> q;
				for(unsigned long int i=1; i<=q; i++) {
					cout << "Attende pour la creation d'etoile #" << i << "..." << endl;
					nouveauEtoile = etoile_creerRnd();
					collEtoiles_ajouterEtoile(plusProcheEtoile, nouveauEtoile);
				}
				cout << endl;
				collEtoiles_afficherQuantEtoiles(plusProcheEtoile);
				attendeEcran();
				break;
			case '7':
				// Supprimer une etoile
				cout << "Choisir etoile ID pour supprimer : " ;
				cin >> q;
				effacerEcran();
				if(q>=0 && q<collEtoiles_quantiteEtoiles(plusProcheEtoile)){
					collEtoiles_afficherQuantEtoiles(plusProcheEtoile);
					cout << "Eliminant etoile #" << q << "..." << endl;
					collEtoiles_supprimerEtoile(plusProcheEtoile, q);
					collEtoiles_afficherQuantEtoiles(plusProcheEtoile);
					attendeEcran();
				} else {
					cout << "L'etoile #" << q << " n'exite pas" << endl;
					attendeEcran();
				}
				break;
			default:
				cout << " ERREUR DE SAISIE !!!" << endl ;
				break;
		}
	}

	return 0;
}

//#pragma warning( disable : 4996 )		// evite la depreciation de la fonction strcpy
//#pragma warning( error : 4706 )			// signale une erreur pour l'affectation dans une expression conditionnelle (= au lieu de =)
//#pragma warning( error : 4700 )			// signale une erreur pour variable non initialise