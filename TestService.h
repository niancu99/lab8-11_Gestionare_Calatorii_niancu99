#pragma once
#include "RepoCustom.h"
#include "Utilizator.h"
#include "Service.h"

class TestService {
private:
	Service service;
	void test_addUtilizator();
	void test_addAvion();
	void test_addBus();
	void test_getAllUsers();
	void test_getAllCalatorii();
	void test_logare();
public:
	TestService();
	void testAll();
};