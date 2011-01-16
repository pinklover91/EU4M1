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

// Collection d'etoiles
typedef struct nodeEtoile* collEtoiles;

// Node de la collection comportant une etoile et le pointeur au prochain node
typedef struct nodeEtoile {
	// l'etoile
	etoile etoile;

	// pointeur a l'etoile prochaine (et aux autres etoiles moins proches)
	collEtoiles suivNodeEtoile;
};

// Cree collEtoiles vide
collEtoiles collEtoiles_creerVide();

// Cree pointeur au nouveau node de la collection d'etoiles
nodeEtoile* nodeEtoile_creer(etoile &e);

// Affiche l'information de la collection d'etoiles
void collEtoiles_afficherInfo(collEtoiles &c);

// Affiche tous les etoiles de la collection
void collEtoiles_afficherToutes(collEtoiles &c);

// Affiche le nombre d'etoiles dans la collection
void collEtoiles_afficherQuantEtoiles(collEtoiles &c);

// Compte le nombre d'etoiles en la collection
unsigned int collEtoiles_quantiteEtoiles(collEtoiles &c);

// Ajoute une etoile a la collection
void collEtoiles_ajouterEtoile(collEtoiles &c, etoile e);

// Ajoute en tete une etoile a la collection
void collEtoiles_ajouteEnTete(collEtoiles &c, etoile e);

// Obtient la derniere etoile de la collection
etoile collEtoiles_derniereEtoile(collEtoiles &c);

// Obtient la plus grande etoile de la collection
etoile collEtoiles_plusGrandEtoile(collEtoiles &c);

// Calcule le volume total de la galaxie
bint collEtoiles_volumeTotal(collEtoiles &c);

// Obtient une etoile a partir de son ID
etoile collEtoiles_getEtoile(collEtoiles &c, unsigned long long id);

// Supprime une etoile de la collection
void collEtoiles_supprimerEtoile(collEtoiles &c, unsigned long long id);

#endif