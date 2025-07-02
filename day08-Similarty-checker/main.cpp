#include "gmock/gmock.h"
#include "similarity_checker.h"

TEST(SIMILARITYCHECK, compareEqualString) {
	StringComparator stringComparator;
	EXPECT_EQ(100, stringComparator.compareString("ABCDE", "ABCDE"));
}

TEST(SIMILARITYCHECK, compareLength) {
	StringComparator stringComparator;
	EXPECT_EQ(60, stringComparator.compareString("FGHIJ", "ABCDE"));
}

TEST(SIMILARITYCHECK, compareLengthMoreThanSixStrings) {
	StringComparator stringComparator;
	EXPECT_EQ(48, stringComparator.compareString("FGHIJK", "ABCDE"));
}

TEST(SIMILARITYCHECK, compareLengthLessThanFourStrings) {
	StringComparator stringComparator;
	EXPECT_EQ(45, stringComparator.compareString("FGHI", "ABCDE"));
}


int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}
