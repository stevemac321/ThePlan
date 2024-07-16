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
}

int main() 
{
    enable_virtual_terminal_processing();
    test_binary_tree();
    test_insertion_sort();   
}