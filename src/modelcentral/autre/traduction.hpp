

#ifndef TRADUCTION_HPP_
#define TRADUCTION_HPP_

#include <string>
#include "../specialisation/salle/TypeSalle.hpp"
#include "../specialisation/salle/TypeSalle.hpp"
#include "Creneau.hpp"
#include "Date.hpp"

using namespace std;





/*! 	\fn intToString
*	\brief traduit un int en string
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 24/04/2015
*	\bug Aucun
*	\warning Aucun
*	\param int const
*
*	Cette fonction permet de convertir une variable de type int en une variable de type string. Elle retournera le string correspondant au int pris en entrée.
*/
string intToString(int const a);

/*! 	\fn typeSalleToString
*	\brief traduit un typeSalle en string
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 24/04/2015
*	\bug Aucun
*	\warning Aucun
*	\param TypeSalle const
*
*	Cette fonction permet de convertir une variable de type typeSalle en une variable de type string. Elle retournera le string correspondant au typeSalle pris en entrée.
*/
string typeSalleToString(TypeSalle const);

/*! 	\fn stringToTypeSalle
*	\brief traduit un string en typeSalle
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 24/04/2015
*	\bug Aucun
*	\warning Aucun
*	\param string const
*
*	Cette fonction permet de convertir une variable de type string en une variable de type typeSalle. Elle retournera le typeSalle correspondant au string pris en entrée.
*/
TypeSalle stringToTypeSalle(string const str);

/*! 	\fn boolToString
*	\brief traduit un booleen en string
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 24/04/2015
*	\bug Aucun
*	\warning Aucun
*	\param bool const
*
*	Cette fonction permet de convertir une variable de type bool en une variable de type string. Elle retournera le string correspondant au bool pris en entrée.
*/
string boolToString(bool const);


#endif /* TRADUCTION_HPP_ */
