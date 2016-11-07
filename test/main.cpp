#include <stdio.h>
#include "../src/Controleur.hpp"
#include "../src/modelcentral/general/InstanceAReserver.hpp"
#include "../src/modelcentral/specialisation/salle/Salle.hpp"
#include <map>
#include "../src/modelcentral/autre/Creneau.hpp"
#include "../src/modelcentral/general/Gestion.hpp"
#include "../src/modelcentral/specialisation/salle/TypeSalle.hpp"
#include "../src/modelcentral/specialisation/salle/TypeTp.hpp"

using namespace std;



bool test_Reservation(){

	//Premier test : dateFin est anterieure à dateDebut ->  on ne peut pas effectuer la réservation de cette salle
	Gestion* g1=new Gestion();
	Salle* s=new Salle("nom",100,TypeSalle("cours"));
	g1->getListeInstances()->insert(make_pair("nom",s));
	bool b1=!(g1->reserver("nom","nomReserveur","15 10"));

	cout<<"Test 1 dateFin est anterieure à dateDebut ->  on ne peut pas effectuer la réservation de cette salle"<<endl;
	if (b1){
		cout<<"Test 1 [OK]"<<endl;
	}else{
		cout<<"Test 1 [NOK]        /!\\"<<endl;
	}

	g1->reserver("nom","nomReserveur","12 15");

	//Deuxieme test : 	Le créneau de dateDebut et dateFin se chevauche avec un créneau où la salle choisie est déjà réservée -> on ne peut pas effectuer la réservation de cette salle, donc on n'appelle pas la fonction « réserverSalle »
	bool b2=!(g1->reserver("nom","nomReserveur","14 17"));
	cout<<"Test 2 Le créneau de dateDebut et dateFin se chevauche avec un créneau où la salle choisie est déjà réservée -> on ne peut pas effectuer la réservation de cette salle, donc on n'appelle pas la fonction « réserverSalle »"<<endl;
	if (b2){
		cout<<"Test 2 [OK]"<<endl;
	}else{
		cout<<"Test 2 [NOK]        /!\\"<<endl;
	}


	delete (g1);
	return (b1&&b2);
}

bool test_Controleur(){

	//Premier test : Une unique salle à charger -> il doit y avoir une seule salle dans la liste
	Controleur * c1= new Controleur();
	bool b1;
	c1->chargementDonnees("donnees01.txt");
	b1=(c1->getModel()->getListeInstances()->size()==1);

	cout<<"Test 1 Une unique salle à charger -> il doit y avoir une seule salle dans la liste"<<endl;
	if (b1){
		cout<<"Test 1 [OK]"<<endl;
	}else{
		cout<<"Test 1 [NOK]        /!\\"<<endl;
	}

	//Second test : Plusieurs salles différentes à charger -> il faut toutes les retrouver dans la liste
	Controleur * c2= new Controleur();
	bool b2;
	c2->chargementDonnees("donnees02.txt");
	map<string,InstanceAReserver*>* m2=c2->getModel()->getListeInstances();
	map<string,InstanceAReserver*>::iterator it2=m2->begin();
	Salle* i1=(Salle*) it2->second; it2++;
	Salle* i2=(Salle*) it2->second;
	//On doit avoir 2 salle dans le modele
	b2=(m2->size()==2);
	b2=b2&&(i1->getCapacite()==100)&&(i1->getNomSalle()=="salle000");
	b2=b2&&(i2->getCapacite()==50)&&(i2->getNomSalle()=="salle001");

	cout<<"Test 2 Plusieurs salles différentes à charger -> il faut toutes les retrouver dans la liste"<<endl;
	if (b2){
		cout<<"Test 2 [OK]"<<endl;
	}else{
		cout<<"Test 2 [NOK]        /!\\"<<endl;
	}

	//Troisieme test : Plusieurs fois la même salle à charger avec un nom identique et des paramètres identiques-> il faut retrouver une seule fois la salle
	Controleur * c3= new Controleur();
	bool b3;
	c3->chargementDonnees("donnees03.txt");
	//On doit avoir 1 salle dans le modele
	b3=(c3->getModel()->getListeInstances()->size()==1);

	cout<<"Test 3 Plusieurs fois la même salle à charger avec un nom identique et des paramètres identiques-> il faut retrouver une seule fois la salle"<<endl;
	if (b3){
		cout<<"Test 3 [OK]"<<endl;
	}else{
		cout<<"Test 3 [NOK]        /!\\"<<endl;
	}

	//Quatrieme test : Plusieurs fois la même salle à charger mais des paramètres différents -> il faut retrouver une seule fois la salle avec les premiers paramètres lus
	Controleur * c4= new Controleur();
	bool b4;
	c4->chargementDonnees("donnees04.txt");
	map<string,InstanceAReserver*>* m4=c4->getModel()->getListeInstances();
	map<string,InstanceAReserver*>::iterator it4=m4->begin();
	Salle* i3=(Salle*) it4->second;

	//On doit avoir 1 salle dans le modele
	b4=(m4->size()==1);
	b4=b4&&(i3->getCapacite()==100);

	cout<<"Test 4 Plusieurs fois la même salle à charger mais des paramètres différents -> il faut retrouver une seule fois la salle avec les premiers paramètres lus"<<endl;
	if (b4){
		cout<<"Test 4 [OK]"<<endl;
	}else{
		cout<<"Test 4 [NOK]        /!\\"<<endl;
	}

	delete(c1);
	delete(c2);
	delete(c3);
	delete(c4);

	return (b1&&b2&&b3&&b4);

}

