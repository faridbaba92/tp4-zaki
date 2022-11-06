#pragma once
#include<iostream>
using namespace std;

class Affichable 
{

public:

	virtual ostream& afficher(ostream& sortie) = 0;
	virtual ostream& changerCouleur(ostream& sortie, string couleur) = 0;

};
