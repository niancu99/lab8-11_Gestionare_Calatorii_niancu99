#pragma once
#include <string>
#include <iostream>
using namespace std;

class Calatorie {
protected:
	string cod_calatorie;
	string localitate_plecare;
	string localitate_destinatie;
	string data_plecarii;
	int nr_total_locuri;
	int nr_locuri_rezervate;
public:
	Calatorie();
	Calatorie(string cod_calatorie, string localitate_plecare, string localitate_destinatie, string data_plecarii, int nr_locuri_totale, int nr_locuri_rezervate);
	Calatorie(const Calatorie& c);
	~Calatorie();

	string getCod();
	string getLocPlecare();
	string getLocDestinatie();
	string getData();
	int getNrTotalLocuri();
	int getNrLocuriRezervate();

	Calatorie& operator=(const Calatorie& c);
	bool operator==(const Calatorie& c);

	void setCod(string cod);
	void setLocPlecare(string loc);
	void setLocDestinatie(string destinatie);
	void setData(string data);
	void setNrTotalLocuri(int nr_total);
	void setNrLocuriRezervate(int nr_rezervate);

	virtual Calatorie* clone();
	virtual string toString(string delim);
};