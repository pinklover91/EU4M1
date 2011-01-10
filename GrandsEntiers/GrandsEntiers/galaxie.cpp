#include "galaxie.h"

collEtoiles collEtoiles_creerVide(){
	return null;
}

void collEtoiles_afficherInfo(collEtoiles &c) {
	cout << "INFORMATION DU GALAXIE" << endl << endl;
	collEtoiles_afficherQuantEtoiles(c);
	if(collEtoiles_quantiteEtoiles(c) > 0) {
		etoile etoilePlusGrand = collEtoiles_plusGrandEtoile(c);
		cout << "Etoile plus eloignee (plus grand distance au centre) : " << bint_toString(collEtoiles_derniereEtoile(c).distCentGal) << "000000000000 km" << endl;
		cout << "Etoile plus grand: " << endl;
		etoile_info(etoilePlusGrand, "    ");
		cout << "Volume total du galaxie : " << bint_toString(collEtoiles_volumeTotal(c)) << " x 10^3 km^3" << endl;
	}
}

void collEtoiles_afficherToutes(collEtoiles &c){
	int i=0;
	collEtoiles suiv = c;
	while(suiv!=null){
		cout << "Etoile #"<<i<<" :"<<endl;
		etoile_info(suiv->etoile, "    ");
		i++;
		suiv=suiv->suivNodeEtoile;
	}
}

void collEtoiles_afficherQuantEtoiles(collEtoiles &c){
	cout << "Quantite d'etoiles : " << collEtoiles_quantiteEtoiles(c) << endl;

}

unsigned int collEtoiles_quantiteEtoiles(collEtoiles &c){
	unsigned int q = 0;
	collEtoiles suivNodeEtoile = c;
	while(suivNodeEtoile!=null){
		q++;
		suivNodeEtoile=suivNodeEtoile->suivNodeEtoile;
	}
	return q;
}

nodeEtoile* nodeEtoile_creer(etoile &e){
	nodeEtoile* ne = new nodeEtoile;
	ne->etoile=e;
	ne->suivNodeEtoile=null;
	return ne;
}

void collEtoiles_ajouteEnTete(collEtoiles &c, etoile e){
	nodeEtoile* nouveauNodeEtoile = nodeEtoile_creer(e);
	nouveauNodeEtoile->suivNodeEtoile=c;
	c=nouveauNodeEtoile;
}

void collEtoiles_ajouterEtoile(collEtoiles &c, etoile e) {
	nodeEtoile* nouveauNodeEtoile = nodeEtoile_creer(e);
	if(c==null) c=nouveauNodeEtoile;
	else {
		if(bint_plusGrandQue(c->etoile.distCentGal, nouveauNodeEtoile->etoile.distCentGal)) {
			// le nouveau est plus proche que le node en tete
			collEtoiles_ajouteEnTete(c, e);
		} else {
			// le node en tete es plus proche que le nouveau
			collEtoiles plusProcheNode = c;
			while(plusProcheNode->suivNodeEtoile!=null && bint_plusGrandQue(nouveauNodeEtoile->etoile.distCentGal, plusProcheNode->suivNodeEtoile->etoile.distCentGal)){
				plusProcheNode=plusProcheNode->suivNodeEtoile;
			}
			nouveauNodeEtoile->suivNodeEtoile=plusProcheNode->suivNodeEtoile;
			plusProcheNode->suivNodeEtoile=nouveauNodeEtoile;
		}
	}
}

etoile collEtoiles_derniereEtoile(collEtoiles &c){
	collEtoiles suiv = c;
	while(suiv->suivNodeEtoile!=null) suiv=suiv->suivNodeEtoile;
	return suiv->etoile;
}

etoile collEtoiles_plusGrandEtoile(collEtoiles &c){
	etoile plusGrandEtoile = c->etoile;
	collEtoiles suiv = c;
	while(suiv->suivNodeEtoile!=null) {
		if(bint_plusGrandQue(suiv->etoile.volume, plusGrandEtoile.volume)) plusGrandEtoile=suiv->etoile;
		suiv=suiv->suivNodeEtoile;
	}
	return plusGrandEtoile;
}

bint collEtoiles_volumeTotal(collEtoiles &c){
	bint vol = bint_creerVide();
	collEtoiles suiv = c; 
	while(suiv!=null) {
		bint_ajouter(vol, suiv->etoile.volume);
		suiv=suiv->suivNodeEtoile;
	}
	return vol;
}

etoile collEtoiles_getEtoile(collEtoiles &c, unsigned long long id){
	etoile e;
	collEtoiles suiv = c;
	for(unsigned long long i=0; i<id; i++){
		suiv=suiv->suivNodeEtoile;
	}
	return suiv->etoile;
}

void collEtoiles_supprimerEtoile(collEtoiles &c, unsigned long long id){
	if(id==0){
		collEtoiles s = c->suivNodeEtoile;
		delete c;
		c=s;
	} else {
		collEtoiles_supprimerEtoile(c->suivNodeEtoile, id-1);
	}
}