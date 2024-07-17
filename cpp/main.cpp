#include "common.h"
#include "binarytree.h"
#include "insertion_sort.h"
#include "merge_sort.h"

int main(int argc, char *argv[])
{
    enable_virtual_terminal_processing();

	test_binary_tree();
    test_insertion_sort();
    test_merge_sort();

    print_summary();
}
