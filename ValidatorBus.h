#pragma once
#include "ValidatorCalatorie.h"

class ValidatorBus : public ValidatorCalatorie {
public:
	ValidatorBus();
	~ValidatorBus();
	void validare(Calatorie* c);
};