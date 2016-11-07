
#ifndef SALLETP_HPP_
#define SALLETP_HPP_

#include "Salle.hpp"
#include "TypeTp.hpp"
/*! 	\class SalleTp
*	\brief Instance à réserver de type TP
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 07/04/2014
*	\bug Aucun
*	\warning Aucun
*
*	La classe SalleTp est une sous-classe de la classe Salle, qui contient des arguments differents. Cette classe nous permet de distinguer le type de SalleTp aux autres types de salles (ex: amphi, bureau, salle de cours...)
*/ 
class SalleTp: public Salle {
private:
	TypeTp tp;
public:

	/*! 	\fn SalleTP();
	*	\brief Constructeur
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 26/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*
	*/
	SalleTp();


	/*! 	\fn ~SalleTP();
	*	\brief Destructeur
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 26/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*
	*/
	~SalleTp();
};

#endif /* SALLETP_HPP_ */
