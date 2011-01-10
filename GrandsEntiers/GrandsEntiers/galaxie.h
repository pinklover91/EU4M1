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

// collection d'etoiles
typedef struct nodeEtoile* collEtoiles;

// node de la colection avec une etoile et le pointeur au prochain node
typedef struct nodeEtoile {
	// l'etoile
	etoile etoile;

	// pointeur a le prochain etoile (et les autres etoiles moins proches)
	collEtoiles suivNodeEtoile;
};

// creer collEtoiles vide
collEtoiles collEtoiles_creerVide();

// creer pointeur a nouveau node de la colection d'etoiles
nodeEtoile* nodeEtoile_creer(etoile &e);

// afficher information de la colection d'etoiles
void collEtoiles_afficherInfo(collEtoiles &c);

// afficher toutes les etoiles de la colection
void collEtoiles_afficherToutes(collEtoiles &c);

// afficher le nombre d'etoiles en la colection
void collEtoiles_afficherQuantEtoiles(collEtoiles &c);

// compter le nombre d'etoiles en la colection
unsigned int collEtoiles_quantiteEtoiles(collEtoiles &c);

// ajouter une etoile a la colection
void collEtoiles_ajouterEtoile(collEtoiles &c, etoile e);

// ajouter en tete une etoile a la colection
void collEtoiles_ajouteEnTete(collEtoiles &c, etoile e);

// obtenir la derinere etoile de la colection
etoile collEtoiles_derniereEtoile(collEtoiles &c);

// obtenir la plus grqnde etoile de la colection
etoile collEtoiles_plusGrandEtoile(collEtoiles &c);

// calculer le volume total de la galaxie
bint collEtoiles_volumeTotal(collEtoiles &c);

// obtenir une etoile a partir de son ID
etoile collEtoiles_getEtoile(collEtoiles &c, unsigned long long id);

// suppri,er une etoile de la colection
void collEtoiles_supprimerEtoile(collEtoiles &c, unsigned long long id);

#endif