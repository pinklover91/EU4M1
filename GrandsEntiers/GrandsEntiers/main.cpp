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

	// Etoile la plus proche au centre du galaxie
	collEtoiles plusProcheEtoile = collEtoiles_creerVide();
	etoile nouveauEtoile;
	unsigned long int q=0;
	bool finProg=false;
	char choix;

        //Menu Principal
	while(!finProg){
		effacerEcran();
		afficherMenu();
		cin >> choix;
		effacerEcran();
		switch(choix){

			case '0':
			case 'x':
			case 'X':
                            // Fin du programme
				finProg=true;
				break;
			case '1':
				// Obtient info galaxie
				collEtoiles_afficherInfo(plusProcheEtoile);
				attendeEcran();
				break;
			case '2':
				// Affiche tous les etoiles
				cout << "TOUS LES ETOILES (distance au centre de la galaxie en ordre croissant) :" << endl <<endl;
				collEtoiles_afficherToutes(plusProcheEtoile);
				attendeEcran();
				break;
			case '3':
				// Affiche info sur une etoile
				cout << "Choisir l'etoile ID pour afficher : " ;
				cin >> q;
				effacerEcran();
				if(q>=0 && q<collEtoiles_quantiteEtoiles(plusProcheEtoile)){
					cout << "Etoile #" << q << endl << endl;
					etoile_info(collEtoiles_getEtoile(plusProcheEtoile, q));
					attendeEcran();
				} else {
					cout << "L'etoile #" << q << " n'existe pas" << endl;
					attendeEcran();
				}
				break;
			case '4':
				// Ajoute une etoile avec information aleatoire
				nouveauEtoile = etoile_creerRnd();
				cout << "Etoile cree :" << endl;
				etoile_info(nouveauEtoile);
				collEtoiles_ajouterEtoile(plusProcheEtoile, nouveauEtoile);
				cout << endl;
				collEtoiles_afficherQuantEtoiles(plusProcheEtoile);
				attendeEcran();
				break;
			case '5':
				// Ajoute une etoile avec l'info specifie par l'utilisateur
				nouveauEtoile = etoile_demander();
				collEtoiles_ajouterEtoile(plusProcheEtoile, nouveauEtoile);
				cout << endl << "Nouvelle etoile ajoutee" << endl << endl;
				collEtoiles_afficherQuantEtoiles(plusProcheEtoile);
				attendeEcran();
				break;
			case '6':
				// Ajoute X etoiles aleatoires
				cout << "Quantite d'etoiles a ajouter : ";
				cin >> q;
				for(unsigned long int i=1; i<=q; i++) {
					cout << "Atente pour la creation d'etoile #" << i << "..." << endl;
					nouveauEtoile = etoile_creerRnd();
					collEtoiles_ajouterEtoile(plusProcheEtoile, nouveauEtoile);
				}
				cout << endl;
				collEtoiles_afficherQuantEtoiles(plusProcheEtoile);
				attendeEcran();
				break;
			case '7':
				// Supprime une etoile
				cout << "Choisir un etoile-ID pour supprimer : " ;
				cin >> q;
				effacerEcran();
				if(q>=0 && q<collEtoiles_quantiteEtoiles(plusProcheEtoile)){
					collEtoiles_afficherQuantEtoiles(plusProcheEtoile);
					cout << "En train d'eliminer l'etoile #" << q << "..." << endl;
					collEtoiles_supprimerEtoile(plusProcheEtoile, q);
					collEtoiles_afficherQuantEtoiles(plusProcheEtoile);
					attendeEcran();
				} else {
					cout << "L'etoile #" << q << " n'existe pas" << endl;
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

//#pragma warning( disable : 4996 )	// evite la depreciation de la fonction strcpy
//#pragma warning( error : 4706 )	// signale une erreur pour l'affectation dans une expression conditionnelle (= au lieu de =)
//#pragma warning( error : 4700 )	// signale une erreur pour variable non initialise