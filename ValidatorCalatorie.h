#pragma once
#include <string>
#include "Calatorie.h"

using namespace std;

class ValidatorCalatorie {
public:
	ValidatorCalatorie();
	~ValidatorCalatorie();
	virtual void validate(Calatorie* c);
};