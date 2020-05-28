#include "TestService.h"
#include <cassert>

void TestService::test_addUtilizator()
{
	Service service(RepoCustom<Utilizator> RepoUtilizatori, RepoFile* RepoCalatorie);
	
	Utilizator utilizator1("Nati", "password");
	Utilizator utilizator2("Bianca", "mycustompassword");
	
	this->service.addUtilizator("Nati", "password");
	this->service.addUtilizator("Bianca", "mycustompassword");

	assert(this->service.getAllUsers()[0] == utilizator1);
	assert(this->service.getAllUsers()[1] == utilizator2);

}
void TestService::test_addAvion()
{
	Service s;
	RepoFile* repo = new RepoTXT();
	s.set_repo(repo);
	Avion* a = new Avion("code", "deva", "oradea", "14.02.2020", 20, 20, true);
	try {
		s.addAvion(a->getCod(), a->getLocPlecare(), a->getLocDestinatie(), a->getData(), a->getNrTotalLocuri(), a->getNrLocuriRezervate(), a->getEscale());
	}
	catch (...)
	{
		assert(false);
	}
	assert(*s.getAllCalatorii()[0] == *a);
}

void TestService::test_addBus()
{
	Service s;
	RepoFile* repo = new RepoTXT();
	s.set_repo(repo);
	Bus* b = new Bus("cod", "oradea", "Deva", "10.10.2019", 20, 30, 7);
	try {
		s.addBus(b->getCod(), b->getLocPlecare(), b->getLocDestinatie(), b->getData(), b->getNrTotalLocuri(), b->getNrLocuriRezervate(), b->getNrZile());
	}
	catch (...) {
		assert(false);
	}
	assert(*s.getAllCalatorii()[0] == *b);
}

void TestService::test_getAllCalatorii()
{
	Service s;
	RepoFile* repo = new RepoTXT();
	s.set_repo(repo);
	Bus* b = new Bus("cod", "oradea", "Deva", "10.10.2019", 20, 30, 7);
	Avion* a = new Avion("code", "deva", "oradea", "14.02.2020", 20, 20, true);
	s.addBus(b->getCod(), b->getLocPlecare(), b->getLocDestinatie(), b->getData(), b->getNrTotalLocuri(), b->getNrLocuriRezervate(), b->getNrZile());
	s.addAvion(a->getCod(), a->getLocPlecare(), a->getLocDestinatie(), a->getData(), a->getNrTotalLocuri(), a->getNrLocuriRezervate(), a->getEscale());
	vector<Calatorie*> calatorii = s.getAllCalatorii();
	assert(*calatorii[0] == *b);
	assert(*calatorii[1] == *a);

}

void TestService::test_logare()
{
	Service service(RepoCustom<Utilizator> RepoUtilizatori);

	this->service.addUtilizator("Nati", "password");
	this->service.addUtilizator("Bianca", "mycustompassword");
	assert(this->service.logare("Nati", "notmypass") == false);
	assert(this->service.logare("Bianca", "mycustompassword") == true);
}

void TestService::test_getAllUsers()
{
	Service service(RepoCustom<Utilizator> RepoUtilizatori);

	Utilizator utilizator1("Sebi", "parolaABC");
	Utilizator utilizator2("Ilie", "mycustompassword");

	this->service.addUtilizator("Sebi", "parolaABC");
	this->service.addUtilizator("Ilie", "mycustompassword");

	assert(this->service.getAllUsers()[0] == utilizator1);
	assert(this->service.getAllUsers()[1] == utilizator2);

}

TestService::TestService()
{
}

void TestService::testAll()
{
	this->test_addAvion();
	this->test_addUtilizator();
	this->test_addBus();
	this->test_logare();
	this->test_getAllCalatorii();
}
