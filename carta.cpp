#include "carta.h"
#include <iostream>
#include <string>
#include <sstream>
using std::string;
using std::stringstream;
Carta::Carta(){

}
Carta::Carta(string numero,string tipo){
	this->numero=numero;
	this->tipo=tipo;
}

string Carta::Tostring(){
	stringstream ss;
	ss <<tipo;
	return ss.str();
}

string Carta::getTipo(){
	return tipo;
}

string Carta::getNumero(){
	return numero;
}

void Carta::setTipo(string tipo){
	this->tipo=tipo;
}

void Carta::setNumero(string numero){
	this->numero=numero;
}