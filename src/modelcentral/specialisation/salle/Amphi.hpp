

#ifndef AMPHI_HPP_
#define AMPHI_HPP_

#include "Salle.hpp"

/*! 	\class Amphi
*	\brief Instance à réserver de type amphitheatre
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 07/04/2014
*	\bug Liste des bugs
*	\warning Liste des warning
* 
*	La classe Amphi est une sous-classe de la classe Salle, qui contient des arguments differents. Cette classe nous permet de distinguer le type de Salle Amphi aux autres types de salles (ex: salleTP, bureau, salle de cours...).
*/ 
class Amphi: public Salle {
public:

	/*! 	\fn Amphi();
	*	\brief Constructeur
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 26/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*
	*/
	Amphi();


	/*! 	\fn ~Amphi();
	*	\brief Destructeur
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 26/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*
	*/
	~Amphi();
};

#endif /* AMPHI_HPP_ */
