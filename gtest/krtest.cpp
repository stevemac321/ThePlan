/*==============================================================================
 Name        : gtests.cpp
 Author      : Stephen MacKenzie
 Copyright   : Licensed under GPL version 2 (GPLv2)
 Abstract    : Compare SM solutions to C Answer Book

 See README at the root of this project.

 
==============================================================================*/

#include <gtest/gtest.h>
#include <fstream>

#if 0
/* for cases like remove comments that you have to parse log files */
std::string log2str(const char *log)
{
	std::ifstream t(log);
	std::stringstream buffer;
	buffer << t.rdbuf();
	return buffer.str();
}
TEST(Cmp_1_8, Default)
{
	auto test = Test_1_8();
	auto base = Base_1_8();

	ASSERT_EQ(std::get<0>(test), std::get<0>(base));
	ASSERT_EQ(std::get<1>(test), std::get<1>(base));
	ASSERT_EQ(std::get<2>(test), std::get<2>(base));
}
TEST(Cmp_1_9, Default)
{
        Test_1_9();
        Base_1_9();

        auto test = log2str("./testlogs/1_9.tst");
        auto base = log2str("./baselogs/1_9.exp");

        ASSERT_EQ(test, base);
}
TEST(Cmp_1_10, Default)
{
        Test_1_10();
        Base_1_10();

        auto test = log2str("./testlogs/1_10.tst");
        auto base = log2str("./baselogs/1_10.exp");

}
TEST(Cmp_1_11, Default)
{
	auto test = Test_1_11();
	auto base = Base_1_11();

	ASSERT_EQ(std::get<0>(test), std::get<0>(base));
	ASSERT_EQ(std::get<1>(test), std::get<1>(base));
	ASSERT_EQ(std::get<2>(test), std::get<2>(base));
}
TEST(Cmp_1_12, Default)
{
        Test_1_12();
        Base_1_12();

        auto test = log2str("./testlogs/1_12.tst");
        auto base = log2str("./baselogs/1_12.exp");

}

TEST(Cmp_1_14, Default)
{
	auto test = Test_1_14();
	auto base = Base_1_14();

        ASSERT_EQ(test.size(), base.size());
        ASSERT_EQ(test, base);
}
#endif
int main(int argc, char *argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
