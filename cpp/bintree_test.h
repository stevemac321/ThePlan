///////////////////////////////////////////////////////////////////////////////
// tests
void test_binary_tree_insert_delete()
{
    TEST_BEGIN("test_binary_tree_insert_delete INSERT")
    int a[] = {9, 3, 5, 1};
    BinTree<int> tree;
  
    // Inserting elements into the tree
    for (const auto& i : a) {
        tree.insert(i);
    }
    std::vector<int> v  = tree.get_test_vector();
    int exp[] = {1, 3, 5, 9};
    ASSERT_ITER_EQ(std::begin(exp), std::end(exp), v.begin(), v.end()); 
    TEST_END("test_binary_tree_insert_delete INSERT")    
    
    TEST_BEGIN("test_binary_tree_insert_delete REMOVE")
    int exp2[] = {1, 3, 9};
    int val = 5;
    tree.remove(val);
    std::vector<int> v2  = tree.get_test_vector();
    ASSERT_ITER_EQ(std::begin(exp2), std::end(exp2), v2.begin(), v2.end()); 
   
    TEST_END("test_binary_tree_insert_delete REMOVE")
}
void test_binary_tree_traversals()
{
    TEST_BEGIN("test_binary_tree_traversals IN ORDER ")
    int a[] = {15, 10, 20, 8, 12, 17, 25, 6, 11, 16, 18, 23, 27, 5, 7, 9, 14, 19, 22, 24};
   
    BinTree<int> tree;
  
    // Inserting elements into the tree
    for (const auto& i : a) {
        tree.insert(i);
    }
    
    tree.visit_in_order();
    // expected results 
    int e[] = {5, 6, 7, 8, 9, 10, 11, 12, 14, 15, 16, 17, 18, 19, 20, 22, 23, 24, 25, 27};
    std::cout << "\n";
    print_array(e);
    TEST_END("test_binary_tree_traversals IN-ORDER")    
    
    TEST_BEGIN("test_binary_tree_traversals PRE-ORDER")
   
    tree.visit_pre_order();
    int e2[] = {15, 10, 8, 6, 5, 7, 9, 12, 11, 14, 20, 17, 16, 18, 19, 25, 23, 22, 24, 27};
    std::cout << "\n";
    print_array(e2);
    TEST_END("test_binary_tree_traversals PRE-ORDER")

    TEST_BEGIN("test_binary_tree_traversals POST-ORDER")
    tree.visit_post_order();
    std::cout << "\n";
    int e3[] = {5, 7, 6, 9, 8, 11, 14, 12, 10, 16, 19, 18, 17, 22, 24, 23, 27, 25, 20, 15};
    print_array(e3);
    TEST_END("test_binary_tree_traversals POST-ORDER")
}

void test_binary_tree_search()
{
    TEST_BEGIN("test_binary_tree_search 1")
    int a[] = {15, 10, 20, 8, 12, 17, 25, 6, 11, 16, 18, 23, 27, 5, 7, 9, 14, 19, 22, 24};
    BinTree<int> tree;
  
    // Inserting elements into the tree
    for (const auto& i : a) {
        tree.insert(i);
    }
    int find = 11;
    auto p = tree.search(find);
    
    ASSERT_EQ(p->data, find);
    TEST_END("test_binary_tree_search 1")

    TEST_BEGIN("test_binary_tree_search 2")
    find = 110;
    p = tree.search(find);
    bool cmp = (p == nullptr);
    ASSERT_EQ(cmp, true);
    TEST_END("test_binary_tree_search 2")
}
void test_binary_tree_strings()
{
    const char *a[] = {
    "John", "Mary", "Jane", "Michael", "Sarah", "David", "Laura", "James", "Linda", "Robert",
    "Karen", "Joseph", "Emily", "Charles", "Jennifer", "Thomas", "Jessica", "Daniel", "Megan",
    "Matthew", "Susan", "Brian", "Amanda", "William", "Elizabeth", "Richard", "Melissa",
    "Anthony", "Michelle", "Christopher", "Lisa", "Joshua", "Kimberly", "Andrew", "Sandra",
    "Alexander", "Nancy", "Steven", "Angela", "Edward", "Heather", "Paul", "Rebecca", "Kevin",
    "Laura", "George", "Cynthia", "Jason", "Stephanie", "Timothy", "Sharon", "Mark", "Amy",
    "Jeffrey", "Anna", "Scott", "Donna", "Gary", "Deborah", "Gregory", "Carol", "Kenneth",
    "Ruth", "Ronald", "Katherine", "Patrick"};

     BinTree<const char*, decltype(cmp_str), decltype(print_str)> tree(cmp_str, print_str);
  
    // Inserting elements into the tree
    for (const auto& i : a) {
        tree.insert(i);
    }
    tree.visit_in_order();
}
/*
TC 2
first array is random, second in order expected, 3rd pre, 4th post, etc
{40, 20, 60, 10, 30, 50, 70, 5, 25, 35, 45, 55, 65, 75, 2, 8, 22, 28, 52, 58}
{2, 5, 8, 10, 20, 22, 25, 28, 30, 35, 40, 45, 50, 52, 55, 58, 60, 65, 70, 75}
{40, 20, 10, 5, 2, 8, 30, 25, 22, 28, 35, 60, 50, 45, 55, 52, 58, 70, 65, 75}
{2, 8, 5, 22, 28, 25, 35, 30, 10, 20, 45, 52, 58, 55, 50, 65, 75, 70, 60, 40}

TC 3
{50, 25, 75, 12, 37, 62, 87, 6, 18, 31, 43, 56, 68, 81, 93, 3, 9, 15, 21, 35}
{3, 6, 9, 12, 15, 18, 21, 25, 31, 35, 37, 43, 50, 56, 62, 68, 75, 81, 87, 93}
{50, 25, 12, 6, 3, 9, 18, 15, 21, 37, 31, 35, 43, 75, 62, 56, 68, 87, 81, 93}
{3, 9, 6, 15, 21, 18, 12, 31, 35, 43, 37, 25, 56, 68, 62, 81, 93, 87, 75, 50}

*/


