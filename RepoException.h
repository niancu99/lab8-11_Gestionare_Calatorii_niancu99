#pragma once
#include <string>
#include <exception>
using namespace std;

class RepoException : public exception {
private:
	string message;
public:
	RepoException(const string message) {
		this->message = message;
	}
	~RepoException()
	{}
	virtual const string what() {
		return message;
	}
};