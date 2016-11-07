
#include "InstanceAReserver.hpp"
#include <iostream>
#include <string>
#include "../autre/Creneau.hpp"
#include "../autre/Date.hpp"

InstanceAReserver::InstanceAReserver() {
	nomReserveur=new vector<string>();
	dateReservation=new vector<Creneau>();
}

InstanceAReserver::~InstanceAReserver() {
	nomReserveur->clear();
	dateReservation->clear();
	//cout<<"InstanceAReserver détruite"<<endl;
}

bool InstanceAReserver::estLibre(Creneau const creneau) const{
	bool libre=true;
	unsigned int i=0;
	while((libre)&&(i<dateReservation->size())){
		libre=verifierChevauchement(creneau,dateReservation->at(i));
		i++;
	}
	return libre;
}

vector<string>* InstanceAReserver::getNomReserveur(){
	return nomReserveur;
}

vector<Creneau>* InstanceAReserver::getDateReservation(){
	return dateReservation;
}

bool InstanceAReserver :: reserver(string const nom, Creneau const creneau)
{
	bool b = true;
	getNomReserveur()->push_back(nom);
	getDateReservation()->push_back(creneau);
	return b;
}

bool InstanceAReserver :: liberer(Creneau const creneau)
{	bool b=false;
	unsigned int i=0;
	while ((!b)&&(i<getDateReservation()->size())){
		if ((getDateReservation()->at(i).getDebut().getHeure()==creneau.getDebut().getHeure()) &&
				(getDateReservation()->at(i).getFin().getHeure()==creneau.getFin().getHeure()) ){
			getDateReservation()->erase(getDateReservation()->begin()+i);
			getNomReserveur()->erase(getNomReserveur()->begin()+i);
			b=true;
		}
		i++;
	}
	return b;
}
