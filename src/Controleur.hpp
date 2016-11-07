

#ifndef CONTROLEUR_HPP_
#define CONTROLEUR_HPP_

#include "modelcentral/general/Gestion.hpp"
#include <string>
#include <iostream>
#include <dirent.h>
#include <fstream>
#include <sstream>
using namespace std;

/*! 	\class Controleur
 *	\brief Controleur permettant de manipuler une instance Gestion
 *	\author BAILLEUX COURTOIS MARKOVSKI
 *	\version 1.0
 *	\date 30/03/15
 *	\bug Aucun
 *
 *	Cette classe permet de controler une instance de type Gestion, et possede notamment une methode permettant de charger la liste de salle a manipuler dans le programme.
 *
 */
class Controleur {

private:
	Gestion* model;
public:

/*! 	\fn Controleur
*	\brief Constructeur sans parametre
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 31/03/2015
*	\bug Aucun
*	\warning Aucun
*
*	Constructeur sans parametre. Cree une instance de type Gestion.
*/
	Controleur();

/*! 	\fn ~Controleur()
*	\brief Destructeur
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 31/03/2015
*	\bug Aucun
*	\warning Aucun
*
*	Destructeur.
*/
	~Controleur();

/*! 	\fn getModel()
*	\brief obtenir l adresse du modele
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 31/03/2015
*	\bug Aucun
*	\warning Aucun
* 
*Renvoie l adresse du modele utilise
*/
	Gestion* getModel();


/*! 	\fn chargementDonnees(string const nomFichier)
*	\brief chargement des salles
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 31/03/2015
*	\bug Aucun
*	\warning Aucun
*	\param string const nomFichier
* 
*	La fonction permet de charger les differentes salles presentes dans un fichier et de les ajouter a la liste de salle de la classe Gestion.
*	
* 	Cas a tester :
*	- Aucun nom de fichier renseigne
*	- Aucune instance Gestion donnee en entree
*	- Fichier a charger non formate comme il faut
*	- Ceux sont les cas resumant les differents cas que l on peut etre amene a croiser lors d une utilisation normale du programme.
*	- Une unique salle a charger -> il doit y avoir une seule salle dans la liste
*	- Plusieurs salles differentes a charger -> il faut toutes les retrouver dans la liste
*	- Plusieurs fois la meme salle a charger avec un nom identique et des parametres identiques -> il faut retrouver une seule fois la salle
*	- Plusieurs fois la meme salle a charger mais des parametres differents -> il faut retrouver une seule fois la salle avec les premiers parametres lus
*	- Fichier non trouve -> on renvoie FALSE
*	- Fichier a charger vide -> la liste d instance de la Gestion est vide, on renvoie FALSE
*/
	bool chargementDonnees(string const nomFichier);


/*! 	\fn 	vector<string> getInstanceLibres(string const creneau);
*	\brief obtenir les instances libres du modele
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 31/03/2015
*	\bug Aucun
*	\warning Aucun
*	\param string const creneau
*
*	Renvoie tous les nom d instances libres (sur un creneau) du modele.
*/
	vector<string> getInstanceLibres(string const creneau);

/*! 	\fn 	vector<string> getInstanceOccupees(string const creneau);
*	\brief obtenir les instances occupees du modele
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 31/03/2015
*	\bug Aucun
*	\warning Aucun
*	\param string const creneau
*
*	Renvoie tous les noms d instances occupees (sur un creneau) du modele.
*/
	vector<string> getInstanceOccupees(string const creneau);

/*! 	\fn effectuerRecherche(string const capacite, string const typeSalle)
*	\brief Effectuer une recherche sur les instances du modele
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 31/03/2015
*	\bug Aucun
*	\warning Aucun
*	\param string const capacite
*	\param string const typeSalle
*
*	Renvoie tous les noms des instances dont les criteres correspondent.
*/
	vector<string> effectuerRecherche(string const capacite, string const typeSalle);

/*! 	\fn obtenirInformationInstance(string const nomInstance, string const creneau)
*	\brief Obtenir les informations d une instance
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 26/04/2015
*	\bug Aucun
*	\warning Aucun
*	\param string const nomInstance
*	\param string const creneau
*
*	Renvoie les informations de l instance correspondant au nom donnee en entree pour le creneau donnee.
*/
	string obtenirInformationInstance(string const nomInstance, string const creneau);

/*! 	\fn reserverInstance(string const nomInstance,string const nomReserveur, string const creneau)
*	\brief reserver une instance
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 26/04/2015
*	\bug Aucun
*	\warning Aucun
*	\param string const nomInstance
*	\param string const nomReserveur
*	\param string const creneau
*
*	Reserve l instance dont on donne le nom sur un creneau et pour un reserveur.
*/
	bool reserverInstance(string const nomInstance,string const nomReserveur, string const creneau);

/*! 	\fn rendreInstance(string const nomInstance, string const creneau)
*	\brief rendre une instance
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 26/04/2015
*	\bug Aucun
*	\warning Aucun
*	\param string const nomInstance
*	\param string const creneau
*
*	Rend l instance dont on donne le nom pour un creneau donnee.
*/
	bool rendreInstance(string const nomInstance, string const creneau);
};
#endif /* CONTROLEUR_HPP_ */

