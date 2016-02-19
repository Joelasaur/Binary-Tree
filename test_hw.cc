#include "gtest/gtest.h"
#include <string.h>

TEST(HWTest, testPass){
	EXPECT_TRUE(0 == 0);
}

TEST(HWTest, testFail){
	EXPECT_TRUE(0 == 1);
}

