#pragma once
#include <iostream>

using std::string;

class StringComparator {
public:
	int compareString(const string& string1, const string& string2) {
		if (string1 == string2) return 100;
		int gap;
		double percentage, partialPoint;

		if (string1.size() > string2.size()) {
			gap = string1.size() - string2.size();
			percentage = gap / string2.size();
			partialPoint = (1 - percentage) * 60;
		}
		else {
			gap = string2.size() - string1.size();
			percentage = gap / string1.size();
			partialPoint = (1 - percentage) * 60;
		}

		return static_cast<int>(partialPoint);
	}
};
