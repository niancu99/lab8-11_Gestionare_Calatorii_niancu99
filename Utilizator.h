#pragma once
#include <iostream>
using namespace std;

class Utilizator {
protected:
	string nume;
	string parola;
public:
	Utilizator();
	Utilizator(const Utilizator& u);
	Utilizator(string nume, string parola);
	~Utilizator();

	string getNume();
	string getParola();
	
	bool operator==(const Utilizator& u);
	Utilizator& operator=(const Utilizator& u);

	friend istream& operator>>(istream& is, Utilizator& u);
	friend ostream& operator<<(ostream& os, const Utilizator& u);
};