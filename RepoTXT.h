#pragma once
#include "RepoFile.h"

class RepoTXT : public RepoFile
{
public:
	RepoTXT();
	RepoTXT(string filename);
	~RepoTXT();
	void loadfromfile();
	void savetofile();
};