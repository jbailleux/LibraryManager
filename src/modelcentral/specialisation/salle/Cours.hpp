
#ifndef COURS_HPP_
#define COURS_HPP_

#include "Salle.hpp"
/*! 	\class Cours
*	\brief Salle de cours
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 07/04/2014
*	\bug Aucun
*	\warning Aucun
*
*	La classe Cours est une sous-classe de Salle; qui contient des arguments differents. Cette classe nous permet de distinguer le type de Salle Amphi aux autres types de salles (ex: salleTP, bureau, amphi...)
*/ 
class Cours: public Salle {
public:

	/*! 	\fn Cours();
	*	\brief Constructeur
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 26/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*
	*/
	Cours();

	/*! 	\fn ~Cours();
	*	\brief Destructeur
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 26/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*
	*/
	~Cours();
};

#endif /* COURS_HPP_ */

