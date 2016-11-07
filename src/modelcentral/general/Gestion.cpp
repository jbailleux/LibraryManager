
#include "Gestion.hpp"
#include <vector>
#include <map>
#include "InstanceAReserver.hpp"
#include "../autre/Creneau.hpp"
#include <string>
#include "../autre/traduction.hpp"
#include "../specialisation/salle/Salle.hpp"
#include <stdlib.h>
using namespace std;

Gestion::~Gestion() {
	for(map<string,InstanceAReserver*>::iterator it=listeInstances->begin();it!=listeInstances->end();++it){
		delete(it->second);
	}
	listeInstances->clear();
	//cout<<"Gestion détruite"<<endl;
}

Gestion::Gestion(){
	listeInstances=new map<string,InstanceAReserver*>();
}

vector<string> Gestion::recherche(string const capacite, string const genreSalle){
	TypeSalle typeSalle=stringToTypeSalle(genreSalle);
	int c=atoi(capacite.c_str());
	return recherche( c, typeSalle);
}

vector<string> Gestion::recherche(int const capacite, TypeSalle const typeSalle){
	vector<string> listeInstanceAuCritere;
	map<string,InstanceAReserver*> *tmp;
	tmp=getListeInstances();

	for(map<string,InstanceAReserver*>::iterator it=tmp->begin();it!=tmp->end();++it){
		Salle* salle=(Salle*) it->second;
		if ((capacite<=salle->getCapacite())&&(typeSalle.getType()==salle->getTypeSalle().getType())){
			listeInstanceAuCritere.push_back(it->first);
		}
	}
	return listeInstanceAuCritere;
}

vector<string> Gestion::getListeNomInstances()const{
	vector<string> l;
	map<string,InstanceAReserver*> *tmp;
	tmp=getListeInstances();
	for(map<string,InstanceAReserver*>::iterator it=tmp->begin();it!=tmp->end();++it)
		l.push_back(it->first);
	return l;
}

string Gestion::obtenirInfo(string const nomInstance, string const creneau){
	Creneau c(creneau);
	InstanceAReserver* instance=getInstance(nomInstance);
	return obtenirInfo(instance,c);
}

string Gestion::obtenirInfo(InstanceAReserver* const instance, Creneau const creneau)const {
	return instance->obtenirInfo(creneau);
}



InstanceAReserver* Gestion::getInstance(string const nomInstance){
	map<string,InstanceAReserver*>* tmp;
	tmp=getListeInstances();
	return tmp->at(nomInstance);
}

map<string,InstanceAReserver*>* Gestion::getListeInstances()const{
	return listeInstances;
}

vector<string> Gestion::getInstancesLibres(string const c){
	Creneau creneau(c);
	return getInstancesLibres(creneau);
}

vector<string> Gestion::getInstancesLibres(Creneau const creneau){
	vector<string>instancesLibres;
	map<string,InstanceAReserver*>* instances=getListeInstances();
	for(map<string,InstanceAReserver*>::iterator it=instances->begin();it!=instances->end();++it){
		InstanceAReserver* instance=it->second;
		if (instance->estLibre(creneau)){
			instancesLibres.push_back(it->first);	// On ajoute le nom de l'instance au vecteur qu'on retourne
		}
	}
	return instancesLibres;
}


vector<string> Gestion::getInstancesOccupees(string const c) {
	Creneau creneau(c);
	return getInstancesOccupees(creneau);
}

vector<string> Gestion::getInstancesOccupees(Creneau const creneau) {
	vector<string>instancesOccupees;
	map<string,InstanceAReserver*>* instances=getListeInstances();
	for(map<string,InstanceAReserver*>::iterator it=instances->begin();it!=instances->end();++it){
		InstanceAReserver* instance=it->second;
		if (!instance->estLibre(creneau))
			instancesOccupees.push_back(it->first);	// On ajoute le nom de l'instance au vecteur qu'on retourne
	}
	return instancesOccupees;
}


bool Gestion::reserver(InstanceAReserver* instance,string const nom, Creneau const c)
{
	bool b;
	b=instance->estLibre(c);
	if (b== true){
		b=instance->reserver(nom, c);}
	return b;
}

bool Gestion :: liberer(InstanceAReserver* instance, Creneau c)
{
	bool b=false;
		if (!instance->estLibre(c))
		{
			b=instance->liberer(c);
		}
	return b;
}

bool Gestion::reserver(string nomSalle, string const nomReserveur, string const creneau)
{
	bool b;
	InstanceAReserver* instance;
	instance = getInstance(nomSalle);
	Creneau c(creneau);
	if (c.getDebut().getHeure()>c.getFin().getHeure()){
		return false;
	}
	else{
		b = reserver(instance, nomReserveur, c);
		return b;
	}

}

bool Gestion::liberer(string nomS, string c)
{
	bool b;
	InstanceAReserver* instance;
	instance = getInstance(nomS);
	Creneau creneau(c);
	b = liberer(instance, creneau);
	return b;
}
