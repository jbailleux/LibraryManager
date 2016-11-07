/*
 * TypeSalle.hpp
 *
 *  Created on: 24 mars 2015
 *      Author: jeremy
 */

#ifndef TYPESALLE_HPP_
#define TYPESALLE_HPP_
#include <string>

/*! 	\class TypeSalle
*	\brief Une salle peut etre de type: amphi/tp/bureau/cours
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 30/03/15
*	\bug Aucun
*	\warning Aucun
*
*	TypeSalle est un attribut de la classe Salle.
*	Dans cette classe-enumeration il y a les differentes type de salles qui existent. Ces derniers peuvent etre de type, soit amphitheatre (amphi), soit TP(tp), soit de bureau d'un prof (bureau) ou une salle de cours habituelle(cours).
*/

class TypeSalle
{
public:
 	enum TypeDeSalleExistant{
	tp,
	cours,
//	amphi,
//	bureau
};
	TypeDeSalleExistant type;

	/*! 	\fn 	std::string to_string()const;
	*	\brief Transforme TypeSalle en string
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 26/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*
	*	Renvoie un string permettant d'identifier un typeSalle.
	*/
	std::string to_string()const;

	/*! 	\fn	void setType(int const t);
	*	\brief setter de type
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 26/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*	\param int const t
	*
	*	Setter de type.
	*/
	void setType(int const t);

	/*! 	\fn	std::string getType() const;
	*	\brief getter de type
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 26/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*
	*/
	std::string getType() const;

	/*! 	\fn TypeSalle();
	*	\brief Constructeur
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 26/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*
	*/
	TypeSalle();

	/*! 	\fn TypeSalle(std::string const);
	*	\brief Constructeur avec pamametre
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 26/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*	\param std::string const type
	*/
	TypeSalle(std::string const);


private:

};

#endif /* TYPESALLE_HPP_ */
