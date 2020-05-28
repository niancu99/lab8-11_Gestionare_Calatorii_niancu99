#pragma once
#include "Calatorie.h"
#include <vector>

using namespace std;

class RepoFile {
protected:
	vector<Calatorie*> calatorii;
	string filename;
public:
	RepoFile();
	RepoFile(string filename);
	~RepoFile();
	void setfilename(string filename);

	vector<Calatorie*> getAll();
	int getSize();
	Calatorie* getCalatorie(int pos);
	void addCalatorie(Calatorie* c);
	void updateCalatorie(Calatorie* cVeche, Calatorie* cNoua);
	void deleteCalatorie(Calatorie* c);

	void emptyRepo();

	virtual void loadfromfile() = 0;
	virtual void savetofile() = 0;
};