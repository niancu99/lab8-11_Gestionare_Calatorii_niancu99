#include "RepoTXT.h"
#include <fstream>
#include "Bus.h"
#include "Avion.h"

RepoTXT::RepoTXT() : RepoFile()
{ 
}

RepoTXT::RepoTXT(string filename) : RepoFile(filename)
{
}

RepoTXT::~RepoTXT()
{
}

void RepoTXT::loadfromfile()
{
	ifstream f(this->filename);
	if (f.is_open())
	{
		this->emptyRepo();
		string linie;
		string delim = " ";
		while (getline(f, linie))
		{
			if (linie.substr(0, 1) == "A")
			{
				linie = linie.erase(0, 2);

				int pos = linie.find(delim);
				string code = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				string loc_plecare = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				string loc_destinatie = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				string data = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				int nr_totale = stoi(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				int nr_rezervate = stoi(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				string escale_string = linie.substr(0, pos);
				bool escale;
				if (escale_string == "Da")
					escale = true;
				else if (escale_string == "Nu")
					escale = false;	
				
				Avion* a = new Avion(code, loc_plecare, loc_destinatie, data, nr_totale, nr_rezervate, escale);
				this->calatorii.push_back(a);
			}
			else if (linie.substr(0, 1) == "B")
			{
				linie = linie.erase(0, 2);

				int pos = linie.find(delim);
				string code = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				string loc_plecare = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				string loc_destinatie = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				string data = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				int nr_totale = stoi(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				int nr_rezervate = stoi(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				int nr_zile = stoi(linie.substr(0, pos));

				Bus* b = new Bus(code, loc_plecare, loc_destinatie, data, nr_totale, nr_rezervate, nr_zile);
				this->calatorii.push_back(b);

			}
		}
		f.close();
	}
}

void RepoTXT::savetofile()
{
	ofstream f(this->filename);
	if (f.is_open())
		for (Calatorie* c : this->calatorii)
			f << c->toString(" ") << endl;
}
