#pragma once
#include "RepoTXT.h"
#include "RepoCSV.h"
#include "RepoCustom.h"
#include "RepoCSV.h"
#include "RepoTXT.h"
#include "RepoCustom.h"
#include "Utilizator.h"
#include "Avion.h"
#include "Bus.h"

class Service {
private:
	RepoFile* RepoCalatorie;
	RepoCustom<Utilizator> RepoUtilizator;

public:
	Service();
	Service(const RepoCustom<Utilizator>& RepoUtilizator, RepoFile*);
	Service(const Service& serv);
	void addUtilizator(string nume, string parola);
	void addAvion(string cod_calatorie, string localitate_plecare, string localitate_destinatie, string data_plecarii, int nr_locuri_totale, int nr_locuri_rezervate, bool escale);
	void addBus(string cod_calatorie, string localitate_plecare, string localitate_destinatie, string data_plecarii, int nr_locuri_totale, int nr_locuri_rezervate, int nr_zile);
	vector<Calatorie*> getAllCalatorii();
	vector<Utilizator> getAllUsers();
	vector<Calatorie*> searchbyDate(string date);
	void loadFromFile();
	void saveToFile();
	void set_repo(RepoFile* repofile);
	bool logare(string nume, string parola);
	~Service();
};