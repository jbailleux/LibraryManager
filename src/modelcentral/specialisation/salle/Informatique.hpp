
#ifndef INFORMATIQUE_HPP_
#define INFORMATIQUE_HPP_

#include "SalleTp.hpp"
#include "OperatingSystem.hpp"

/*! 	\class Informatique
*	\brief Salle TP de type "Informatique"
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 30/03/15
*	\bug Aucun
*	\warning Aucun
*
*	Cette classe intervient dans le type d une salle. Une salle de type informatique possede un seul attribut specifique, c est le systeme d exploitation(de type OS {Mac,Win,Lin}).
*/

class Informatique: public SalleTp {
private:
	OperatingSystem systemeExpl;
public:
	/*! 	\fn Informatique();
	*	\brief Constructeur
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 26/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*
	*/
	Informatique();

	/*! 	\fn ~Informatique();
	*	\brief Destructeur
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 26/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*
	*/
	~Informatique();
};

#endif /* INFORMATIQUE_HPP_ */
