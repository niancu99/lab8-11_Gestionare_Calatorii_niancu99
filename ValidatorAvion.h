#pragma once
#include "ValidatorCalatorie.h"

class ValidatorAvion : public ValidatorCalatorie {
public:
	ValidatorAvion();
	~ValidatorAvion();
	void validare(Calatorie* c);
};