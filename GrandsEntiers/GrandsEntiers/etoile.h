#ifndef etoile_h
#define etoile_h

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <string>
#include "bint.h"
#include "uint64util.h"

using namespace std;

// Etoile (star)
typedef struct etoile {
	// distance au centre du galaxie (10^12 km)
	bint distCentGal;

	// rayon (radius) de l'etoile (10^3 km)
	bint rayon;

	// volume de l'etoile (10^3 km^3)
	bint volume;
};



// fonctions basiques

// creer une etoile a partir de la distance au centre du galaxie et son rayon
etoile etoile_creer(unsigned long long distanceCentreGalaxie, unsigned long long rayon);

// creer une etoile a partir de la distance au centre du galaxie et son rayon
etoile etoile_creer(bint distanceCentreGalaxie, bint rayon);

// creer une etoile a partir de la distance au centre du galaxie, son rayon et volume
etoile etoile_creer(bint distanceCentreGalaxie, bint rayon, bint volume);

// creer une etoile de distance au centre du galaxie et rayon aleatorires, et calculer le volume a partir du rayon
etoile etoile_creerRnd();








// obtenir etoile sur le clavier (demander distance au centre du galaxie et rayon. Calculer volume a partir du rayon)
etoile etoile_demander();









// fonctions d'affichage

// information generale de l'etoile: DEBUG
void etoile_info(etoile &e, string teteCout = "");

#endif