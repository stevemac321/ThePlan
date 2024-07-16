#include "common.h"
#include "binarytree.h"
#include "sort.h"

void test_binary_tree()
{
       int a[] = {9, 3, 5, 1};
    BinTree<int> tree;

    // Inserting elements into the tree
    for (const auto& i : a) {
        tree.insert(i);
    }

    std::cout << "\nBefore Remove:\n";
    tree.visit();

    int val = 5;
    tree.remove(val);

    std::cout << "\nAfter Remove:\n";
    tree.visit();
}
void test_insertion_sort()
{
    int a[] = {44,2,6,8,0,1};
    int b[] = {0,1,2,6,8,44};
    insertion_sort(a);
    compare_array(a,b);
    const char* charArray[] = {"banana", "apple", "cherry"};
    std::string strArray[] = {"orange", "pear", "banana"};
    std::array<char, 5> charstdArray = {'e', 'd', 'a', 'c', 'b'};

    insertion_sort(charArray, strcmp_wrapper);   // Uses the const char* specialization
    const char* cmpchar[] = {"apple", "banana", "cherry"};
    compare_array(charArray, cmpchar, strcmp_wrapper);

    insertion_sort(strArray, string_comp_wrapper);    // Uses the std::string specialization
    std::string cmpstr[] = {"banana", "orange", "pear"};
    compare_array(strArray, cmpstr, string_comp_wrapper);

    insertion_sort(charstdArray);  // Uses the std::array specialization
    std::array<char, 5> cmpstdArray = {'a', 'b', 'c', 'd', 'e'};
    compare_array(charstdArray, cmpstdArray);

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

int main() 
{
    enable_virtual_terminal_processing();
    test_binary_tree();
    test_insertion_sort();  
    test_print_array(); 
}