#pragma once
#include "Calatorie.h"

class Avion : public Calatorie {
private:
	bool escale;
public:
	Avion();
	Avion(string cod_calatorie, string localitate_plecare, string localitate_destinatie, string data_plecarii, int nr_locuri_totale, int nr_locuri_rezervate, bool escale);
	Avion(const Avion& c);
	~Avion();

	bool getEscale();
	void setEscale(bool escale);

	Avion& operator=(const Avion& c);
	bool operator==(const Avion& c);
	string toString(string delim);

	Calatorie* clone();
};