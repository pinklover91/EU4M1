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

// Etoile
typedef struct etoile {
	// distance au centre de la galaxie (10^12 km)
	bint distCentGal;

	// rayon (radius) de l'etoile (10^3 km)
	bint rayon;

	// volume de l'etoile (10^3 km^3)
	bint volume;
};



// Sous-programmes de base

// Cree une etoile a partir de la distance au centre de la galaxie et son rayon
etoile etoile_creer(unsigned long long distanceCentreGalaxie, unsigned long long rayon);

// Cree une etoile a partir de la distance au centre de la galaxie et son rayon
etoile etoile_creer(bint distanceCentreGalaxie, bint rayon);

// Cree une etoile a partir de la distance au centre de la galaxie, son rayon et volume
etoile etoile_creer(bint distanceCentreGalaxie, bint rayon, bint volume);

// Cree une etoile de distance au centre du galaxie et rayon aleatoires, et calcule le volume a partir du rayon
etoile etoile_creerRnd();

// Obtient une etoile (demande la distance au centre de la galaxie et le rayon.
// Calcule le volume a partir du rayon)
etoile etoile_demander();

// Sous-programmes d'affichage

// Information generale de l'etoile: DEBUG
void etoile_info(etoile &e, string teteCout = "");

#endif