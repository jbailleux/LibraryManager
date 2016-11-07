

#ifndef VUE_HPP_
#define VUE_HPP_

#include "modelcentral/general/Gestion.hpp"
#include "Controleur.hpp"
#include <vector>

/*! 	\class Vue
 *	\brief Vue sur le Controleur
 *	\author BAILLEUX COURTOIS MARKOVSKI
 *	\version 1.0
 *	\date 31/03/15
 *	\bug Aucun
 *
 *	Cette classe est la classe permettant d avoir une vue sur le controleur et le modele centrale.
 */
class Vue {
private:
	Controleur* control;

public:

/*! 	\fn Vue()
*	\brief Constructeur
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 26/04/2015
*	\bug Aucun
*	\warning Aucun
*
*	Constructeur sans parametre. Il se charge de creer le controleur et de lui faire charger les donnees necessaire au fonctionnement du programme.
*/
	Vue();

/*! 	\fn ~Vue()
*	\brief Destructeur
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 26/04/2015
*	\bug Aucun
*	\warning Aucun
*
*/
	~Vue();


/*! 	\fn getControl()
*	\brief Renvoie le controleur
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 26/04/2015
*	\bug Aucun
*	\warning Aucun
*
* 	Renvoie l adresse du controleur utilise dans la Vue.
*/
	Controleur* getControl();

/*! 	\fn lireManuel(string const nomFichier)const
 *	\brief Afficher le manuel
 *	\author BAILLEUX COURTOIS MARKOVSKI
 *	\version 1.0
 *	\date 26/04/2015
 *	\bug Aucun
 *	\warning Aucun
 *
 * 	Permet d afficher le manuel d utilisation a l utilisateur. La fonction va lire un fichier texte et l afficher.
 */
	bool lireManuel(string const nomFichier)const;

/*! 	\fn menu()
 *	\brief lance le menu principal
 *	\author BAILLEUX COURTOIS MARKOVSKI
 *	\version 1.0
 *	\date 26/04/2015
 *	\bug Aucun
 *	\warning Aucun
 *
 */
	void menu();

/*! 	\fn voirInstancesLibres()
 *	\brief lance l onglet voirInstancesLibres
 *	\author BAILLEUX COURTOIS MARKOVSKI
 *	\version 1.0
 *	\date 26/04/2015
 *	\bug Aucun
 *	\warning Aucun
 *
 *	Permet de voir le sous menu pour voir les instances libres.
 */
	void voirInstancesLibres();

/*! 	\fn effectuerRecherche()
 *	\brief Effectuer une recherche
 *	\author BAILLEUX COURTOIS MARKOVSKI
 *	\version 1.0
 *	\date 26/04/2015
 *	\bug Aucun
 *	\warning Aucun
 *
 *	Permet de voir le sous menu pour voir effectuer une recherche.
 */
	void effectuerRecherche();

/*! 	\fn obtenirInfoInstance()
 *	\brief obtenir information d'instance
 *	\author BAILLEUX COURTOIS MARKOVSKI
 *	\version 1.0
 *	\date 26/04/2015
 *	\bug Aucun
 *	\warning Aucun
 *
 *	Permet de voir le sous menu qui permettra d afficher les informations d une instance.
 */
	void obtenirInfoInstance();

/*! 	\fn reserverInstance(vector<string> v=vector<string>(), string creneau=string("vide"))
 *	\brief reserver une instance
 *	\author BAILLEUX COURTOIS MARKOVSKI
 *	\version 1.0
 *	\date 26/04/2015
 *	\bug Aucun
 *	\warning Aucun
 *	\param	vector<string> =vector<string>()
 *	\param	string =string("vide")
 *
 *	Permet de voir le sous menu qui permettra de reserver une instance.
 */
	void reserverInstance(vector<string> v=vector<string>(), string creneau=string("vide"));

/*! 	\fn rendreInstance(vector<string> v=vector<string>(), string creneau=string("vide"))
 *	\brief rendre une instance
 *	\author BAILLEUX COURTOIS MARKOVSKI
 *	\version 1.0
 *	\date 26/04/2015
 *	\bug Aucun
 *	\warning Aucun
 * 	\param	vector<string> =vector<string>()
 *	\param	string =string("vide")
 *
 *	Permet de voir le sous menu qui permettra de rentre une instance.
 */
	void rendreInstance(vector<string> v=vector<string>(), string creneau=string("vide"));

/*! 	\fn voirInstances
 *	\brief voir les instances
 *	\author BAILLEUX COURTOIS MARKOVSKI
 *	\version 1.0
 *	\date 26/04/2015
 *	\bug Aucun
 *	\warning Aucun
 *
 *	Permet de voir le sous menu qui permettra d afficher toutes les instances du modele.
 */
	void voirInstances();

/*! 	\fn voirInstancesOccupees
 *	\brief voir les instances occupees
 *	\author BAILLEUX COURTOIS MARKOVSKI
 *	\version 1.0
 *	\date 26/04/2015
 *	\bug Aucun
 *	\warning Aucun
 *
 *	Permet de voir le sous menu qui permettra d'afficher toutes les instances occupees du modele.
 */
	void voirInstancesOccupees();

/*! 	\fn ClearScreen
*	\brief nettoyer l'ecran
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 26/04/2015
*	\bug Aucun
*	\warning Aucun
*
*	Permet de nettoyer l ecran.
*/
	void ClearScreen()const;

/*! 	\fn afficherVector(vector<string> const )const
*	\brief afficher un vecteur
*	\author BAILLEUX COURTOIS MARKOVSKI
*	\version 1.0
*	\date 26/04/2015
*	\bug Aucun
*	\warning Aucun
*	\param vector<string> const
*/
	void afficherVector(vector<string> const )const;

};

#endif /* VUE_HPP_ */
