#include "TestCalatorie.h"
#include <assert.h>
#include "Calatorie.h"
#include "Util.h"
void TestCalatorie::test_getters()
{
	Calatorie c("CODE", "Bucuresti", "Oradea", "14.10.2020", 70, 50);
	assert(c.getCod() == "CODE");
	assert(c.getData() == "14.10.2020");
	assert(c.getLocDestinatie() == "Oradea");
	assert(c.getLocPlecare() == "Bucuresti");
	assert(c.getNrLocuriRezervate() == 50);
	assert(c.getNrTotalLocuri() == 70);
}

void TestCalatorie::test_setters()
{
	Calatorie c;
	c.setCod("MyCode");
	c.setData("2.02.2021");
	c.setLocDestinatie("Marghita");
	c.setNrLocuriRezervate(20);
	assert(c.getCod() == "MyCode");
	assert(c.getData() == "2.02.2021");
	assert(c.getLocDestinatie() == "Marghita");
	assert(c.getNrLocuriRezervate() == 20);
}

void TestCalatorie::test_to_string()
{
	Calatorie c("CODE", "Bucuresti", "Oradea", "14.10.2020", 70, 50);
	assert(c.toString(" ") == "CODE Bucuresti Oradea 14.10.2020 70 50");
	assert(c.toString(",") == "CODE,Bucuresti,Oradea,14.10.2021,70,50");
}

void TestCalatorie::test_clone()
{
	Calatorie c("CODE", "Bucuresti", "Oradea", "14.10.2020", 70, 50);
	Calatorie* clone = c.clone();
	assert(c == *clone);
	assert(&c != clone);
}

void TestCalatorie::testAll()
{
	this->test_clone();
	this->test_getters();
	this->test_setters();
	this->test_to_string();
}
