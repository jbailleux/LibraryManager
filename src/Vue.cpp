
#include "Vue.hpp"
#include <iostream>
#include <string>
#include "Controleur.hpp"
#include <vector>
using namespace std;



Vue::~Vue() {
	delete(control);
	//cout<<"Vue detruite"<<endl;
}

Vue::Vue() {
	control=new Controleur();
	if (!control->chargementDonnees("donnees.txt"))
		cout<<"Probleme lors du chargement."<<endl;
	else
		cout<<"Chargement OK."<<endl;
}

Controleur* Vue::getControl(){
	return control;
}

bool Vue::lireManuel(string const nomFichier)const{
	ifstream fichier;
    fichier.open(nomFichier.c_str(), ios::in);
	if(fichier){
		string l;
        while(getline(fichier, l))
        	cout << l << endl;
    	 fichier.close();
    	 return true;
    }
    else
    	return false;
}

string obtenirCreneau(){
	string creneau;
	cout<<"Donnez votre creneau (de la forme \"XX YY\" avec YY>XX) "<<endl;
	getline(cin, creneau);
	return creneau;
	/*string obtenirCreneau(){
	string creneau;
	bool bonCreneau=false;
	while (!bonCreneau){
		creneau.clear();
		cout<<"Donnez votre creneau (de la forme \"XX YY\" avec YY>XX) "<<endl;
		getline(cin, creneau);
		unsigned int i;
		int j=0;
		bool b=true;
		while ((i<creneau.size())&&(j<2)&&(b)){
			char c=creneau.at(i);
			if(c==' ')
				j++;
			if (!((c=='0')||(c=='1')||(c=='2')||(c=='3')||
				(c=='4')||(c=='5')||(c=='6')||(c=='7')||
				(c=='8')||(c=='9')||(c==' ') ))
				b=false;
			i++;
		}
		bonCreneau=b&&(j==1);
		if (bonCreneau){
			Creneau c(creneau);
			bonCreneau=(c.getDebut().getHeure()<=c.getFin().getHeure());
			cout<<c.to_string()<<endl;
		}
	}
	return creneau;
}
	 * */

}

void Vue::voirInstancesLibres(){
	string creneau=obtenirCreneau();
	int choix=-1;
	vector<string> v=getControl()->getModel()->getInstancesLibres(creneau);
	cout<<"Les instances libres sont les suivantes : "<<endl;
	afficherVector(v);
	cout<<"Voulez vous reserver une des instances sur le creneau donne? 1: oui, 0 : non"<<endl;
	cin>>choix;cin.ignore();
	if (choix==1)
		reserverInstance(v,creneau);
}

void Vue::reserverInstance(vector<string> v, string creneau){
	int choix;
	bool b;
	string nomReserveur;
	if(creneau=="vide")
		creneau=obtenirCreneau();
	if (v.empty())
		v=getControl()->getModel()->getInstancesLibres(creneau);
	afficherVector(v);
	cout<<"Quelle instance voulez vous reserver? Donnez son numero."<<endl;
	cin>>choix;cin.ignore();
	cout<<"Quel est votre nom?"<<endl;
	cin>>nomReserveur;cin.ignore();
	b=getControl()->reserverInstance(v[choix],nomReserveur,creneau);
	if (b)
		cout<<"Instance reservee avec succes"<<endl;
	else
		cout<<"Probleme lors de la reservation. Contactez votre administrateur."<<endl;
}

void Vue::voirInstances(){
	vector<string >v=getControl()->getModel()->getListeNomInstances();
	cout<<"Voici toutes les instances enregistrees : "<<endl;
	afficherVector(v);
}

void Vue::obtenirInfoInstance(){
	vector<string >v=getControl()->getModel()->getListeNomInstances();
	string creneau=obtenirCreneau();
	int choix;
	cout<<"Voici toutes les instances enregistrees : "<<endl;
	afficherVector(v);
	cout<<"Indiquez le numero d instance dont vous voulez obtenir les informations."<<endl;
	cin>>choix;cin.ignore();
	cout<<"Voici les informations pour l'instance : "<<getControl()->getModel()->getInstance(v[choix])->obtenirInfo(creneau)<<endl;
}

