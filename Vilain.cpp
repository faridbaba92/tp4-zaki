#include"Vilain.hpp"
using namespace std;



ostream& Vilain::afficher(ostream& sortie) {
	

	Personnage::afficher(sortie);

	sortie << "objectif: " << objectif_ << endl;

	


	return sortie;
}