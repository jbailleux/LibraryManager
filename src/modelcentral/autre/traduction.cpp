#include "traduction.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include "../specialisation/salle/TypeSalle.hpp"
#include "../specialisation/salle/TypeSalle.hpp"
#include "Creneau.hpp"
#include "Date.hpp"

using namespace std;

string intToString(int const a){
    string s;
    stringstream out;
    out << a;
    s = out.str();
    return s;
}

TypeSalle stringToTypeSalle(string const str){
	if (str=="tp"){
		TypeSalle t;
		t.setType(0);
		return t;
	}
	else{
		TypeSalle t;
		t.setType(1);
		return t;
	}
}

string boolToString(bool const b){
	if (b)
		return "true";
	else
		return "false";
}
