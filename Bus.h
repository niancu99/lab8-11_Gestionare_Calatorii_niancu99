#pragma once
#include "Calatorie.h"

class Bus : public Calatorie
{
private:
	int nr_zile;
public:
	Bus();
	Bus(string cod_calatorie, string localitate_plecare, string localitate_destinatie, string data_plecarii, int nr_locuri_totale, int nr_locuri_rezervate, int nr_zile);
	Bus(const Bus& c);
	~Bus();

	int getNrZile();
	void setNrZile(int nr_zile);
	Bus& operator=(const Bus& c);
	bool operator==(const Bus& c);
	string toString(string delim);

	Calatorie* clone();
};