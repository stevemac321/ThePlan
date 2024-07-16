/*==============================================================================
 Name        : libconf.cpp
 Author      : Stephen MacKenzie
 Copyright   : Licensed under GPL version 2 (GPLv2)
 Abstract    : Compare SM solutions to C Answer Book

 See README at the root of this project.

==============================================================================*/
#include "assert-h.cpp"
#include <gtest/gtest.h>
#include <fstream>

std::string log2str(const char *log)
{
	std::ifstream t(log);
	std::stringstream buffer;
	buffer << t.rdbuf();
	return buffer.str();
}
TEST(Test_7_2, Default)
{
	bool test = Test_7_2();

	ASSERT_EQ(test, true);
}
int main(int argc, char *argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
