/*
 * Salle.cpp
 *
 *  Created on: 24 mars 2015
 *      Author: jeremy
 */

#include "Salle.hpp"
#include "../../general/InstanceAReserver.hpp"
#include "../../autre/traduction.hpp"
#include <string>
using namespace std;

Salle::Salle() {
}

Salle::~Salle() {
	cout<<"Salle détruite"<<endl;
}

Salle::Salle(string const n, int const c, TypeSalle const g){
	nomSalle=n;
	capacite=c;
	typeSalle=g;
}

string Salle::getNomSalle()const{
	return nomSalle;
}

int Salle::getCapacite()const{
	return capacite;
}

TypeSalle Salle::getTypeSalle()const{
	return typeSalle;
}

string Salle::obtenirInfo(Creneau const creneau)const {
	string tmp;
	tmp="nomSalle="+getNomSalle()+" capacite="+intToString(getCapacite())+" typeSalle="+getTypeSalle().to_string()+" libre au creneau(="+creneau.to_string()+") ="+boolToString(InstanceStatique::InstanceAReserver::estLibre(creneau))+" ."+'\n';
	return tmp;
}
