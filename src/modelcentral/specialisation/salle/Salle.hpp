
#ifndef SALLE_HPP_
#define SALLE_HPP_

#include "../../general/InstanceStatique.hpp"
#include "TypeSalle.hpp"
#include <string>
#include "../../general/InstanceAReserver.hpp"
using namespace std;
/*! 	\class Salle
*	\brief Instance de type salle à réserver
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 07/04/2014
*	\bug Aucun
*	\warning Aucun
*
*	La classe Salle est une sous-classe de la classe InstanceAreserver. Elle a des parametres qui la definissent permettant de la distinguer lorsqu on recherche une salle a reserver selon des criteres precis. 
*/ 
class Salle: public InstanceStatique {

private:
	string nomSalle;
	//string batiment;
	int capacite;
	//Tableau tableau;
	TypeSalle typeSalle;
	//bool videoProj;

public:

	/*! 	\fn 	Salle();
	*	\brief Constructeur sans parametre
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 01/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*
	*/
	Salle();

	/*! 	\fn 	Salle(string const nomSalle, int const capacite, TypeSalle const typeSalle);
	*	\brief Constructeur avec parametres
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 01/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*
	*	Construit une salle a partir des parametres donnees en entree.
	*/
	Salle(string const nomSalle, int const capacite, TypeSalle const typeSalle);

	/*! 	\fn 	~Salle();
	*	\brief Destructeur
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 01/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*
	*/
	~Salle();


	/*! 	\fn 	virtual string obtenirInfo(Creneau const creneau)const;
	*	\brief obtenir les informations d'une salle sur un creneau donne
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 01/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*	\param Creneau creneau
	*
	*	Cette fonction permet d obtenir les informations sur un creneau d une salle
	*/
	virtual string obtenirInfo(Creneau const creneau)const;

	/*! 	\fn string getNomSalle()const;
	*	\brief Getter de nomSalle
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 01/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*
	*	Renvoie le nom de la salle.
	*/
	string getNomSalle()const;

	/*! 	\fn int getCapacite()const;
	*	\brief Getter de capacite
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 01/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*
	*	Renvoie la capacite de la salle.
	*/
	int getCapacite()const;

	/*! 	\fn TypeSalle getTypeSalle()const;
	*	\brief Getter de typeSalle
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 01/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*
	*	Renvoie le type de la salle.
	*/
	TypeSalle getTypeSalle()const;

};

#endif /* SALLE_HPP_ */

