#include "common.h"
#include "binarytree.h"
#include "insertion_sort.h"

void test_binary_tree()
{
    TEST_BEGIN("test_binary_tree 1")
    int a[] = {9, 3, 5, 1};
    BinTree<int> tree;
  
    // Inserting elements into the tree
    for (const auto& i : a) {
        tree.insert(i);
    }
    std::vector<int> v  = tree.get_test_vector();
    int exp[] = {1, 3, 5, 9};
    ASSERT_ITER_EQ(std::begin(exp), std::end(exp), v.begin(), v.end()); 
    TEST_END("test_binary_tree 1")    
    
    TEST_BEGIN("test_binary_tree 2")
    int exp2[] = {1, 3, 9};
    int val = 5;
    tree.remove(val);
    std::vector<int> v2  = tree.get_test_vector();
    ASSERT_ITER_EQ(std::begin(exp2), std::end(exp2), v2.begin(), v2.end()); 
   
    TEST_END("test_binary_tree 2")
}
void test_insertion_sort()
{
    TEST_BEGIN("test_insertion_sort 1")
    int a[] = {44,2,6,8,0,1};
    int b[] = {0,1,2,6,8,44};
    insertion_sort(a);
    ASSERT_ITER_EQ(std::begin(a), std::end(a), std::begin(b), std::end(b)); 
    TEST_END("test_insertion_sort 1")

    TEST_BEGIN("test_insertion_sort 2")
    int a2[] = {44,2,6,8,0,1};
    int g[] = {44,8,6,2,1,0};
    insertion_sort(a2, std::less());
    ASSERT_ITER_EQ(std::begin(a2), std::end(a2), std::begin(g), std::end(g)); 
    TEST_END("test_insertion_sort 2")
     
    TEST_BEGIN("test_insertion_sort 3")
    const char* charArray[] = {"banana", "apple", "cherry"};
    const char* cmpArray[] = {"apple", "banana","cherry"};
    insertion_sort(charArray, strcmp_wrapper);
    for(int i=0; i < 3; i++) {
        ASSERT_STREQ(charArray[i], cmpArray[i]);
    }
    TEST_END("test_insertion_sort 3")

    TEST_BEGIN("test_insertion_sort 4")
    std::string stringArray[] = {"banana", "apple", "cherry"};
    std::string cmpStringArray[] = {"apple", "banana","cherry"};
    insertion_sort(stringArray, string_comp_wrapper);
    for(int i=0; i < 3; i++) {
        ASSERT_STR_EQ(stringArray[i], cmpStringArray[i]);
    }
    TEST_END("test_insertion_sort 4")

    TEST_BEGIN("test_insertion_sort 5")
    std::array<char, 5> charstdArray = {'e', 'd', 'a', 'c', 'b'};
    std::array<char, 5> cmpstdArray = {'a', 'b', 'c', 'd', 'e'};

    insertion_sort(charstdArray);  // Uses the std::array specialization
    ASSERT_ITER_EQ(std::begin(charstdArray), std::end(charstdArray), std::begin(cmpstdArray), std::end(cmpstdArray)); 
    TEST_END("test_insertion_sort 5")
    
} 
void test_print_array()
{
    int a[] = {44,2,6,8,0,1};
    print_array(a);
    const char* charArray[] = {"banana", "apple", "cherry"};
    print_array(charArray);

    std::string strArray[] = {"orange", "pear", "banana"};
    print_array(strArray);

    std::array<char, 5> charstdArray = {'e', 'd', 'a', 'c', 'b'};
    print_array(charstdArray);
}

int main(int argc, char *argv[])
{
    enable_virtual_terminal_processing();

	test_binary_tree();
    test_insertion_sort();

    print_summary();
}
