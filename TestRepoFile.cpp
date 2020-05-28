#include "TestRepoFile.h"
#include <assert.h>
#include "RepoCSV.h"
#include "RepoTXT.h"
#include "Avion.h"
#include "Bus.h"

void TestRepoFile::testGetSize()
{
	RepoFile* repofile = new RepoTXT();
	assert(repofile->getSize() == 0);
	repofile->addCalatorie(new Calatorie());
	assert(repofile->getSize() == 1);
}

void TestRepoFile::testGetAll()
{
	RepoFile* repofile = new RepoTXT();
	Avion* c1 = new Avion("D34", "Bucuresti", "Oradea", "2.02.2021", 70, 50, true);
	Bus* c2 = new Bus("B32", "Oradea", "Bucuresti", "3.04.2020", 50, 50, false);
	repofile->addCalatorie(c1);
	repofile->addCalatorie(c2);
	vector<Calatorie*> calatorii = repofile->getAll();
	assert(*calatorii[0] == *c1->clone());
	assert(*calatorii[1] == *c2->clone());

}

void TestRepoFile::testGetCalatorie()
{
	RepoFile* repofile = new RepoTXT();
	Bus* b = new Bus("CGF", "Iasi", "Cluj-Napoca", "15.06.2020", 80, 35, 14);
	repofile->addCalatorie(b);
	assert(*repofile->getCalatorie(0) == *b->clone());
	assert(*repofile->getCalatorie(-1) == *(new Bus()));
	
}

void TestRepoFile::testAddCalatorie()
{
	RepoFile* repofile = new RepoTXT();
	Bus* c1 = new Bus("CS", "Bucuresti", "Suceava", "15.08.2020", 80, 20, 7);
	repofile->addCalatorie(c1);
	assert(*repofile->getCalatorie(0) == *c1->clone());

}

void TestRepoFile::testUpdateCalatorie()
{
	RepoFile* repofile = new RepoTXT();
	Avion* c1 = new Avion("GGG", "Craiova", "Bucuresti", "14.09.2020", 60, 10, true);
	repofile->addCalatorie(c1);
	Avion* c2 = new Avion("FGSS", "Caras Severin", "Oradea", "15.09.2020", 50, 50, false);
	Avion* c3 = new Avion("FSC", "Cluj-Napoca", "Targu Mures", "17.08.2020", 80, 55, false);
	repofile->updateCalatorie(c3, c2);
	assert(*repofile->getCalatorie(0) == *c1);
	repofile->updateCalatorie(c1, c2);
	assert(*repofile->getCalatorie(0) == *c2);
}

void TestRepoFile::testDeleteCalatorie()
{
	RepoFile* repofile = new RepoTXT();
	Bus* c1 = new Bus("CS", "Bucuresti", "Suceava", "15.08.2020", 80, 20, 7);
	repofile->addCalatorie(c1);
	Bus* c2 = new Bus("MS", "Targu Mures", "Oradea", "16.09.2020", 50, 50, 14);
	repofile->deleteCalatorie(c2);
	assert(repofile->getSize() == 1);
	assert(*repofile->getCalatorie(0) == *c1);
	repofile->deleteCalatorie(c1);
	assert(repofile->getSize() == 0);
}

void TestRepoFile::testLoadFromFileTXT()
{
	RepoFile* repofile = new RepoTXT(this->filenameInTXT);
	repofile->loadfromfile();
	assert(repofile->getSize() == this->calatoriiIn.size());
	assert(*repofile->getCalatorie(0) == *this->calatoriiIn[0]);
	assert(*repofile->getCalatorie(1) == *this->calatoriiIn[1]);

}

void TestRepoFile::testLoadFromFileCSV()
{
	RepoFile* repofile = new RepoCSV(this->filenameInCSV);
	repofile->loadfromfile();
	assert(repofile->getSize() == this->calatoriiIn.size());
	assert(*repofile->getCalatorie(0) == *this->calatoriiIn[0]);
	assert(*repofile->getCalatorie(1) == *this->calatoriiIn[1]);

}

void TestRepoFile::testSaveToFileTXT()
{
	RepoFile* repofile = new RepoTXT(this->filenameInTXT);
	repofile->loadfromfile();
	repofile->setfilename(this->filenameOutTXT);
	Bus* b1 = new Bus("C2", "Bucuresti", "Constanta", "5.05.2020", 20, 20, 4);
	repofile->addCalatorie(b1);
	repofile->savetofile();
	repofile->loadfromfile();
	assert(repofile->getSize() == this->calatoriiIn.size() + 1);
	vector<Calatorie*> calatorii = repofile->getAll();
	for (int i = 0; i < repofile->getSize(); i++)
		assert(*calatorii[i] == *this->calatoriiIn[i]);
	assert(*calatorii[calatorii.size() - 1] == *b1);
}

void TestRepoFile::testSaveToFileCSV()
{
	RepoFile* repofile = new RepoCSV(this->filenameInCSV);
	repofile->loadfromfile();
	repofile->setfilename(this->filenameOutCSV);
	Bus* b1 = new Bus("C2", "Bucuresti", "Constanta", "5.05.2020", 20, 20, 4);
	repofile->addCalatorie(b1);
	repofile->savetofile();
	repofile->loadfromfile();
	assert(repofile->getSize() == this->calatoriiIn.size() + 1);
	vector<Calatorie*> calatorii = repofile->getAll();
	for (int i = 0; i < repofile->getSize(); i++)
		assert(*calatorii[i] == *this->calatoriiIn[i]);
	assert(*calatorii[calatorii.size() - 1] == *b1);
}

TestRepoFile::TestRepoFile()
{
	Bus* b1 = new Bus("C2", "Bucuresti", "Constanta", "5.05.2020", 20, 20, 4);
	this->calatoriiIn.push_back(b1);
}

TestRepoFile::~TestRepoFile()
{
}

void TestRepoFile::testAll()
{
	this->testGetCalatorie();
	this->testAddCalatorie();
	this->testDeleteCalatorie();
	this->testGetAll();
	this->testGetSize();
	this->testLoadFromFileCSV();
	this->testLoadFromFileTXT();
	this->testUpdateCalatorie();
	this->testSaveToFileCSV();
	this->testSaveToFileTXT();
}
