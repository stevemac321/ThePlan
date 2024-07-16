/*==============================================================================
 Name        : gtests.cpp
 Author      : Stephen MacKenzie
 Copyright   : Licensed under GPL version 2 (GPLv2)
==============================================================================*/
#include "test.h"
#include "files.cpp"
#include "bsdlist.cpp"
#include "array.cpp"

TEST(word_count, Default)
{
	int ret = word_count();
	ASSERT_EQ(ret, 621);  //621 is what wc -w returns
	
}
TEST(test_against_bsdlist, Default)
{
    test_bsdlist();
}
TEST(binary_search, Default)
{
    int a[] = {0,1,2,3,4,5,6,7,8,9};
    auto tupres  = binary_search(a, _countof(a), 3);
    auto tupcmp = std::make_tuple(true, 3, 3);
    ASSERT_EQ(tupres, tupcmp);
}

// Assuming smallest_subarray is defined as:
// int smallest_subarray(const int a[], const int len, const int x);

TEST(smallest_subarray, Default) {
    int a[] = {1, 4, 45, 6, 0, 19};
    auto ret = smallest_subarray(a, _countof(a), 51);
    ASSERT_EQ(ret, 3);
}

TEST(smallest_subarray, NoValidSubarray) {
    int a[] = {1, 10, 5, 2, 7};
    auto ret = smallest_subarray(a, _countof(a), 100);
    ASSERT_EQ(ret, 0);
}

TEST(smallest_subarray, SingleElementSubarray) {
    int a[] = {1, 10, 5, 2, 7};
    auto ret = smallest_subarray(a, _countof(a), 9);
    ASSERT_EQ(ret, 1);
}

TEST(smallest_subarray, LargerSumRequired) {
    int a[] = {1, 2, 3, 4, 5};
    auto ret = smallest_subarray(a, _countof(a), 15);
    ASSERT_EQ(ret, 0);
}

TEST(smallest_subarray, EdgeCaseEmptyArray) {
    int a[] = {};
    auto ret = smallest_subarray(a, 0, 1);
    ASSERT_EQ(ret, 0);
}

TEST(smallest_subarray, EdgeCaseSingleElementGreaterThanX) {
    int a[] = {100};
    auto ret = smallest_subarray(a, _countof(a), 50);
    ASSERT_EQ(ret, 1);
}

TEST(smallest_subarray, EdgeCaseSingleElementLessThanX) {
    int a[] = {5};
    auto ret = smallest_subarray(a, _countof(a), 10);
    ASSERT_EQ(ret, 0);
}
// -----------------------------------------------
// left most and right most index

TEST(left_and_rightmost_indexes, Default)
{
    int a[] = {1,3,5,5,5,5,67,123,125};
    auto ret = left_and_rightmost_indexes(a, 5, _countof(a));
    ASSERT_EQ(ret, std::make_pair(2,5));
}
//-----------------------------------------------
TEST(longest_common_prefix, Default)
{
    const char * strs[] = {"geeksforgeeks", "geeks", "geek", "geezer"};
    auto ret = longest_common_prefix(strs);
    ASSERT_EQ(ret, "gee");
}
//-----------------------------------------------
int main(int argc, char *argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

