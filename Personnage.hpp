#pragma once
#include "Affichable.hpp"
using namespace std;

class Personnage : public  Affichable 
{

public:

	string getNom() const {
		return nom_;
	};

	string getjeuParution()const {
		return jeuParution_;
	};

	Personnage(string nom, string jeuParution) : nom_(nom), jeuParution_(jeuParution) {};

	virtual ostream& afficher(ostream& sortie);
	virtual ostream& changerCouleur(ostream& sortie, string couleur);

private:

	string nom_;
	string jeuParution_;

};
