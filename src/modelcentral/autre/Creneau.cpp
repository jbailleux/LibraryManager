#include "Creneau.hpp"
#include <string>
#include <iostream>
#include "Date.hpp"
using namespace std;


string Creneau::premiereDate(std::string const c)const{
	size_t pos =c.find(" ");
	string p=c.substr(0,pos);
	return p;
}

string Creneau::deuxiemeDate(std::string const c)const{
	size_t pos =c.find(" ");
	string p=c.substr(pos+1,c.size());
	return p;
}

bool verifierChevauchement(Creneau const c1, Creneau const c2) {
	int d1=c1.getDebut().getHeure();
	int d2=c1.getFin().getHeure();
	int d3=c2.getDebut().getHeure();
	int d4=c2.getFin().getHeure();
	return ((d2<=d3)||(d1>=d4));// on a bien d1<d2 et d3<d4 car ce sont des Creneaux
}

Creneau::Creneau(){
}

Creneau::Creneau(Date const debut, Date const fin){
	setDebut(debut);
	setFin(fin);
}

Creneau::Creneau(string const c){
	setDebut(Date(premiereDate(c)));
	setFin(Date(deuxiemeDate(c)));
}
void Creneau::setDebut(Date const d){
	debut=d;
}

void Creneau::setFin(Date const d){
	fin=d;
}

Creneau::~Creneau(){
}

Date Creneau::getDebut()const {
	return debut;
}

Date Creneau::getFin()const {
	return fin;
}

string Creneau::to_string()const{
	string tmp;
	tmp="("+getDebut().to_string()+","+getFin().to_string()+")";
	return tmp;
}
