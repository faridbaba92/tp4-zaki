using namespace std;
#include "Heros.hpp"




ostream& Heros::afficher(ostream& sortie) 
{
	
	Personnage::afficher(sortie);

	sortie << "liste d'aliés :" << endl;

	for (int i = 0; i < getAlies().size(); i++)
	{
		sortie << "		" << getAlies()[i] << endl;
	}

	return sortie;
}

