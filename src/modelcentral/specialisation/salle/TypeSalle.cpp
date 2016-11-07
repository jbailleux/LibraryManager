#include "TypeSalle.hpp"
#include <string>
using namespace std;

string TypeSalle::getType() const{
	switch(type){
        case 0: {
			return "tp";
            break;}
        case 1: {
			return "cours";
            break;}
        default:{
        	return "cours";}
	}
}

void TypeSalle::setType(int a){
	switch(a){
        case 0: {
			type=tp;
            break;}
        case 1: {
			type=cours;
            break;}
        default:{
        	type=cours;
        }
	}
}

string TypeSalle::to_string()const{
	return getType();
}

TypeSalle::TypeSalle(){

}

TypeSalle::TypeSalle(string const str){
	if (str[0]=='t')
		setType(0);
	else
		setType(1);
}

