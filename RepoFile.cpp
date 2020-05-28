#include "RepoFile.h"

RepoFile::RepoFile()
{
}

RepoFile::RepoFile(string filename)
{
	this->filename = filename;
}

RepoFile::~RepoFile()
{
}

void RepoFile::setfilename(string filename)
{
	this->filename = filename;
}

vector<Calatorie*> RepoFile::getAll()
{
	return this->calatorii;
}

int RepoFile::getSize()
{
	return this->calatorii.size();
}

Calatorie* RepoFile::getCalatorie(int pos)
{
	if (pos > 0 && pos < this->getSize())
		return this->calatorii[pos]->clone();
	return new Calatorie();
}

void RepoFile::addCalatorie(Calatorie* c)
{
	this->calatorii.push_back(c->clone());
	this->savetofile();

}

void RepoFile::updateCalatorie(Calatorie* cVeche, Calatorie* cNoua)
{
	for (int i = 0; i < this->calatorii.size(); i++)
	{
		if (*(this->getCalatorie(i)) == *cVeche)
		{
			delete this->calatorii[i];
			this->calatorii[i] = cNoua->clone();
			this->savetofile();
			return;
		}
	}
}

void RepoFile::deleteCalatorie(Calatorie* c)
{
	for (int i = 0; i < this->calatorii.size(); i++)
	{
		if (**(this->calatorii.begin() + i) == *c)
		{
			delete this->calatorii[i];
			this->calatorii.erase(this->calatorii.begin() + i);
			this->savetofile();
			return;
		}
	}
}

void RepoFile::emptyRepo()
{
	for (int i = 0; i < this->getSize(); i++)
		delete this->calatorii[i];
	this->calatorii.clear();
}
