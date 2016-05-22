#pragma once 

#include <iostream>
#include <string>
#include <sstream>

using std::string;
class Carta
{
private:
	string numero;
	string tipo;
public:
	Carta();
	Carta(string,string);
	string Tostring();
	void setNumero(string);
	void setTipo(string);
	string getNumero();
	string getTipo();
};