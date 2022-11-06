using namespace std;
#include <iostream>
#include <vector>
#include "Personnage.hpp"




class Heros : virtual public Personnage 
{

public:

	Heros(string nom, string jeuParution, string ennemi, vector<string> alies) : Personnage(nom, jeuParution), ennemi_(ennemi), alies_(alies) {}


	string getEnnemi()const {
		return ennemi_;
	};

	
	vector<string> getAlies() const {
		return alies_;
	}

	
	ostream& afficher(ostream& sortie);

private:

	string ennemi_;
	vector<string> alies_;

};


