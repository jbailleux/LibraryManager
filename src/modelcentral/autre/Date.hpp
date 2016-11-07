#ifndef DATE_HPP_
#define DATE_HPP_
#include <string>

/*! 	\class Date
*	\brief Date
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 31/03/2015
*	\bug Pas de bugs
*	\warning Pas de warning
*
*	Ici une date est simplement une heure. Cet aspect pourra etre complete par plus de champs par la suite si necessaire, par exemple : annee, mois, jour, heure, minute, seconde etc..
*/ 
class Date {
private:
	int heure;
public:
	Date();

	/*! 	\fn 	Date(std::string const heure);
	*	\brief Constructeur avec parametre std::string
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 26/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*	\param std::string const heure
	*
	*	Permet de creer une date a partir d un string formate.
	*/
	Date(std::string const heure);

	/*! 	\fn 	Date(int const heure);
	*	\brief Constructeur avec parametre int
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 26/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*	\param int const heure
	*
	*	Permet de creer une date a partir d un int.
	*/
	Date(int const a);

	/*! 	\fn 	void setHeure(int const heure);
	*	\brief setter de heure
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 26/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*	\param int const heure
	*
	*/
	void setHeure(int const heure);

	/*! 	\fn int getHeure()const;
	*	\brief getter de heure
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 26/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*
	*/
	int getHeure()const;
	
	/*! 	\fn to_string
		*	\brief affichage de la date
		*	\author BAILLEUX COURTOIS MARKOVSKI
		*	\version 1.0
		*	\date 24/04/2015
		*	\bug Pas de bugs
		*	\warning Pas de warning
		*
		*	Cette fonction permet d afficher l heure dans le terminal.
		*/
	std::string to_string()const;
};

#endif /* DATE_HPP_ */