bool test_obtentionSallesLibres(){

	//Premier test : Une unique salle de libre -> il doit y avoir une seule salle dans la liste retournée
	Gestion* g1=new Gestion();
	Salle* s1=new Salle("nom1",100,TypeSalle("cours"));
	Salle* s2=new Salle("nom2",100,TypeSalle("cours"));
	Salle* s3=new Salle("nom2",100,TypeSalle("cours"));
	g1->getListeInstances()->insert(make_pair("nom1",s1));
	g1->getListeInstances()->insert(make_pair("nom2",s2));
	g1->getListeInstances()->insert(make_pair("nom3",s3));
	g1->reserver("nom1","nomReserveur","10 15");
	g1->reserver("nom2","nomReserveur","9 12");
	bool b1=((g1->getInstancesLibres("8 15")).size()==1);
	cout<<"Test 1 Une unique salle de libre -> il doit y avoir une seule salle dans la liste retournée"<<endl;
	if (b1){
		cout<<"Test 1 [OK]"<<endl;
	}else{
		cout<<"Test 1 [NOK]        /!\\"<<endl;
	}

	//Deuxieme test : si aucune salle n’est libre sur aucun créneau -> on doit retrouver un vecteur vide
	g1->reserver("nom1","nomReserveur","10 15");
	g1->reserver("nom2","nomReserveur","9 12");
	g1->reserver("nom3","nomReserveur","5 19");
	bool b2=((g1->getInstancesLibres("8 15")).size()==0);
	cout<<"Test 2 si aucune salle n’est libre sur aucun créneau -> on doit retrouver un vecteur vide"<<endl;
	if (b2){
		cout<<"Test 2 [OK]"<<endl;
	}else{
		cout<<"Test 2 [NOK]        /!\\"<<endl;
	}

	delete(g1);
	return (b1&&b2);
}

bool test_obtentionSallesOccupees(){

	//Premier test : Une unique salle réservée -> il doit y avoir une seule salle dans la liste retournée
	Gestion* g1=new Gestion();
	Salle* s1=new Salle("nom1",100,TypeSalle("cours"));
	Salle* s2=new Salle("nom2",100,TypeSalle("cours"));
	Salle* s3=new Salle("nom2",100,TypeSalle("cours"));
	g1->getListeInstances()->insert(make_pair("nom1",s1));
	g1->getListeInstances()->insert(make_pair("nom2",s2));
	g1->getListeInstances()->insert(make_pair("nom3",s3));
	g1->reserver("nom1","nomReserveur","10 15");
	bool b1=((g1->getInstancesOccupees("8 15")).size()==1);
	cout<<"Test 1 Une unique salle réservée -> il doit y avoir une seule salle dans la liste retournée"<<endl;
	if (b1){
		cout<<"Test 1 [OK]"<<endl;
	}else{
		cout<<"Test 1 [NOK]        /!\\"<<endl;
	}

	//Deuxieme test : si toutes les salles sont réservées sur tous les créneaux -> on doit retrouver la liste complète des salles
	g1->reserver("nom2","nomReserveur","9 12");
	g1->reserver("nom3","nomReserveur","5 19");
	bool b2=((g1->getInstancesOccupees("8 15")).size()==3);
	cout<<"Test 2 si toutes les salles sont réservées sur tous les créneaux -> on doit retrouver la liste complète des salles"<<endl;
	if (b2){
		cout<<"Test 2 [OK]"<<endl;
	}else{
		cout<<"Test 2 [NOK]        /!\\"<<endl;
	}

	delete(g1);
	return (b1&&b2);
}

