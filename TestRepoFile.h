#pragma once
#include "RepoFile.h"

class TestRepoFile {
private:
	const string filenameInTXT = "TestCalatorieIn.txt";
	const string filenameOutTXT = "TestCalatorieOut.txt";
	const string filenameInCSV = "TestCalatorieIn.csv";
	const string filenameOutCSV = "TestCalatorieOut.CSV";

	vector<Calatorie*> calatoriiIn;

	void testGetSize();
	void testGetAll();
	void testGetCalatorie();
	void testAddCalatorie();
	void testUpdateCalatorie();
	void testDeleteCalatorie();

	void testLoadFromFileTXT();
	void testLoadFromFileCSV();
	void testSaveToFileTXT();
	void testSaveToFileCSV();
public:
	TestRepoFile();
	~TestRepoFile();
	void testAll();
};