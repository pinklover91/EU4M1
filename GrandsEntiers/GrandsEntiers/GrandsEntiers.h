#ifndef GrandsEntiers_h
#define GrandsEntiers_h

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>

using namespace std;

// Grand Entier
typedef struct bint {
	// bloques
	unsigned long long *b;

	// longeur. Nombre de bloques utilises
	unsigned int nb;

	// longeur reel. Longeur d'array
	unsigned int internal_nb;
} bint;

bint bint_creerVide();

void bint_info(bint b);

void bint_assigner(bint &b, int n);

void bint_ajouter(int b);

#endif
