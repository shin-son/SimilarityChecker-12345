#pragma once
#include <iostream>

using std::string;

class StringComparator {
public:
	double compareString(const string& string1, const string& string2) {		
		return compareLength(string1, string2) + compareAlphabet(string1, string2);
	}

	double compareAlphabet(const string& string1, const string& string2) {
		bool used1[26] = { false }, used2[26] = { false };
		for (char eachAlphabet : string1) {
			if (isAlphabet(eachAlphabet)) used1[eachAlphabet - 'A'] = true;
		}

		for (char eachAlphabet : string2) {
			if (isAlphabet(eachAlphabet)) used2[eachAlphabet - 'A'] = true;
		}

		double commonCnt = 0, totalCnt = 0;
		for (int i = 0; i < 26; ++i) {
			bool firstChar = used1[i], secondChar = used2[i];
			if (firstChar || secondChar) totalCnt++;
			if (firstChar && secondChar) commonCnt++;
		}

		double alphaPoint = (commonCnt / totalCnt) * 40;
		return alphaPoint;
	}

	double compareLength(const string& string1, const string& string2) {
		double len1 = static_cast<double>(string1.size());
		double len2 = static_cast<double>(string2.size());

		double shorter = std::min(len1, len2);
		double gap = std::abs(len1 - len2);

		if (shorter == 0) return 0;

		double percentage = gap / shorter;
		double lengthPoint = std::max(0.0, (1 - percentage) * 60.0);

		return lengthPoint;
	}

private:
	bool isAlphabet(const char eachAlphabet) {
		return (eachAlphabet >= 'A' && eachAlphabet <= 'Z');
	}
};
