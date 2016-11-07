

#ifndef INSTANCEMOBILE_HPP_
#define INSTANCEMOBILE_HPP_

#include "InstanceAReserver.hpp"
#include "../autre/Creneau.hpp"
#include <vector>

/*! 	\class InstanceMobile
*	\brief Instance Mobile
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 01/04/2015
*	\bug Aucun
*	\warning Aucun
*
*	Une instance designe de maniere generale un bien pouvant ere reserve par un reserveur. Une instance mobile peut quant a elle se deplacer, etre reservee et deposee à differents endroits.
*/
class InstanceMobile : public InstanceAReserver {
private:
	vector<string> lieuDepart;
	vector<string> lieuArrivee;
public:

	/*! 	\fn InstanceMobile();
	*	\brief Constructeur
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 26/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*/
	InstanceMobile();

	/*! 	\fn ~InstanceMobile();
		*	\brief Destructeur
		*	\author BAILLEUX COURTOIS MARKOVSKI
		*	\version 1.0
		*	\date 26/04/2015
		*	\bug Aucun
		*	\warning Aucun
		*/
	~InstanceMobile();

/*! 	\fn 	bool reserver(string const nomReserveur, Creneau creneau, string lieuDepart, string lieuArrivee);
*	\brief reserver l instance sur un creneau
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 01/04/2015
*	\bug Aucun
*	\warning Aucun
*	\param string const nomReserveur
*	\param Creneau creneau
*	\param string lieuDepart
*	\param string lieuArrivee
*
*	Cette fonction permet de reserver une instance mobile sur un certain creneau donne en parametre, en indiquant le lieu de depart et le lieu d arrivee.
*/
	bool reserver(string const nomReserveur, Creneau creneau, string lieuDepart, string lieuArrivee);

	/*! 	\fn	virtual string obtenirInfo(Creneau const creneau)const=0;
	*	\brief obtenir les informations
	*	\author BAILLEUX COURTOIS MARKOVSKI
	*	\version 1.0
	*	\date 26/04/2015
	*	\bug Aucun
	*	\warning Aucun
	*
	*	Renvoie les informations d une instance statique. Methode virtuelle devant etre redefinie dans les classes heritieres.
	*/
	virtual string obtenirInfo(Creneau const creneau)const=0;

};

#endif /* INSTANCEMOBILE_HPP_ */