bool test_Recherche(){

	//Premier test : Soit il y a une liste d’instances qui satisfait les critères de recherche -> liste filtrée
	Controleur * c= new Controleur();
	c->chargementDonnees("donnees05.txt");
	bool b1=(c->effectuerRecherche("40","cours").size()==2);
	cout<<"Test 2 Soit il y a une liste d’instances qui satisfait les critères de recherche -> liste filtrée"<<endl;
	if (b1){
		cout<<"Test 1 [OK]"<<endl;
	}else{
		cout<<"Test 1 [NOK]        /!\\"<<endl;
	}

	//Deuxieme test : Soit il n’y a pas d’instance qui satisfait la recherche -> message de notification
	bool b2=(c->effectuerRecherche("150","tp").size()==0);
	cout<<"Test 2 Soit il n’y a pas d’instance qui satisfait la recherche -> message de notification dans la vue"<<endl;
	if (b2){
		cout<<"Test 2 [OK]"<<endl;
	}else{
		cout<<"Test 2 [NOK]        /!\\"<<endl;
	}

	delete(c);
	return (b1&&b2);
}

int main(){

	cout<<"########################################"<<endl;
	bool b1=test_Controleur();
	if (b1){
		cout<<"####################"<<endl;
		cout<<"Test Controleur : [OK]"<<endl;
		cout<<"####################"<<endl;
	}
	else{
		cout<<"####################"<<endl;
		cout<<"Test Controleur : [NOK]        /!\\"<<endl;
		cout<<"####################"<<endl;
	}
	cout<<"########################################"<<endl;
	bool b2=test_Reservation();
	if (b2){
		cout<<"####################"<<endl;
		cout<<"Test Reservation : [OK]"<<endl;
		cout<<"####################"<<endl;
	}
	else{
		cout<<"####################"<<endl;
		cout<<"Test Reservation : [NOK]        /!\\"<<endl;
		cout<<"####################"<<endl;
	}
	cout<<"########################################"<<endl;
	bool b3=test_obtentionSallesLibres();
	if (b3){
		cout<<"####################"<<endl;
		cout<<"Test Obtention des salles libres : [OK]"<<endl;
		cout<<"####################"<<endl;
	}
	else{
		cout<<"####################"<<endl;
		cout<<"Test Obtention des salles libres : [NOK]        /!\\"<<endl;
		cout<<"####################"<<endl;
	}
	cout<<"########################################"<<endl;
	bool b4=test_obtentionSallesOccupees();
	if (b4){
		cout<<"####################"<<endl;
		cout<<"Test Obtention des salles occupees : [OK]"<<endl;
		cout<<"####################"<<endl;
	}
	else{
		cout<<"####################"<<endl;
		cout<<"Test Obtention des salles occupees : [NOK]        /!\\"<<endl;
		cout<<"####################"<<endl;
	}
	cout<<"########################################"<<endl;
	bool b5=test_Recherche();
	if (b5){
		cout<<"####################"<<endl;
		cout<<"Test Recherche : [OK]"<<endl;
		cout<<"####################"<<endl;
	}
	else{
		cout<<"####################"<<endl;
		cout<<"Test Recherche : [NOK]        /!\\"<<endl;
		cout<<"####################"<<endl;
	}
	cout<<"########################################"<<endl;


	if(b1&&b2&&b3&&b4&&b5)
		cout<<"Tout est OK"<<endl;
	else
		cout<<"        /!\\        Tout n'est pas OK        /!\\        "<<endl;


	return 0;
}
