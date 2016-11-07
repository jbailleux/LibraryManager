
#include "Controleur.hpp"
#include "modelcentral/general/Gestion.hpp"
#include "modelcentral/specialisation/salle/TypeSalle.hpp"
#include "modelcentral/specialisation/salle/Salle.hpp"
#include "modelcentral/autre/traduction.hpp"

Controleur::Controleur() {
	model= new Gestion();
}

Controleur::~Controleur() {
	delete(model);
	//cout<<"Controleur détruit"<<endl;
}

Gestion* Controleur::getModel() {
	return model;
}

bool Controleur::chargementDonnees(string const nomFichier){
	ifstream fichier;
    fichier.open(nomFichier.c_str(), ios::in); // on ouvre le fichier en lecture
	if(fichier){  // si l'ouverture a reussi
		int nombreSalle;
		fichier>>nombreSalle;
		for(int i=0;i<nombreSalle;i++){
			string nomSalle;
			int capacite;
			TypeSalle genreSalle;
			string typeSalleStr;
			fichier>>nomSalle;
			fichier>>capacite;
			fichier>>typeSalleStr;
			genreSalle=stringToTypeSalle(typeSalleStr);
			Salle* salle= new Salle(nomSalle,capacite,genreSalle);
			getModel()->getListeInstances()->insert(pair<string,InstanceAReserver*>(nomSalle,salle));
		}
		fichier.close();
		return true;
    }
    else
    {	cout<<"loupé"<<endl;
    	return false;
    }
};

vector<string> Controleur::getInstanceLibres(string const creneau){
	return getModel()->getInstancesLibres(creneau);
}

vector<string> Controleur::getInstanceOccupees(string const creneau){
	return getModel()->getInstancesOccupees(creneau);
}

vector<string> Controleur::effectuerRecherche(string const capacite, string const typeSalle){
	return getModel()->recherche(capacite,typeSalle);
}

string Controleur::obtenirInformationInstance(string const nomInstance,string const creneau){
	return getModel()->obtenirInfo(nomInstance,creneau);
}

bool Controleur::reserverInstance(string const nomInstance,string const nomReserveur, string const creneau){
	return getModel()->reserver(nomInstance,nomReserveur, creneau);
}

bool Controleur::rendreInstance(string const nomInstance, string const creneau){
	return getModel()->liberer(nomInstance,creneau);
}

