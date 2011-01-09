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

	// atomes de l'etoile
	//bint atomes;
} etoile;



// fonctions basiques
etoile etoile_creer(unsigned long long distanceCentreGalaxie, unsigned long long rayon);
etoile etoile_creer(bint distanceCentreGalaxie, bint rayon);
etoile etoile_creer(bint distanceCentreGalaxie, bint rayon, bint volume);
etoile etoile_creerRnd();






// obtenir etoile
etoile etoile_demander();









// fonctions d'affichage

// information generale: DEBUG
void etoile_info(etoile &e, string teteCout = "");

#endif