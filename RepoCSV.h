#pragma once
#include "RepoFile.h"

class RepoCSV : public RepoFile {
public:
	RepoCSV();
	RepoCSV(string filename);
	~RepoCSV();
	void loadfromfile();
	void savetofile();
};