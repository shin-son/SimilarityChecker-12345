#include "gmock/gmock.h"
#include "similarity_checker.h"

using namespace testing;

class stringComparatorFixture : public Test {
public:
	StringComparator stringComparator;
};

TEST_F(stringComparatorFixture, compareEqualString) {
	EXPECT_EQ(100, stringComparator.compareString("ABCDE", "ABCDE"));
}

TEST_F(stringComparatorFixture, compareLength) {
	EXPECT_EQ(60, stringComparator.compareString("FGHIJ", "ABCDE"));
}

TEST_F(stringComparatorFixture, compareLengthMoreThanSixStrings) {
	EXPECT_EQ(48, stringComparator.compareString("FGHIJK", "ABCDE"));
}

TEST_F(stringComparatorFixture, compareLengthLessThanFourStrings) {
	EXPECT_EQ(45, stringComparator.compareString("FGHI", "ABCDE"));
}

TEST_F(stringComparatorFixture, compareLengthLessThanOnetring) {
	EXPECT_EQ(0, stringComparator.compareString("F", "ABCDE"));
}

TEST_F(stringComparatorFixture, compareAlphabetOneString) {
	EXPECT_EQ(77, stringComparator.compareString("ABCD", "ABCDE"));
}

TEST_F(stringComparatorFixture, compareAlphabetLengthCheck) {
	EXPECT_EQ(86, static_cast<int>(stringComparator.compareString("ABCDF", "ABCDE")));
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}
