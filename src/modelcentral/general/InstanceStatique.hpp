

#ifndef INSTANCESTATIQUE_HPP_
#define INSTANCESTATIQUE_HPP_

#include "InstanceAReserver.hpp"
#include "../autre/Creneau.hpp"

/*! 	\class InstanceStatique
*	\brief Instance Statique
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 01/04/2015
*	\bug Pas de bugs
*	\warning Pas de warning
* 
*	Une instance designe de maniere generale un bien pouvant etre reserve par un reserveur. Une instansce statique est une instance ne bougeant pas, et une instance mobile est une instance ayant un lieu de location different du lieu de retour (ex: une voiture...).
*/
class InstanceStatique: public InstanceAReserver {
public:

	/*! 	\fn InstanceStatique();
	*	\brief Constructeur
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 26/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*/
	InstanceStatique();

	/*! 	\fn InstanceStatique();
	*	\brief Destructeur
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 26/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*/
	~InstanceStatique();

	/*! 	\fn	virtual string obtenirInfo(Creneau const creneau)const=0;
	*	\brief obtenir les informations
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 26/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*
	*	Renvoie les informations d une instance statique. Methode virtuelle devant etre redefinie dans les classes heritieres.
	*/
	virtual string obtenirInfo(Creneau const creneau)const=0;

};

#endif /* INSTANCESTATIQUE_HPP_ */
