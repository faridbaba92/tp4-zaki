#pragma once
#include"Vilain.hpp"
#include"Heros.hpp"
using namespace std;

class VilainHeros : public Vilain, public Heros {
public:

	VilainHeros(Heros heros, Vilain vilain) : Personnage(vilain.getNom() + "-" + heros.getNom(),
											  vilain.getjeuParution() + "-" + heros.getjeuParution()),
											  Heros(heros), Vilain(vilain), 
											  missionSpeciale_(vilain.getObjectif() + " dans le monde de " + heros.getjeuParution()) {};

	
	ostream& afficher(ostream& out);


private:
	string missionSpeciale_;
};