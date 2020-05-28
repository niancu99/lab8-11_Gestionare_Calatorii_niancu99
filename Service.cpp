#include "Service.h"

Service::Service()
{
}

Service::Service(const RepoCustom<Utilizator>& RepoUtilizator, RepoFile* RepoCalatorie)
{
	this->RepoUtilizator = RepoUtilizator;
	this->RepoCalatorie = RepoCalatorie;
}

Service::Service(const Service& serv)
{
	this->RepoUtilizator = serv.RepoUtilizator;
	this->RepoCalatorie = serv.RepoCalatorie;
}

void Service::addUtilizator(string nume, string parola)
{
	this->RepoUtilizator.addElem(Utilizator(nume, parola));
}

void Service::addAvion(string cod_calatorie, string localitate_plecare, string localitate_destinatie, string data_plecarii, int nr_locuri_totale, int nr_locuri_rezervate, bool escale)
{
	Avion* a = new Avion(cod_calatorie, localitate_plecare, localitate_destinatie, data_plecarii, nr_locuri_totale, nr_locuri_rezervate, escale);
	this->RepoCalatorie->addCalatorie(a);
}

void Service::addBus(string cod_calatorie, string localitate_plecare, string localitate_destinatie, string data_plecarii, int nr_locuri_totale, int nr_locuri_rezervate, int nr_zile)
{
	Bus* b = new Bus(cod_calatorie, localitate_plecare, localitate_destinatie, data_plecarii, nr_locuri_totale, nr_locuri_rezervate, nr_zile);
	this->RepoCalatorie->addCalatorie(b);
}

vector<Calatorie*> Service::getAllCalatorii()
{
	return this->RepoCalatorie->getAll();
}

vector<Utilizator> Service::getAllUsers()
{
	return this->RepoUtilizator.getAll();
}

vector<Calatorie*> Service::searchbyDate(string date)
{
	vector<Calatorie*> calatorii = this->RepoCalatorie->getAll();
	vector<Calatorie*> myvector;
	for (Calatorie* c : calatorii)
	{
		if (c->getData() == date)
			myvector.push_back(c);
	}
	return myvector;
}

void Service::loadFromFile()
{
	this->RepoUtilizator.loadfromfile();
}

void Service::saveToFile()
{
	this->RepoUtilizator.savetofile();
}

void Service::set_repo(RepoFile* repofile)
{
	this->RepoCalatorie = repofile;
}

bool Service::logare(string nume, string parola)
{
	for (int i = 0; i < this->RepoUtilizator.getSize(); i++)
	{
		if (this->RepoUtilizator.getAll()[i].getNume() == nume && this->RepoUtilizator.getAll()[i].getParola() == parola)
		{
			return true;
		}
	}
	return false;
}

Service::~Service()
{
}
