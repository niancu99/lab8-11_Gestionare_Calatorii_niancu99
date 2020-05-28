#pragma once
#include <string.h>
#include <exception>

using namespace std;

class ValException : public exception {
private:
	char* message;
public:
	ValException(const char* message)
	{
		this->message = new char[strlen(message) + 1];
		strcpy_s(this->message, 1 + strlen(message), message);
	}
	~ValException() {
		if (this->message != NULL)
			delete[]this->message;
	}
	virtual const char* what() {
		return message;
	}
};