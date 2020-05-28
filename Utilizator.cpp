#include "Utilizator.h"
#include <string>

Utilizator::Utilizator()
{
	this->nume = "";
	this->parola = "";
}

Utilizator::Utilizator(const Utilizator& u)
{
	this->nume = u.nume;
	this->parola = u.parola;
}

Utilizator::Utilizator(string nume, string parola)
{
	this->nume = nume;
	this->parola = parola;
}

Utilizator::~Utilizator()
{
}

string Utilizator::getNume()
{
	return this->nume;
}

string Utilizator::getParola()
{
	return this->parola;
}

bool Utilizator::operator==(const Utilizator& u)
{
	return this->nume == u.nume && this->parola == u.parola;
}

Utilizator& Utilizator::operator=(const Utilizator& u)
{
	this->nume = u.nume;
	this->parola = u.parola;
	return *this;
}

istream& operator>>(istream& is, Utilizator& u)
{
	is >> u.nume >> u.parola;
	return is;
}

ostream& operator<<(ostream& os, const Utilizator& u)
{
	os << u.nume << " " << u.parola << endl;
	return os;
}
