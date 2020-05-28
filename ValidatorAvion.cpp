#include "ValidatorAvion.h"
#include "Avion.h"
#include "ValException.h"

ValidatorAvion::ValidatorAvion()
{
}

ValidatorAvion::~ValidatorAvion()
{
}

void ValidatorAvion::validare(Calatorie* c)
{
	ValidatorCalatorie::validate(c);
	Avion* a = (Avion*)c;
	if (!bool(a->getEscale()))
		throw ValException("Invalid data type");
}
