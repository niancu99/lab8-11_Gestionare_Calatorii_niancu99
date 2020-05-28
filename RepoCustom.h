#pragma once
#pragma once
#include <vector>
#include <fstream>
#include <cstddef>
using namespace std;

template <class T>
class RepoCustom {
protected:
	vector<T> elements;
	char* f_name;
public:
	RepoCustom() {
		this->f_name = NULL;
	}
	RepoCustom(const char* f_name)
	{
		this->f_name = new char[strlen(f_name) + 1];
		strcpy_s(this->f_name, strlen(f_name) + 1, f_name);
		this->loadfromfile();
	}
	RepoCustom(const RepoCustom& repostl)
	{
		this->f_name = new char[strlen(repostl.f_name) + 1];
		strcpy_s(this->f_name, 1 + strlen(repostl.f_name), repostl.f_name);
		this->loadfromfile();

	}
	void setf_name(const char* f_name) {
		if (this->f_name != NULL)
			delete[]this->f_name;
		if (f_name != NULL)
		{
			this->f_name = new char[strlen(f_name) + 1];
			strcpy_s(this->f_name, strlen(f_name) + 1, f_name);
		}
		else this->f_name = NULL;
	}
	void addElem(T e) {
		this->elements.push_back(e);
	}

	void delElem(T e) {
		typename vector<T>::iterator it;
		it = find(this->elements.begin(), this->elements.end(), e);
		if (it != elements.end())
			this->elements.erase(it);
	}

	void clear()
	{
		this->elements.clear();
	}

	void updateElem(T& oldE, T& newE)
	{
		typename vector<T>::iterator it;
		for (it = this->elements.begin(); it != this->elements.end(); it++)
		{
			if (*it == oldE)
				*it = newE;
		}
	}
	T getAtPosition(int pos)
	{
		return this->elements[pos];
	}
	vector<T> getAll() {
		return this->elements;
	}
	int getSize() {
		return this->elements.size();
	}
	void loadfromfile()
	{
		if (this->f_name != NULL) {
			this->elements.clear();
			ifstream f(this->f_name);
			T elem;
			while (f >> elem)
				addElem(elem);
			f.close();
		}
	}
	void savetofile()
	{
		if (this->f_name != NULL)
		{
			ofstream f(this->f_name);
			int len = this->elements.size();
			for (size_t i = 0; i < len; i++)
				f << getAtPosition(i) << endl;
			f.close();
		}
	}
	~RepoCustom()
	{
		this->elements.clear();
	}
};