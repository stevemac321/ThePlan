#include "common.h"
#include "binarytree.h"


int main(int argc, char *argv[])
{
    enable_virtual_terminal_processing();
    Heap_Init();
    test_binary_tree_rb_insert();
    print_summary();
}
