#include "TestValidatorCalatorie.h"
#include "ValidatorCalatorie.h"
#include "ValException.h"
#include "ValidatorAvion.h"
#include "ValidatorBus.h"
#include "Avion.h"
#include "Bus.h"
#include <cassert>

void TestValidatorCalatorie::testValidatorCalatorie()
{
	ValidatorCalatorie val;
	Calatorie* c1 = new Calatorie("cod", "loc plecare", "loc destinatie", "data", 20, 20);
	try {
		val.validate(c1);
	}
	catch (...) {
		assert(false);
	}
	Calatorie* c2 = new Calatorie("cod", "loc plecare", "loc destinatie", "", 20, 20);
	try {
		val.validate(c2);
		assert(true);
	}
	catch(ValException& e){}
	catch (...)
	{
		assert(false);
	}

}

void TestValidatorCalatorie::testValidatorAvion()
{
	ValidatorCalatorie val;
	Avion* a1 = new Avion("cod", "deva", "oradea", "14.10.2020", 20, 20, true);
	try {
		val.validate(a1);
	}
	catch (...) {
		assert(false);
	}
	Avion* a2 = new Avion("cod1", "oradea", "mures", "15.10.2020", 20, 20, true);
	try {
		val.validate(a2);
		assert(true);
	}
	catch(ValException& e){}
	catch (...) {
		assert(false);
	}
	delete a1;
	delete a2;
}

void TestValidatorCalatorie::testValidatorBus()
{
	ValidatorCalatorie val;
	Bus* b1 = new Bus("cod", "Bucuresti", "Ploiesti", "1.09.2019", 20, 10, 2);
	try {
		val.validate(b1);
	}
	catch (...)
	{
		assert(false);
	}
	Bus* b2 = new Bus("cod2", "Constanta", "Ploiesti", "1.09.2019", 20, 10, 2);
	try {
		val.validate(b2);
		assert(true);
	}
	catch(ValException& ex){}
	catch (...)
	{
		assert(true);
	}
	delete b1;
	delete b2;
}

TestValidatorCalatorie::TestValidatorCalatorie()
{
}

TestValidatorCalatorie::~TestValidatorCalatorie()
{
}

void TestValidatorCalatorie::testAll()
{
	this->testValidatorBus();
	this->testValidatorAvion();
	this->testValidatorCalatorie();
}
