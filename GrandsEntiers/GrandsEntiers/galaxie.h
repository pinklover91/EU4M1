#ifndef galaxie_h
#define galaxie_h

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <sstream>
#include "etoile.h"
#include "globals.h"
#include "uint64util.h"

using namespace std;

//collection d'etoiles
typedef struct nodeEtoile* collEtoiles;

typedef struct nodeEtoile {
	// l'etoile
	etoile etoile;

	// pointeur a le prochain etoile (et les autres etoiles moins proches)
	collEtoiles suivNodeEtoile;
} nodeEtoile;

collEtoiles collEtoiles_creerVide();
nodeEtoile* nodeEtoile_creer(etoile &e);
void collEtoiles_afficherInfo(collEtoiles &c);
void collEtoiles_afficherToutes(collEtoiles &c);
void collEtoiles_afficherQuantEtoiles(collEtoiles &c);
unsigned int collEtoiles_quantiteEtoiles(collEtoiles &c);
void collEtoiles_ajouterEtoile(collEtoiles &c, etoile e);
void collEtoiles_ajouteEnTete(collEtoiles &c, etoile e);
etoile collEtoiles_derniereEtoile(collEtoiles &c);
etoile collEtoiles_plusGrandEtoile(collEtoiles &c);
bint collEtoiles_volumeTotal(collEtoiles &c);
etoile collEtoiles_getEtoile(collEtoiles &c, unsigned long long id);
void collEtoiles_supprimerEtoile(collEtoiles &c, unsigned long long id);

#endif