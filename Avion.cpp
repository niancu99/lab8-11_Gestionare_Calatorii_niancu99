#include "Avion.h"
#include "Util.h"

Avion::Avion() : Calatorie()
{
}

Avion::Avion(string cod_calatorie, string localitate_plecare, string localitate_destinatie, string data_plecarii, int nr_locuri_totale, int nr_locuri_rezervate, bool escale) : Calatorie(cod_calatorie, localitate_plecare, localitate_destinatie, data_plecarii, nr_locuri_totale, nr_locuri_rezervate)
{
	this->escale = escale;
}

Avion::Avion(const Avion& c) : Calatorie(c)
{
	this->escale = c.escale;
}

Avion::~Avion()
{
}

bool Avion::getEscale()
{
	return this->escale;
}

void Avion::setEscale(bool escale)
{
	this->escale = escale;
}

Avion& Avion::operator=(const Avion& c)
{
	Calatorie::operator=(c);
	this->escale = c.escale;
	return *this;
}

bool Avion::operator==(const Avion& c)
{
	return Calatorie::operator==(c) && this->escale == c.escale;
}

string Avion::toString(string delim)
{
	return "A" + delim + Calatorie::toString(delim) + ConvertBoolToString(this->escale);
}

Calatorie* Avion::clone()
{
	return new Avion(this->cod_calatorie, this->localitate_plecare, this->localitate_destinatie, this->data_plecarii, this->nr_total_locuri, this->nr_locuri_rezervate, this->escale);
}
