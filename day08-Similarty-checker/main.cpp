#include "gmock/gmock.h"
#include "similarity_checker.h"

TEST(SIMILARITYCHECK, compareEqualString) {
	StringComparator stringComparator;
	EXPECT_EQ(100, stringComparator.compareString("ABCDE", "ABCDE"));
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}
