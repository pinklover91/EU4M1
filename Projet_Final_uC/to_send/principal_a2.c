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
#define TestLed RA1


static char counter;
static char consigne;
static char erreur;
static char commande;
static char retour;
static char encoder;
static char vitesse;

//Timer 0 - interruptions tout les 4.1ms pour faire commande
void setupT0() {
	//Fosc=4MHz, Fcy=1MHz, Tcy=1us
	//interruptions chaque 16*256us = 4.1ms@ prescaler 16
	T0CS=0;	//Horloge Interne
	PSA=0;
	PS2=0;	//Prescaler 16
	PS1=1;	//Prescaler 16
	PS0=1;	//Prescaler 16
	TMR0=0;	//Initialization a zero
	T0IF=0;	//Interrupt flag to zero
	T0IE=1;	//Enable interrupt
}

//Timer1 - Mode timer, compte nombre de flancs montants
// TMR1H:TMRH1L = duration en microsecondes entre deux flancs du signal du encoder
// On se sert seulement de la partie superieure donc:  65ms > temps entre flancs > 0.256ms 

void setupT1() {
	encoder=0;
	vitesse=0;
	T1CKPS1=0;	//Prescaler 1
	T1CKPS0=0;	//Prescaler 1
	TMR1CS=0;  //Mode Timer
	TMR1H=0;	//Initialization a zero
	TMR1L=0;	//Initialization a zero
	TMR1IF=0;
	PEIE=1;	//Enable peripheral interrupt
	TMR1IE=1;
	TMR1ON=1;	//Allume compteur
}

void setupBoutons(){
	TRISE3=1;
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
	TRISD2=0; 	//RD2 sortie PWM
	PR2=0xFF;
	TMR2ON=1;
	T2CKPS1=1;
	T2CKPS0=1;	//Prescaler mis a 16 pour le PWM donc PeriodePWM=4.1ms
	CCP2M3=1; 	//PWM mode
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
		if(consigne>250) consigne=255;
		GODONE=1; //debut ADC/CAN
		ADIF=0;
	} else if(T0IF) {
		erreur=consigne-(255-encoder);
		commande=(erreur>>1)+(erreur>>2)+(erreur>>3);
		CCPR2H=0;
		CCPR2L=commande;
		T0IF=0;
	} else if(TMR1IF) {
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
	TRISA1=0;
	GIE=1;

	//debut ADC/CAN
	GODONE=1;

	AfficherDecimal(0);

	while(1){ //infinite loop

		// Software debouncing code
       		if (counter < 255){ //previent que le compteur reviens a zero
         		counter++;
       		}    
		//capteur - falling edge
		if(Capteur==1){
			counter=0;
			TestLed=0;
		}
		if (counter == 20) { //Apres stabilization et une seule fois
			//lire temp encoder (capteur)
			TestLed=1;			
			encoder=TMR1H;  
			TMR1ON=1;
			TMR1H=0;
			TMR1L=0;
			counter++;
		}
		
		i++;
		if(i>200){
			i=0;
			if(SwAffichConsigne==Appuye){
				AfficherDecimal(consigne);
			} else if(SwAffichErreur==Appuye){
				AfficherDecimal(erreur);
			} else if(SwAffichCommande==Appuye){
				AfficherDecimal(commande);
			} else if(SwAffichRetour==Appuye){
				AfficherDecimal(encoder);
			}
		}
	}
}
