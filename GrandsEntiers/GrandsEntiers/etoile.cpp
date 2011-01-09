#include "etoile.h"

etoile etoile_demander(){
	etoile e;
	unsigned long long dist, rayon;
	cout<<endl<<endl;
	cout << "Creer nouveau etoile :" << endl;
	cout << "Distance au centre du galaxie en 10^12 km (ex Soleil est 250000) : ";
	cin >> dist;
	cout << "Rayon en 10^3 km (ex. Soleil est 1392) : ";
	cin >> rayon;
	e=etoile_creer(dist, rayon);
	return e;
}

etoile etoile_creer(unsigned long long distanceCentreGalaxie, unsigned long long rayon) {
	return etoile_creer(bint_creer(distanceCentreGalaxie), bint_creer(rayon));
}

etoile etoile_creer(bint distanceCentreGalaxie, bint rayon){
	etoile e;
	e.distCentGal=distanceCentreGalaxie;
	e.rayon=rayon;
	//v=4/3*pi*r^3 -> aprox v=4*r^3
	e.volume=bint_copier(rayon);
	bint_multiplier(e.volume, rayon);
	bint_multiplier(e.volume, rayon);
	bint_multiplier(e.volume, 4);
	return e;
}

etoile etoile_creer(bint distanceCentreGalaxie, bint rayon, bint volume) {
	etoile e;
	e.distCentGal=distanceCentreGalaxie;
	e.rayon=rayon;
	e.volume=volume;
	return e;
}

etoile etoile_creerRnd() {
	unsigned long long rayon = uint64Rnd(500, 100000);
	if(rayon < 50000) return etoile_creer(uint64Rnd(10000, 50000000), rayon);
	else {
		// volumen ensin rayon, parce-que il est tres grand
		unsigned long long diff = uint64Rnd(100, uint64MaxValue);
		bint vol = bint_creer(uint64MaxValue);
		bint_ajouter(vol, diff);
		bint_ajouter(vol, diff);
		return etoile_creer(bint_creer(uint64Rnd(10000, 50000000)), bint_creer(0), vol);
	}
}


void etoile_info(etoile &e, string teteCout) {
	cout << teteCout << "Distance au centre du galaxie : " << bint_toString(e.distCentGal) << " x 10^12 km" << endl;
	if(bint_estVide(e.rayon)) cout << teteCout << "Rayon : (tres grand)" << endl;
	else cout << teteCout << "Rayon : " << bint_toString(e.rayon) << " x 10^3 km" << endl;
	cout << teteCout << "Volume : " << bint_toString(e.volume) << " x 10^9 km^3" << endl;
	//cout << "Atomes : " << bint_toString(e.atomes) << endl;
}