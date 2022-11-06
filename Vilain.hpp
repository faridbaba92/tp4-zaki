#include "Personnage.hpp"
using namespace std;


class Vilain: virtual public Personnage 
{

public:
	Vilain(string nom, string jeuParution, string objectif) : Personnage(nom, jeuParution), objectif_(objectif) {}

	string getObjectif() const 
	{
		return objectif_;
	}

	ostream& afficher(ostream& sortie) 
	{
		Personnage::afficher(sortie);
		sortie << "objectif: " << objectif_ << endl;

		return sortie;
	}



private:

	string objectif_;
};