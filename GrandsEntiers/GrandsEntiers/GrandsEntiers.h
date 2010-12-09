#ifndef GrandsEntiers_h
#define GrandsEntiers_h

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <string>

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









// fonctions basiques
bint bint_creerVide();
void bint_assigner(bint &b, unsigned long long n);








// fonctions d'affichage

// information generale: DEBUG
void bint_info(bint &b);

// obtenir valeur binaire
string bint_getBin(bint &b);











// arithmetique

// a=a+b
void bint_ajouter(bint &a, int b);
void bint_ajouter(bint &a, unsigned long long b);
void bint_ajouter(bint &a, const bint &b);

//ajoute un nombre en certain position du array
void bint_ajouter(bint &a, unsigned long long b, int pos);

// a=a-b
void bint_sustraire(bint &a, int b);
void bint_sustraire(bint &a, unsigned long long b);

// a=a*b
void bint_multiplier(bint &a, const bint &b);

// a=a^b
void bint_pow(bint &a, const bint &b);







// options internes
void bint_setLongInter(bint &a, unsigned int L);
bool uint64GetBit(unsigned long long N, unsigned char bit);
string uint64ToBinStr(unsigned long long n);

#endif
