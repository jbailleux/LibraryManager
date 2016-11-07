#include "Date.hpp"
#include <string>
#include "traduction.hpp"
using namespace std;




void Date::setHeure(int h){
	heure=h;
}

int Date::getHeure() const{
	return heure;
}

Date::Date(int heure){
	setHeure(heure);
}

Date::Date(string heure){
	setHeure(stoi(heure));
}

Date::Date(){

}

string Date::to_string()const{
	string tmp;
	tmp=intToString(getHeure());
	return tmp;
}
