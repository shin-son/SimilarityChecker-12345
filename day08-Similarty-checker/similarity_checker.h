#pragma once
#include <iostream>

using std::string;

class StringComparator {
public:
	int compareString(const string& string1, const string& string2) {
		if (string1 == string2) return 100;
	}
};
