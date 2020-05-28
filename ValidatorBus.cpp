#include "ValidatorBus.h"
#include "Bus.h"
#include "ValException.h"

ValidatorBus::ValidatorBus()
{
}

ValidatorBus::~ValidatorBus()
{
}

void ValidatorBus::validare(Calatorie* c)
{
	ValidatorCalatorie::validate(c);
	Bus* b = (Bus*)c;
	if (b->getNrZile() < 0)
		throw("Nr zile negativ");
}
