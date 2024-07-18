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
    print_summary();
}
