#ifndef CRENEAU_HPP_
#define CRENEAU_HPP_

#include "Date.hpp"
#include <string>
/*! 	\class Creneau
*	\brief Creneau de deux dates
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 31/03/2015
*	\bug Aucun
*	\warning Aucun
*
*	Un creneau existe a partir de deux dates. Cette classe sert a gerer les reservations. Elle permet de donner les horaires de debut et de fin de reservation.
*/ 
class Creneau {
private:
	Date debut;
	Date fin;

	/*! 	\fn 	std::string deuxiemeDate(std::string const c)const;
	*	\brief Renvoie la deuxieme date presente dans le string donnee en parametre
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 26/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*	\param std::string const c
	*
	*	Retourne un string contenant la seconde date dans le string qu on lui donne en entree.
	*/
	std::string deuxiemeDate(std::string const c)const;

	/*! 	\fn Creneau(Date const debut, Date const fin)const;
	*	\brief 	 Renvoie la premiere date presente dans le string donnee en parametre
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 26/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*	\param std::string const c
	*
	*	Retourne un string contenant la premiere date dans le string qu on lui donne en entree.
	*/
	std::string premiereDate(std::string const c)const;

public:
	Creneau();

/*! 	\fn Creneau(Date const debut, Date const fin)
*	\brief Constructeur avec parametre dates
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 26/04/2015
*	\bug Aucun
*	\warning Aucun
*	\param Date const debut
*	\param Date const fin
*
*	Permet de creer un creneau a partir de deux dates.
*/
	Creneau(Date const debut, Date const fin);

/*! 	\fn ~Creneau()
*	\brief Destructeur
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 26/04/2015
*	\bug Aucun
*	\warning Aucun
*/
	~Creneau();

/*! 	\fn Creneau(std::string const)
*	\brief Constructeur avec parametre string
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 26/04/2015
*	\bug Aucun
*	\warning Aucun
*	\param string const
*
*	Permet de creer un creneau a partir d'un string (formate d une certaine maniere).
*/
	Creneau(std::string const);

	/*! 	\fn setDebut(Date const debut);
	*	\brief setter de Date debut
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 26/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*	\param Date const debut
	*
	*/
	void setDebut(Date const debut);

	/*! 	\fn setFin(Date const fin);
	*	\brief setter de Date fin
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 26/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*	\param Date const debut
	*
	*/
	void setFin(Date const fin);

	/*! 	\fn Date getDebut()const;
	*	\brief getter de Date debut
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 26/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*
	*/
	Date getDebut()const;

	/*! 	\fn Date getFin()const;
	*	\brief getter de Date fin
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 26/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*
	*/
	Date getFin()const;

/*! 	\fn 	std::string to_string()const
*	\brief methode to_string
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 26/04/2015
*	\bug Aucun
*	\warning Aucun
*
*	Permet de renvoyer un creneau en string
*/
	std::string to_string()const;

};

/*! 	\fn verifierChevauchement(Creneau const c1, Creneau const c2)
*	\brief verifie le chevauchement de creneaux
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 24/04/2015
*	\bug Aucun
*	\warning Aucun
*	\param Creneau const
*	\param Creneau const
*
*	Cette fonction permet de verifier que deux creneaux ne se chevauchent pas; elle retourne un booleen: true si il n y a pas de chevauchement, false sinon.
*/
bool verifierChevauchement(Creneau const c1, Creneau const c2);


#endif /* CRENEAU_HPP_ */

