#include "common.h"
#include "binarytree.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "heap_sort.h"

int main(int argc, char *argv[])
{
    enable_virtual_terminal_processing();
    test_insertion_sort();
    test_merge_sort();
    test_binary_tree_insert_delete();
    test_binary_tree_traversals();
    test_binary_tree_search();
    test_binary_tree_strings();
    test_binary_tree_delete_no_copy();
    test_binary_tree_delete_transplant();
    print_summary();
}
