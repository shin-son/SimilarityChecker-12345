#pragma once
#include <iostream>

using std::string;

class StringComparator {
public:
	double compareString(const string& string1, const string& string2) {		
		if (string1 == string2) return 100;

		double len1 = static_cast<double>(string1.size());
		double len2 = static_cast<double>(string2.size());

		double shorter = std::min(len1, len2);
		double gap = std::abs(len1 - len2);

		if (shorter == 0) return 0;

		double percentage = gap / shorter;
		double partialPoint = std::max(0.0, (1 - percentage) * 60.0);

		return partialPoint;
	}
};
