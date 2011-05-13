/*********************************************************/
// µ-projet de commande par microcontrôleur
// ENS2M avril 2011
// Adrian BULNES
// David FUENMAYOR
/*********************************************************/

#include <pic.h>
#include "afficheur.h"

#define SwAffichConsigne RE3
#define SwAffichErreur RD4
#define SwAffichCommande RD6
#define SwAffichRetour RD7
#define Capteur RD1
#define Appuye 0
#define MoteurON RD5
#define Kp 1

static char consigne;
static char erreur;
static char commande;
static char retour;
static char encoder;
static char vitesse;


//Timer 0 - interrupt 5ms pour faire commande
void setupT0() {
	//Fosc=4MHz, Fcy=1MHz, Tcy=1us
	//interrupts chaque 128*256us = 32ms@ 128prescaler 
	T0CS=0; //Horloge Interne
	PSA=0;
	PS2=1;
	PS1=1;	//Prescaler 128
	PS0=0;
	TMR0=0; //Initialization a zero
	T0IF=0;	//Interrupt flag to zero
	T0IE=1;	//Enable interrupt
}

//Timer1 - compteur flancs encoder sans prescaler en RC5/T1CKI
void setupT1() {
	T1CKPS1=0;	//Pas de prescaler
	T1CKPS0=0;	//Pas de prescaler
	TMR1CS=1;	//Mode compteur 
	T1SYNC=1;	//Synchronisation habilété
	TMR1H=0;	//Initialization a zero
	TMR1L=0;	//Initialization a zero
	TMR1IF=0;	
	PEIE=1;		//Enable peripheral interrupt
	TMR1IE=1;
	TMR1ON=1;	//Allume compteur
}

void setupBoutons(){
	TRISE3=1;

	TRISC5=1;
	TRISD|=0b11010000;
}

// lire ADC (potentiometer) - commande
void setupAdcPot(){
	consigne=0;
	TRISA0=1; //AN0 entree POT1
	ANSEL=1; //AN0 analog, AN1-7 numerique
	ADCON1=0x10; //Fosc/8
	ADRESL=0;
	ADRESH=0;
	ADIF=0;
	ADIE=1;
	PEIE=1;
	ADCON0=1; //ADON, Channel 0 (AN0)
}

//PWM - vitesse moteur
void setupPWM(){
	TRISD2=0; //RD2 sortie PWM
	PR2=0xFF;
	TMR2ON=1;
	T2CKPS1=1; //Prescaler mis a 16 pour le PWM donc Periode PWM=4.1ms
	T2CKPS0=1;
	CCP2M3=1; //PWM mode
	CCP2M2=1;
}

void setupMoteur(){
	TRISD5=0; //MoteurON
	MoteurON=1;
}

void setupCapteur(){
	TRISD1=1;
}

void interrupt gestion_IT() {
	if(ADIF){
		consigne=ADRESH;
		GODONE=1; //debut ADC/CAN
		ADIF=0;
	} 
	if(T0IF) {	
		encoder=TMR1L;
		vitesse= encoder<<5; //Vitesse max = 8 flancs encoder en 32ms ->255 = Gain=255/8=32
		erreur=consigne-vitesse;
		commande=(erreur>>1)+(erreur>>2)+(erreur>>3);		
		CCPR2H=0;
		CCPR2L=commande;	// Modifie PWM
		TMR1ON=1;		
		TMR1H=0;		// Reinitialise Compteur
		TMR1L=0;		
		T0IF=0;			
	}
	if(TMR1IF) {
		//temps encoder trop grand - fixe a 255
		TMR1ON=0;
		TMR1H=0xFF;
		TMR1IF=0;
	}
}

char i;

void main(){
	setupMoteur();
	InitialisationAfficheur();
	setupT0();
	setupT1();
	setupBoutons();
	setupAdcPot();
	setupPWM();
	setupCapteur();
	GIE=1;	
	GODONE=1;		//debut ADC/CAN

	AfficherDecimal(0);

	while(1){		// Boucle infini
		i++;
		if(i>250){	// Affiche les infos selectionnes
			i=0;
			if(SwAffichConsigne==Appuye) {
				AfficherDecimal(consigne);
			} else if(SwAffichErreur==Appuye) {
				AfficherDecimal(erreur);
			} else if(SwAffichCommande==Appuye) {
				AfficherDecimal(commande);
			} else if(SwAffichRetour==Appuye) {
				AfficherDecimal(vitesse);
			}
		}
	}
}