void Vue::voirInstancesOccupees(){
	string creneau=obtenirCreneau();
	int choix=-1;
	vector<string> v=getControl()->getModel()->getInstancesOccupees(creneau);
	cout<<"Les instances occupees sont les suivantes : "<<endl;
	afficherVector(v);
	cout<<"Voulez vous rendre une des instances sur le creneau donne? 1: oui, 0 : non"<<endl;
	cin>>choix;cin.ignore();
	if (choix==1)
		rendreInstance(v,creneau);
}

void Vue::rendreInstance(vector<string> v, string creneau){
	int choix;
	bool b;
	if(creneau=="vide")
		creneau=obtenirCreneau();
	if (v.empty())
		v=getControl()->getModel()->getInstancesLibres(creneau);
	cout<<"Quelle instance voulez vous liberer? Donnez son numero."<<endl;
	cin>>choix;cin.ignore();
	b=getControl()->rendreInstance(v[choix],creneau);
	if (b)
		cout<<"Instance liberee avec succes"<<endl;
	else
		cout<<"Probleme lors de la liberation. Contactez votre administrateur. (Avez vous entre le creneau exacte avec lequel la salle a ete reservee?)"<<endl;
}

void Vue::effectuerRecherche(){
	string capacite;
	string genreSalle;
	vector<string>v;
	int choix;
	cout<<"Entrez la capacite minimum recherchee"<<endl;
	cin>>capacite;cin.ignore();
	cout<<"Entrez le genre de salle recherche (cours/tp)"<<endl;
	cin>>genreSalle;
	cin.ignore();
	v=getControl()->getModel()->recherche(capacite,genreSalle);
	if (v.size()==0)
		cout<<"Aucune salle ne correspont a vos criteres"<<endl;
	else{
		cout<<"Voici les salles correspondant a vos criteres: "<<endl;
		afficherVector(v);
		cout<<"Voulez vous reserver une salle? (1 : oui, 0 : non)"<<endl;
		cin>> choix;
		cin.ignore();
		if (choix==1)
			reserverInstance(v);
	}

}



void Vue::menu(){
    int choix=42;
    while ((choix!=9)){
        cout<<endl;
        cout<<"Que voulez vous faire?"<<endl;
        cout<<" 1 : Voir les salles libres sur un creneau."<<endl;
        cout<<" 2 : Effectuer une recherche."<<endl;
        cout<<" 3 : Obtenir les informations d'une salle sur un creneau."<<endl;
        cout<<" 4 : Reserver une salle sur un creneau."<<endl;
        cout<<" 5 : Rendre une salle sur un creneau."<<endl;
        cout<<" 6 : Voir les salles occupees sur un creneau."<<endl;
        cout<<" 7 : Voir toutes les salles enregistrées."<<endl;
        cout<<" 8 : Lire le manuel."<<endl;
        cout<<" 9 : Quitter."<<endl;
        cin>>choix;cin.ignore();
        switch (choix){
            case 1: {
            	ClearScreen();
            	voirInstancesLibres();
                break;}
            case 2: {
            	ClearScreen();
            	effectuerRecherche();
                break;}
            case 3: {
            	ClearScreen();
            	obtenirInfoInstance();
            	break;}
            case 4: {
            	ClearScreen();
            	reserverInstance();
            	break;}
            case 5: {
            	rendreInstance();
            	break;}
            case 6: {
            	ClearScreen();
            	voirInstancesOccupees();
            	break;}
            case 7:{
            	ClearScreen();
            	voirInstances();
            	break;}
            case 8: {
            	ClearScreen();
            	lireManuel("manuel.txt");
            	break;}
            case 9: {
            	break;}
            default:{
            	ClearScreen();
               cout<<"Entree non reconnue"<<endl;}
        }
    }
}

void Vue::afficherVector(vector<string> const v )const{
	for(unsigned int i=0;i<v.size();i++)
		cout<<"instance "<<i<<" : "<<v[i]<<endl;
}

void Vue::ClearScreen()const{
  cout << string( 100, '\n' );
}


int main(){
	Vue *vue=new Vue();
	vue->menu();
	delete(vue);
	return 1;
}
