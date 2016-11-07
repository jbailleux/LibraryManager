

#ifndef GESTION_HPP_
#define GESTION_HPP_

#include <map>
#include <vector>
#include "InstanceAReserver.hpp"
#include "../autre/Creneau.hpp"
#include <string>
#include "../specialisation/salle/TypeSalle.hpp"
using namespace std;

/*! 	\class Gestion
*	\brief classe de gestion de reservation
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 24/04/2015
*	\bug Aucun
*	\warning Aucun
*
*	Cette classe Gestion fera parti du modele de notre projet. Elle contient toutes les methodes permettant la reservation d une instance quelconque; c est a partir de cette classe que nous gererons nos reservations. 
*/

class Gestion {
private:
	map<string,InstanceAReserver*>* listeInstances;
public:

	/*! \fn 	Gestion();
	*	\brief Constructeur sans parametre
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 01/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*/
	Gestion();

	/*! \fn 	~Gestion();
	*	\brief Destructeur
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 01/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*/
	~Gestion();

/*! \fn 	vector<string> recherche(string const capacite, string const genreSalle);
*	\brief recherche d instances selon critere (version publique)
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 01/04/2015
*	\bug Aucun
*	\warning Aucun
*	\param string const capacite
*	\param string const genreSalle
*
*	Cette fonction permet d obtenir une liste d instances correspondant a une liste de criteres choisis au prealable.
*	Elle fait appelle à la methode privee portant le meme nom.
*/
	vector<string> recherche(string const capacite, string const genreSalle);

/*! \fn InstanceAReserver* getInstance(string const nomInstance);
*	\brief obtenir une instance
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 01/04/2015
*	\bug Aucun
*	\warning Aucun
*	\param string nomInstance
*
*	Cette fonction permet d'obtenir l instance a partir de son nom.
*/
	InstanceAReserver* getInstance(string const nomInstance);

/*! 	\fn map<string,InstanceAReserver*>* getListeInstances()const;
*	\brief Donne la liste de nos instances
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 01/04/2015
*	\bug Aucun
*	\warning Aucun
*
*	Cette fonction permet d obtenir le map d'instance.
*/
	map<string,InstanceAReserver*>* getListeInstances()const;

/*! \fn vector<string> getListeNomInstances()const;
*	\brief Donne la liste des noms de nos instances
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 26/04/2015
*	\bug Aucun
*	\warning Aucun
*
*	Cette fonction permet d obtenir la liste des noms d instance.
*/
	vector<string> getListeNomInstances()const;

/*! 	\fn vector<string> getInstancesOccupees(string const creneau);
*	\brief Donne les instances occupees
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 01/04/2015
*	\bug Aucun
*	\warning Aucun
*	\param String const creneau
*
*	Cette fonction publique permet d'obtenir les instances occupees a partir d'un creneau donnee sous forme de string.
*/
	vector<string> getInstancesOccupees(string const creneau);

/*! 	\fn vector<string> getInstancesLibres(string const creneau);
*	\brief Obtenir les instances libres
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 01/04/2015
*	\bug Aucun
*	\warning Aucun
*	\param String const creneau
*
*	Cette fonction publique permet d obtenir les instances libres a partir d un creneau donne sous forme de string.
*/
	vector<string> getInstancesLibres(string const creneau);

/*! 	\fn bool reserver(string nomSalle, string const nomReserveur, string const creneau);
*	\brief reserver une instance
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 01/04/2015
*	\bug Aucun
*	\warning Aucun
*	\param InstanceAReserver instance
*	\param string const nomReserveur
*	\param Creneau const creneau
*
*	Cette fonction permettra, lors de son appel, de reserver une instance a une date donnee pendant une duree donnee, en fonction du nom de la personne qui reserve. On ne pourra reserver que des instances libres (pas reservees).
*	Pour reserver une instance, on appellera la fonction reserver(String const nomInstance, String const nomReserveur, Creneau const creneau) de la classe Gestion. Cette methode prend en argument le nom de la salle,  une chaine de caracteres qui represente le nom de la personne qui reserve, et un creneau. Cette fonction publique reserver de notre classe "Gestion",qui utilisera une fonction getInstance(nom: string):Instance qui permet d obtenir la salle correspondant au nom qui lui est donne en entree,appellera notre fonction privee reserver reserver(Instance instance, String const nomReserveur, Creneau const creneau) de cette meme classe.
*	Il sera alors verifie si l instance que l on souhaite reserver est libre aux horaires donnes.
*	Pour une instance mobile, il faudra egalement prendre en argument un lieu de depart et un lieu d arrivee, qui correspondent au lieu ou on reserve notre instance mobile et au lieu ou on rend notre instance mobile.
*	Cette fonction retournera un booleen, pour savoir si l operation a reussi (true) ou non (false).
*/
	bool reserver(string nomSalle, string const nomReserveur, string const creneau);


/*! 	\fn 	bool liberer(string nomSalle, string creneau);
*	\brief libere une InstanceAReserver
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 01/04/2015
*	\bug Aucun
*	\warning Aucun
*	\param string instance
*	\param Creneau const creneau
*
*	Cette fonction permet de liberer une InstanceAReserver en donnant en entree son nom.
* 	Pour liberer une instance, nous ferons appel a une fonction qu on appellera avant la fonction de reservation de salle. Cette fonction permettra de verifier que les dates proposees pour la liberation sont valides (c est-a-dire que dateFin n'est pas anterieure a dateDebut, et que le creneau de dates proposees ne se chevauche pas avec un creneau ou la salle choisie est deja reservee).
*/
	bool liberer(string nomSalle, string creneau);

/*! 	\fn string obtenirInfo(string const nomInstance, string const creneau);
*	\brief obtenir les informations d une instance
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 01/04/2015
*	\bug Aucun
*	\warning Aucun
*	\param nomInstance instance
*	\param Creneau creneau
*
*	Cette fonction permet d obtenir les informations sur un creneau d une instance a partir de son nom. Elle fait appel a la methode privee du meme nom.
*/
	string obtenirInfo(string const nomInstance, string const creneau);


private:
/*! 	\fn bool reserver(InstanceAReserver* instance,string const nomReserveur, Creneau const creneau);
*	\brief reserver une instance
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 01/04/2015
*	\bug Aucun
*	\warning Aucun
*	\param InstanceAReserver instance
*	\param string const nomReserveur
*	\param Creneau const creneau
*
*	Cette fonction permet de reserver une instance statique ( pas de lieuDepart ni de lieuArrivee) sur un certain creneau apres avoir verifie que cette derniere est bien libre.
*	Pour reserver une instance, nous ferons appel a une fonction qu on appellera avant la fonction de reservation de salle. Cette fonction permettra de verifier que les dates proposees pour la reservation sont valides (c est-a-dire que dateFin n est pas anterieure a dateDebut, et que le creneau de dates proposees ne se chevauche pas avec un creneau ou la salle choisie est deja reservee).
*	reserver (parametres) de la classe Gestion va recuperer l instance associee au nom donne en entree, pour ensuite appeler la methode reserver de la classe InstanceAReserver.
*
* 	Methode Verification reservation salle :
* 	Cas a tester :
*	- dateFin est anterieure a dateDebut -> on ne peut pas effectuer la reservation de cette salle, donc on n appelle pas la fonction "reserverSalle".
*	- une des dates est negative -> la date n'est pas valide, donc on n'appelle pas la fonction "reserverSalle".
*	- Le creneau de dateDebut et dateFin se chevauche avec un creneau ou la salle choisie est deja reservee -> on ne peut pas effectuer la reservation de cette salle, donc on n appelle pas la fonction "reserverSalle".
*	- La salle que l on veut reserver n est pas libre sur les horaires choisies -> on ne peut pas effectuer la reservations de cette salle.
*	- La salle choisie est libre sur le creneau choisi -> la reservation de la salle peut etre faite, on appelle donc la fonction reserverSalle().
*
*	Reserver une salle :
*	Cas a tester :
*	- La salle recherchee n existe pas (c est-a-dire aucune salle ne correspond aux criteres passes en parametres de la fonction reserver de notre classe Gestion) -> on ne peut pas effectuer de reservation.
*	- Le nom de la personne qui souhaite reserver une salle est trop long -> pas de probleme
*	- Le nom de la personne qui souhaite reserver est nulle -> on ne peut pas effectuer la reservation la fonction retourne false.
*	- On souhaite reserver une salle, et la verification de reservation de salle a ete faite avec succes -> la reservation de salle se fait avec succes.
*/
	bool reserver(InstanceAReserver* instance,string const nomReserveur, Creneau const creneau);

/*! 	\fn bool liberer(InstanceAReserver* instance, Creneau creneau);
*	\brief (privee) liberer une InstanceAReserver
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 01/04/2015
*	\bug Aucun
*	\warning Aucun
*	\param InstanceAReserver instance
*	\param Creneau const creneau
*
*	Cette fonction permet de liberer une InstanceAReserver.
* 	Pour liberer une instance, nous ferons appel a une fonction qu on appellera avant la fonction de reservation de salle. Cette fonction permettra de verifier que les dates proposees pour la liberation sont valides (c'est-a-dire que dateFin n'est pas anterieure a dateDebut, et que le creneau de dates proposees ne se chevauche pas avec un creneau ou la salle choisie est deja reservee).
*	liberer (parametres) de la classe Gestion, va recuperer l'instance associee au nom donne en entree, pour ensuite appeler la methode liberer de la classe InstanceAReserver.
* 
*	Verification liberation salle :
*	Cas a tester :
*	Identique a verification reservation salle.
*
*	Reserver une salle :
*	Cas a tester :
*	- La salle recherchee n existe pas (c est-a-dire aucune salle ne correspond aux criteres passes en parametres de la fonction reserver de notre classe Gestion) -> on ne peut pas liberer cette salle inexistante.
*	- Le nom de la personne qui souhaite reserver une salle est trop long -> pas de probleme
*	- Le nom de la personne qui souhaite liberer est vide(NULL) -> on ne peut pas effectuer la reservation ; la fonction retourne false.
*	- On souhaite liberer une salle, et la verification de liberation de salle a ete faite avec succes -> la liberation de salle se fait avec succes.
*/
bool liberer(InstanceAReserver* instance, Creneau creneau);

/*! 	\fn string obtenirInfo(InstanceAReserver* const instance, Creneau const creneau)const;
*	\brief (privee) obtenir les informations d une instance
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 01/04/2015
*	\bug Aucun
*	\warning Aucun
*	\param InstanceAReserver instance
*	\param Creneau creneau
*
*	Cette fonction permet d obtenir les informations sur un creneau d une instance.
*	Ces deux methodes sont identiques sauf le type du parametre d entree. Dans le cas de la methode de la classe Gestion la fonction prend en entree une chaine de caracteres. Et dans la classe Instance la methode s applique sur instance directement en passant en creneau en entree.
*	Ici nous ne considerons pas les problemes pouvant etre lies au creneau, ceux-ci etant traites autre part dans le rapport.
*
*	Cas a tester :
*	- Un cas classique avec une instance valide en entree -> pas de probleme
*	- Une requete vide i.e un parametre d'entree Null -> message d'erreur
*	- Instance non existante -> message d'erreur
*/
string obtenirInfo(InstanceAReserver* const instance, Creneau const creneau)const;

/*! 	\fn vector<string> recherche(int const capacite, TypeSalle const genreSalle);
*	\brief recherche d instances selon critere
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 01/04/2015
*	\bug Aucun
*	\warning Aucun
*	\param int const capacite
*	\param TypeSalle const genreSalle
*
*	Cette fonction permet d obtenir une liste d instances correspondant a une liste de criteres choisis au prealable.
*	Cas a tester :
*	- Le vecteur listeCriteres vide -> message d erreur
*	- Le vecteur listeCriteres avec trop de criteres.
*	- Un cas classique avec un vecteur listeCriteres valide en entree. Deux cas de figure possible : soit il y a une liste d instances qui satisfait les criteres de recherche -> liste filtre, soit il n y a pas d instance qui satisfait la recherche -> message de notification.
*/
	vector<string> recherche(int const capacite, TypeSalle const genreSalle);

/*! 	\fn 	vector<string> getInstancesLibres(Creneau const creneau) ;
*	\brief obtenir les instances libres
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 01/04/2015
*	\bug Aucun
*	\warning Aucun
*	\param Creneau const creneau
*
*	Cette fonction permet d obtenir la liste d instances libres au creneau donne
*	Cas a tester :
*	- Le vecteur listeCriteres vide -> message d erreur.
*	- Le vecteur listeCriteres avec trop de criteres.
*	- Un cas classique avec un vecteur listeCriteres valide en entree. Deux cas de figure possible : soit il y a une liste d instances qui satisfait les criteres de recherche -> liste filtre, soit il n y a pas d instance qui satisfait la recherche -> message de notification.
*/
	vector<string> getInstancesLibres(Creneau const creneau) ;

/*! 	\fn 	vector<string> getInstancesOccupees(Creneau const creneau);
*	\brief obtenir les instances Occupees
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 01/04/2015
*	\bug Aucun
*	\warning Aucun
*	\param Creneau const creneau
*
*	Cette fonction permet d obtenir la liste d instances occupees au creneau donne
*	Cas a tester :
*	Ici nous ne considerons pas les problemes pouvant etre lies au creneau, ceux-ci etant traites autre part dans le rapport.
*	- Une unique salle de libre -> il doit y avoir une seule salle dans la liste retournee.
*	- Plusieurs salles differentes libres -> il faut toutes les retrouver dans la liste retournee.
*	- Aucune salle libre sur aucun creneau-> on doit retrouver un vecteur vide.
*	- Toutes les salles sont libres sur tous les creneaux-> on doit retrouver la liste complete des salles.
*	- Aucune salle est libre sur ce creneau -> on doit retrouver un vecteur vide.
*	- Toutes les salles sont libres sur ce creneau -> on doit retrouver la liste complete des salles.
*	- La methode passe ces differents tests -> elle sera alors valide pour le programme.
*/
	vector<string> getInstancesOccupees(Creneau const creneau);
};

#endif /* GESTION_HPP_ */
