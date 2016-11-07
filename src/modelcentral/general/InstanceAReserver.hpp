

#ifndef INSTANCEARESERVER_H_
#define INSTANCEARESERVER_H_

#include <iostream>
#include <string>
#include <vector>
#include "../autre/Creneau.hpp"

using namespace std;


/*! 	\class InstanceAReserver
*	\brief Instance generale
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 01/04/2015
*	\bug Pas de bug
*	\warning Pas de warning
* 
*	Une instance designe de maniere generale un bien pouvant etre reserve par un reserveur.
*/
class  InstanceAReserver {
private:
	string nom;
	vector<string>* nomReserveur;
	vector<Creneau>* dateReservation;
public:

	/*! 	\fn		vector<string>* getNomReserveur();
	*	\brief obtenir la liste de nom de reserveur
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 01/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*
	*	Renvoie l'adresse du vecteur contenant les noms de reseveurs.
	*/
	vector<string>* getNomReserveur();


	/*! 	\fn		vector<Creneau>* getDateReservation();
	*	\brief obtenir la liste de nom de reserveur
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 01/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*
	*	Renvoie l'adresse du vecteur contenant les dates de reservation.
	*/
	vector<Creneau>* getDateReservation();

	/*! 	\fn	InstanceAReserver();
	*	\brief Constructeur
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 01/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*/
	InstanceAReserver();

	/*! 	\fn	~InstanceAReserver();
	*	\brief Destructeur
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 01/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*/
	~InstanceAReserver();

/*! 	\fn bool estLibre(Creneau const creneau) const;
*	\brief Dit si l'instance est libre sur ce creneau
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 01/04/2015
*	\bug Aucun
*	\warning Aucun
*	\param Creneau const creneau
*
*	Cette fonction permet de dire si l instance est libre sur ce creneau ou non. Elle retourne true si l instance est libre et false sinon.
*/
	bool estLibre(Creneau const creneau) const;

/*! 	\fn bool reserver(string const nomReserveur, Creneau const creneau);
*	\brief reserver l'instance sur un creneau
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 01/04/2015
*	\bug Aucun
*	\warning Aucun
*	\param string const nomReserveur
*	\param Creneau const creneau
*
*	Cette fonction permet de reserver l instance sur un certain creneau donne en parametre. Elle retourne un booleen pour dire si la reservation s est bien deroulee.
*/
	bool reserver(string const nomReserveur, Creneau const creneau);

/*! 	\fn	bool liberer(Creneau const creneau);
*	\brief reserver l instance sur un creneau
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 01/04/2015
*	\bug Aucun
*	\warning Aucun
*	\param Creneau const creneau
*
*	Cette fonction permet de liberer l instance d un certain creneau donne en parametre, pour qu elle puisse etre reservee sur ce creneau. Elle retourne un booleen pour dire si la reservation s est bien deroulee.
*/
	bool liberer(Creneau const creneau);

/*! 	\fn 	virtual string obtenirInfo(Creneau const creneau)const=0;
*	\brief Obtention des informations d'une instance
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 30.03.15
*	\bug Aucun
*	\warning Aucun
*	\param Creneau const creneau
*
*	Cette methode permet a l utilisateur, a partir d'un creneau, de recevoir les informations detaillees de l instance en question. Par exemple pour une salle donne il va obtenir si la salle est une salle de Tp, quel type de tableau elle possede etc.
*/ 
	virtual string obtenirInfo(Creneau const creneau)const=0;

};

#endif /* INSTANCEARESERVER_H_ */
