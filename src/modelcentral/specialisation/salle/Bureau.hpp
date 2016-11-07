

#ifndef BUREAU_HPP_
#define BUREAU_HPP_

#include "Salle.hpp"
#include <list>
#include <string>
using namespace std;

/*! 	\class Bureau
*	\brief Salle de type Bureau
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 07/04/2014
*	\bug Aucun
*	\warning Aucun
*
*	La classe Bureau est une sous-classe de Salle; elle ne peut pas etre reservee mais seulement consultee. Contrairement aux autres salles, elle appartient a une Personne (personne qui travaille dans ce bureau).
*/ 
class Bureau: public Salle {
private:
	list<string> professeurs;
public:

	/*! 	\fn Bureau();
	*	\brief Constructeur
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 26/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*
	*/
	Bureau();

	/*! 	\fn ~Bureau();
	*	\brief Destructeur
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 26/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*
	*/
	~Bureau();

};

#endif /* BUREAU_HPP_ */

