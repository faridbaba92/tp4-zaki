#include "VilainHeros.hpp"
using namespace std;




ostream&  VilainHeros::afficher(ostream& sortie)
{
	
	Personnage::afficher(sortie);
	
	sortie << "l'objectif: " << getObjectif() << endl << "l'ennemi: " << getEnnemi() << endl << "la liste d'ali�s:" << endl;

	
	for (int i = 0; i < getAlies().size(); i++)
	{
		sortie << "			" << getAlies()[i] << endl;
	}

	sortie << "la mission sp�ciale: " << missionSpeciale_ << endl;



	return sortie;

}