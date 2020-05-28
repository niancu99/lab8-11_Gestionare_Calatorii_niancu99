#include "Bus.h"
#include "Util.h"

Bus::Bus() : Calatorie()
{
	this->nr_zile = 0;
}

Bus::Bus(string cod_calatorie, string localitate_plecare, string localitate_destinatie, string data_plecarii, int nr_locuri_totale, int nr_locuri_rezervate, int nr_zile) : Calatorie(cod_calatorie, localitate_plecare, localitate_destinatie, data_plecarii, nr_locuri_totale, nr_locuri_rezervate)
{
	this->nr_zile = nr_zile;
}

Bus::Bus(const Bus& c) : Calatorie(c)
{
	this->nr_zile = c.nr_zile;
}

Bus::~Bus()
{
}

int Bus::getNrZile()
{
	return this->nr_zile;
}

void Bus::setNrZile(int nr_zile)
{
	this->nr_zile = nr_zile;
}

Bus& Bus::operator=(const Bus& c)
{
	Calatorie::operator=(c);
	this->nr_zile = c.nr_zile;
	return *this;
}

bool Bus::operator==(const Bus& c)
{
	return Calatorie::operator==(c) && this->nr_zile == c.nr_zile;
}

string Bus::toString(string delim)
{
	return "B" + delim + Calatorie::toString(delim) + ConvertIntToString(this->nr_zile);
}

Calatorie* Bus::clone()
{
	return new Bus(this->cod_calatorie, this->localitate_plecare, this->localitate_destinatie, this->data_plecarii, this->nr_total_locuri, this->nr_locuri_rezervate, this->nr_zile);
}
