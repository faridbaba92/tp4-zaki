using namespace std; 
#include <string>
#include "Personnage.hpp"



ostream& Personnage::afficher(ostream& sortie) 
{
	sortie << "Nom : " << getNom() << endl << "jeu de parution : " << getjeuParution() << endl;

	return sortie;
}



ostream& Personnage::changerCouleur(ostream& sortie, string couleur)
{
	string affichageCouleur = "\033[" + couleur + "m";
	
	sortie << affichageCouleur;

	return sortie;

};