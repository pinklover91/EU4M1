#ifndef bint_h
#define bint_h

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <sstream>
#include "uint64util.h"

using namespace std;

// Grand Entier
typedef struct bint {
	// bloques (array)
	unsigned long long *b;

	// longeur. Nombre de bloques utilises
	unsigned int nb;

	// longeur reel. Longeur d'array
	unsigned int internal_nb;
} bint;









// fonctions basiques
bint bint_creerVide();
bint bint_creer(unsigned long long valeur);
void bint_assigner(bint &b, unsigned long long n);
bint bint_copier(const bint &a);








// fonctions d'affichage et information

// information generale: DEBUG
void bint_info(bint &b);

// obtenir valeur binaire
string bint_getBin(bint &b);

// compter bits
unsigned long long bint_compterBits(bint &b);

// valeur environ (approximate value)
string bint_valEnviron(bint &b);

string bint_toString(bint &b);










// arithmetique

// a=a+b
void bint_ajouter(bint &a, int b);
void bint_ajouter(bint &a, unsigned long long b);
void bint_ajouter(bint &a, const bint &b);

// ajoute un nombre en certain position du array
void bint_ajouter(bint &a, unsigned long long b, int pos);

// a=a-b
void bint_sustraire(bint &a, int b);
void bint_sustraire(bint &a, unsigned long long b);

// sustraire un nombre en certain position du array
void bint_sustraire(bint &a, unsigned long long b, int pos);

// a=a*b
void bint_multiplier(bint &a, unsigned int b);
void bint_multiplier(bint &a, const bint &b);

// a=a^b
void bint_pow(bint &base, unsigned long long exp);
void bint_pow(bint &base, const bint &exp);










// comparaison
// est vide or ==0
bool bint_estVide(const bint &a);

// TRUE si a>b. FALSE si a<=b
bool bint_plusGrandQue(const bint &a, unsigned long long  b);
bool bint_plusGrandQue(const bint &a, const bint &b);

// TRUE si a<b. FALSE si a>=b
bool bint_plusPetitQue(const bint &a, unsigned long long  b);
bool bint_plusPetitQue(const bint &a, const bint &b);

// TRUE si a==b

bool bint_egal(const bint &a, unsigned long long b);
bool bint_egal(const bint &a, const bint &b);

// TRUE si a==b et les arrays sont egales aussi
bool bint_egalExact(const bint &a, const bint &b);





// options internes
// changer la longeur interieure de bint
void bint_setLongInter(bint &a, unsigned int L);


#endif
