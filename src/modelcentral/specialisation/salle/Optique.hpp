
#ifndef OPTIQUE_HPP_
#define OPTIQUE_HPP_

#include "SalleTp.hpp"

/*! 	\class Optique
*	\brief Salle TP de type Optique
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 30/03/15
*	\bug Aucun
*	\warning Aucun
*
* 	Cette classe intervient dans le type d'une salle. Une salle de type Optique ne possede pas d attribut specifique pour l'instant.
*	Cette classe peut acquerir des attributs qui seront specifiques a une salle de TP de type Optique.
*/

class Optique: public SalleTp {
public:

	/*! 	\fn Optique();
	*	\brief Constructeur
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 26/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*
	*/
	Optique();

	/*! 	\fn ~Optique();
	*	\brief Destructeur
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 26/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*
	*/
	~Optique();
};

#endif /* OPTIQUE_HPP_ */
