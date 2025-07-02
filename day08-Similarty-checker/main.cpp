#include "gmock/gmock.h"
#include "similarity_checker.h"

TEST(TS, TC1) {
	EXPECT_EQ(1, 1);
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}
