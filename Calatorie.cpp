#include "Calatorie.h"
#include "Util.h"

Calatorie::Calatorie()
{
	this->nr_total_locuri = 0;
	this->nr_locuri_rezervate = 0;
}

Calatorie::Calatorie(string cod_calatorie, string localitate_plecare, string localitate_destinatie, string data_plecarii, int nr_locuri_totale, int nr_locuri_rezervate)
{
	this->cod_calatorie = cod_calatorie;
	this->localitate_plecare = localitate_plecare;
	this->localitate_destinatie = localitate_destinatie;
	this->data_plecarii = data_plecarii;
	this->nr_total_locuri = nr_locuri_totale;
	this->nr_locuri_rezervate = nr_locuri_rezervate;
}

Calatorie::Calatorie(const Calatorie& c)
{
	this->cod_calatorie = c.cod_calatorie;
	this->localitate_plecare = c.localitate_plecare;
	this->localitate_destinatie = c.localitate_destinatie;
	this->data_plecarii = c.data_plecarii;
	this->nr_locuri_rezervate = c.nr_locuri_rezervate;
	this->nr_total_locuri = c.nr_total_locuri;
}

Calatorie::~Calatorie()
{
}

string Calatorie::getCod()
{
	return this->cod_calatorie;
}

string Calatorie::getLocPlecare()
{
	return this->localitate_plecare;
}

string Calatorie::getLocDestinatie()
{
	return this->localitate_destinatie;
}

string Calatorie::getData()
{
	return this->data_plecarii;
}

int Calatorie::getNrTotalLocuri()
{
	return this->nr_total_locuri;
}

int Calatorie::getNrLocuriRezervate()
{
	return this->nr_locuri_rezervate;
}

Calatorie& Calatorie::operator=(const Calatorie& c)
{
	this->cod_calatorie = c.cod_calatorie;
	this->localitate_plecare = c.localitate_plecare;
	this->localitate_destinatie = c.localitate_destinatie;
	this->data_plecarii = c.data_plecarii;
	this->nr_locuri_rezervate = c.nr_locuri_rezervate;
	this->nr_total_locuri = c.nr_total_locuri;
	return *this;

}

bool Calatorie::operator==(const Calatorie& c)
{
	return this->cod_calatorie == c.cod_calatorie && this->localitate_destinatie == c.localitate_destinatie && this->localitate_plecare == c.localitate_plecare && this->nr_locuri_rezervate == c.nr_locuri_rezervate && this->nr_total_locuri == c.nr_total_locuri && this->data_plecarii == c.data_plecarii;
}

void Calatorie::setCod(string cod)
{
	this->cod_calatorie = cod;
}

void Calatorie::setLocPlecare(string loc)
{
	this->localitate_plecare = loc;
}

void Calatorie::setLocDestinatie(string destinatie)
{
	this->localitate_destinatie = destinatie;
}

void Calatorie::setData(string data)
{
	this->data_plecarii = data;
}

void Calatorie::setNrTotalLocuri(int nr_total)
{
	this->nr_total_locuri = nr_total;
}

void Calatorie::setNrLocuriRezervate(int nr_rezervate)
{
	this->nr_locuri_rezervate = nr_rezervate;
}

Calatorie* Calatorie::clone()
{
	return new Calatorie(this->cod_calatorie, this->localitate_plecare, this->localitate_destinatie, this->data_plecarii, this->nr_total_locuri, this->nr_locuri_rezervate);
}

string Calatorie::toString(string delim)
{
	return this->cod_calatorie + delim + this->localitate_plecare + delim + this->localitate_destinatie + delim + this->data_plecarii + delim + ConvertIntToString(this->nr_total_locuri) + delim + ConvertIntToString(this->nr_locuri_rezervate);
}
