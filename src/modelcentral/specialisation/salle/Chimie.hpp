

#ifndef CHIMIE_HPP_
#define CHIMIE_HPP_

#include "SalleTp.hpp"

/*! 	\class Chimie
*	\brief Salle TP de type Chimie
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 30/03/15
*	\bug Aucun
*	\warning Aucun
*
*	Cette classe intervient dans le type d une salle. Une salle de type chimie ne possede pas d attribut specifique pour l'instant.
*	Cette classe peut acquerir des attributs qui seront specifiques a une salle de TP de type chimie.
*/

class Chimie: public SalleTp {
public:

	/*! 	\fn Chimie();
	*	\brief Constructeur
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 26/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*
	*/
	Chimie();


	/*! 	\fn ~Chi()mie;
	*	\brief Destructeur
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 26/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*
	*/
	~Chimie();
};

#endif /* CHIMIE_HPP_ */
