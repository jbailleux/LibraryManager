
#ifndef ELECTRONIQUE_HPP_
#define ELECTRONIQUE_HPP_

#include "SalleTp.hpp"

/*! 	\class Electronique
 *	\brief Salle TP de type Electronique
 *	\author BAILLEUX COURTOIS MARKOVSKI
 *	\version 1.0
 *	\date 30/03/15
 *	\bug Aucun
 *	\warning Aucun
 *
 *	Cette classe intervient dans le type d'une salle. Une salle de type Electronique ne possede pas d attribut specifique pour l instant.
 *	Cette classe peut acquerir des attribut qui seron specifique a une salle de TP de type Electronique.
 */

class Electronique: public SalleTp {
public:

	/*! 	\fn Electronique();
	*	\brief Constructeur
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 26/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*
	*/
	Electronique();


	/*! 	\fn ~Electronique();
	*	\brief Destructeur
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 26/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*
	*/
	~Electronique();
};

#endif /* ELECTRONIQUE_HPP_ */
