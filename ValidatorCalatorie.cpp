#include "ValidatorCalatorie.h"
#include "ValException.h"

ValidatorCalatorie::ValidatorCalatorie()
{
}

ValidatorCalatorie::~ValidatorCalatorie()
{
}

void ValidatorCalatorie::validate(Calatorie* c)
{
	if (c->getData().empty())
		throw ValException("Empty date");
	if (c->getLocDestinatie().empty())
		throw ValException("Loc destinatie gol");
	if (c->getLocPlecare().empty())
		throw ValException("Loc plecare gol");
	if (c->getNrLocuriRezervate() < 0)
		throw ValException("Nr locuri rezervate negativ");
	if (c->getNrTotalLocuri() < 0)
		throw ValException("Nr total locuri negativ");
	if (c->getNrLocuriRezervate() > c->getNrTotalLocuri())
		throw ValException("Imposibil de rezervat mai multe locuri decat cele totale");
	if (c->getCod().empty())
		throw ValException("Empty code");
}
