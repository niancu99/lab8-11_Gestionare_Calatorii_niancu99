#include "Util.h"

string ConvertIntToString(int nr)
{
	string s = to_string(nr);
	return s;
}

string ConvertBoolToString(bool x)
{
	string s;
	if (x == true)
		s = "Da";
	else if (x == false)
		s = "Nu";
	return s;
}

