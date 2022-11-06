#include "lectureBinaire.hpp"
#include <fstream>
#include <sstream>
#include <cassert>
#include "bibliotheque_cours.hpp"
#include <vector>
#include "VilainHeros.hpp"
#include <iostream>
using namespace std;

ifstream ouvrirFichierBinaire(const string& nomFichier)
{
	ifstream fichier(nomFichier, ios::binary);
	fichier.exceptions(ios::failbit);
	return fichier;
}

void testsPourCouvertureLectureBinaire()
{
	istringstream iss("\xA0\x12\xA1\x21\x43\xA2\x98\xBA\xDC\xFE");
	assert(lireUintTailleVariable(iss) == 0x12);
	assert(lireUintTailleVariable(iss) == 0x4321);
	assert(lireUintTailleVariable(iss) == 0xFEDCBA98);
}


Vilain lireVilain(ifstream& fichierBinaire) {
	string nom = lireString(fichierBinaire);
	string jeuParution = lireString(fichierBinaire);
	string objectif = lireString(fichierBinaire);



	Vilain v(nom, jeuParution, objectif);
	return v;
}

void creerVilain(vector<Vilain>& vilainV, ifstream& fichierBinaire) {

	size_t nElements = lireUintTailleVariable(fichierBinaire);

	for (int i = 0; i < nElements; i++) {
		vilainV.push_back(lireVilain(fichierBinaire));
	}
}


Heros lireHeros(ifstream& fichierBinaire) 
{
	vector<string> alies;
	string nom = lireString(fichierBinaire);
	string jeuParution = lireString(fichierBinaire);
	string ennemi = lireString(fichierBinaire);
	int tailleVecteur = lireUintTailleVariable(fichierBinaire);

	

	for (int i = 0; i < tailleVecteur; i++) 
	{
		alies.push_back(lireString(fichierBinaire));
	}

	Heros h(nom,jeuParution,ennemi,alies);

	return h;
}



void creerHeros(vector<Heros>& herosV, ifstream& fichierBinaire) {
	int tailleVecteur = lireUintTailleVariable(fichierBinaire);

	for (int i = 0; i < tailleVecteur; i++) {
		herosV.push_back(lireHeros(fichierBinaire));
	}
}




int main()
{
	#pragma region "Bibliothèque du cours"
	// Permet sous Windows les "ANSI escape code" pour changer de couleur
	// https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac
	// les supportent normalement par défaut.
	bibliotheque_cours::activerCouleursAnsi();
	#pragma endregion
	
	testsPourCouvertureLectureBinaire();

	// Trait de separation
	static const string trait =
		"═════════════════════════════════════════════════════════════════════════";

	// Ouverture des fichiers binaires
	ifstream fichierHeros = ouvrirFichierBinaire("heros.bin");
	ifstream fichierVilains = ouvrirFichierBinaire("vilains.bin");

	//TODO: Votre code pour le main commence ici (mais vous pouvez aussi ajouter/modifier du code avant si nécessaire)
	vector <Heros> herosV;
	vector <Vilain> vilainV;
	vector <unique_ptr<Personnage>> personnageV;
	
	creerVilain(vilainV, fichierVilains);
	creerHeros(herosV, fichierHeros);
	




	for (int i = 0; i < herosV.size(); i++) 
	{
		herosV[i].changerCouleur(cout, "32");
		herosV[i].afficher(cout);
		herosV[i].changerCouleur(cout, "0");
		cout << "═══════════════════════════════════════════════════════════════"<< "\n";
			
	}

	for (int i = 0; i < vilainV.size(); i++) {
		vilainV[i].changerCouleur(cout, "95");
		vilainV[i].afficher(cout);
		vilainV[i].changerCouleur(cout, "0");
		cout << "═══════════════════════════════════════════════════════════════" << "\n";
	}

	VilainHeros vh(herosV[5], vilainV[2]);
	

	
	
	
	
	for (int i = 0; i < herosV.size(); i++) 
	{
		personnageV.push_back(make_unique<Heros>(herosV[i]));
	}
	
	
	for (int i = 0; i < vilainV.size(); i++) 
	{
		personnageV.push_back(make_unique<Vilain>(vilainV[i]));
	}


	personnageV.push_back(make_unique<VilainHeros>(vh));
	

	
	for (int i = 0; i < personnageV.size(); i++) 
	{
		
		personnageV[i]->afficher(cout);
	}

}
