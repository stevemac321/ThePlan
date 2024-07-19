
#pragma once
template <typename DataType>
struct BNode {
    DataType data;
    int count = 1;
    BNode<DataType>* right = nullptr;
    BNode<DataType>* left = nullptr;
    BNode<DataType>* parent = nullptr;

    // Disable copy and move operations
    BNode(const BNode& other) = delete;
    BNode& operator=(const BNode& other) = delete;
    BNode(BNode&& other) = delete;
    BNode& operator=(BNode&& other) = delete;

    // Constructor
    BNode(const DataType& val, BNode<DataType> *parent) : data(val), parent(parent) {}

    // Destructor
    ~BNode() {
        delete left;
        delete right;
    }
};

auto print_int = [](BNode<int> *p) { std::cout << p->data << " "; };
auto print_str = [](BNode<const char*> *p) { std::cout << p->data << " "; };

auto cmp_int = [](const int &key, const int &pdata) {
    if(key == pdata) {
        return 0;
    }else if (key < pdata) {
        return -1;
    } else {
        return 1;
    };
};
auto cmp_str = [](const char *key, const char *pdata) {return std::strcmp(key, pdata);};

template <typename DataType, typename Compare = decltype(cmp_int), typename Func = decltype(print_int)>
class BinTree {
    BNode<DataType>* root = nullptr;
    Compare comp;
    Func func;

   BNode<DataType>* inner_insert(BNode<DataType>* p, const DataType& data, BNode<DataType>* parent) 
   {
        if (p == nullptr) {
            return new BNode<DataType>(data, parent);
        }
        if (comp(data, p->data) == 0) {
            p->count++;
        } else if (comp(data, p->data) == -1) {
            p->left = inner_insert(p->left, data, p);
        } else {
            p->right = inner_insert(p->right, data, p);
        }
        return p;
    }
    
    void inner_visit_in_order(BNode<DataType>* p) const {
        if (p) {
            inner_visit_in_order(p->left);
            func(p);
            inner_visit_in_order(p->right);
        }
    }

    void inner_visit_pre_order(BNode<DataType>* p) const {
        if (p) {
            func(p);
            inner_visit_pre_order(p->left);
            inner_visit_pre_order(p->right);
        }
    }
    void inner_visit_post_order(BNode<DataType>* p) const {
        if (p) {
            inner_visit_post_order(p->left);
            inner_visit_post_order(p->right);
            func(p);
        }
    }
    void inner_get_test_vector(BNode<DataType>* p, std::vector<DataType>& v) {
        if (p) {
            inner_get_test_vector(p->left, v);
            v.push_back(p->data);
            inner_get_test_vector(p->right, v);
        }
    }
 BNode<DataType>* successor(BNode<DataType>* x) 
 {
    if(x == nullptr) {
        return nullptr;
    }
    if(x->right != nullptr) {
        return find_min(x->right);
    }
    BNode<DataType> *y = x->parent;
    while(y != nullptr && x == y->right) {
        x = y;
        y = y->parent;
    }
    return y;
 }
 BNode<DataType>* predecessor(BNode<DataType>* x) 
 {
    if(x == nullptr) {
        return nullptr;
    }
    if(x->left != nullptr) {
        return find_max(x->left);
    }
    BNode<DataType> *y = x->parent;
    while(y != nullptr && x == y->left) {
        x = y;
        y = y->parent;
    }
    return y;
 }
    BNode<DataType>* find_min(BNode<DataType>* p) 
    {
        while (p && p->left != nullptr) {
            p = p->left;
        }
        return p;
    }
    BNode<DataType>* find_max(BNode<DataType>* p) 
    {
        while (p && p->right != nullptr) {
            p = p->right;
        }
        return p;
    }
     BNode<DataType>* inner_search(BNode<DataType>* p, DataType &key) 
    {
        /*
        iterative:
        while(p != nullptr && key != p->data) {
            if(key < p->data) {
                p = p->left;
            } else {
                p = p->right
            }
            return p;
        }
        */
        if(p == nullptr || comp(key, p->data)== 0) {
            return p;
        }

        if(comp(key, p->data)== -1) {
            return inner_search(p->left, key);
        }else {
            return inner_search(p->right, key);
        }
    }
   
    BNode<DataType>* inner_remove(BNode<DataType>* p, const DataType& data) {
        if (p == nullptr) {
            return nullptr;
        }
        if (comp(data, p->data) == -1) {
            p->left = inner_remove(p->left, data);
        } else if (comp(data, p->data) == 1) {
            p->right = inner_remove(p->right, data);
        } else {
            // Node found
            if (p->left == nullptr) {
                BNode<DataType>* temp = p->right;
                if (temp != nullptr) {
                    temp->parent = p->parent; // Update parent pointer
                }
                delete p;
                return temp;
            } else if (p->right == nullptr) {
                BNode<DataType>* temp = p->left;
                if (temp != nullptr) {
                    temp->parent = p->parent; // Update parent pointer
                }
                delete p;
                return temp;
            } else {
                // Two children case
                BNode<DataType>* succ = find_min(p->right);
                p->data = succ->data;
                p->right = inner_remove(p->right, succ->data);
            }
        }
        return p;
    }
    BNode<DataType>* inner_remove_no_copy(BNode<DataType>* p, const DataType& data) {
    if (p == nullptr) {
        return nullptr;
    }
    if (comp(data, p->data) == -1) {
        p->left = inner_remove(p->left, data);
    } else if (comp(data, p->data) == 1) {
        p->right = inner_remove(p->right, data);
    } else {
        if (p->left == nullptr) {
            BNode<DataType>* temp = p->right;
            if (temp != nullptr) {
                temp->parent = p->parent;
            }
            delete p;
            return temp;
        } else if (p->right == nullptr) {
            BNode<DataType>* temp = p->left;
            if (temp != nullptr) {
                temp->parent = p->parent;
            }
            delete p;
            return temp;
        } else {
            BNode<DataType>* succ = find_min(p->right);
            succ->left = p->left;
            if (p->left) {
                p->left->parent = succ;
            }
            if (succ->parent != p) {
                succ->parent->left = succ->right;
                if (succ->right) {
                    succ->right->parent = succ->parent;
                }
                succ->right = p->right;
                if (p->right) {
                    p->right->parent = succ;
                }
            }
            succ->parent = p->parent;
            delete p;
            return succ;
        }
    }
    return p;
}


public:
    BinTree(Compare compare = cmp_int, Func func=print_int) : comp(compare), func(func) {}
    ~BinTree() {
        delete root;
    }

    void remove(const DataType& data) 
    {
        root = inner_remove(root, data);
    }
    void remove_no_copy(const DataType& data) 
    {
        root = inner_remove_no_copy(root, data);
    }
    void visit_in_order() const 
    {
        inner_visit_in_order(root);
    }
    
    void visit_pre_order() const 
    {
        inner_visit_pre_order(root);
    }
    void visit_post_order() const 
    {
        inner_visit_post_order(root);
    }
    BNode<DataType>* search(DataType &key) 
    {
        return inner_search(root, key);
    }
    std::vector<DataType> get_test_vector() 
    {
        std::vector<DataType> v;
        inner_get_test_vector(root, v);
        return v;
    }

    void insert(const DataType& data) {
        root = inner_insert(root, data, nullptr);
    }
};
/////////////////////////////////////////////////////////
 
#include "bintree_test.h"

 