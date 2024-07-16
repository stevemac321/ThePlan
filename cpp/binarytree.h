
#pragma once
template <Numeric DataType>
struct BNode {
    DataType data;
    int count = 1;
    BNode<DataType>* right = nullptr;
    BNode<DataType>* left = nullptr;

    // Disable copy and move operations
    BNode(const BNode& other) = delete;
    BNode& operator=(const BNode& other) = delete;
    BNode(BNode&& other) = delete;
    BNode& operator=(BNode&& other) = delete;

    // Constructor
    BNode(const DataType& val) : data(val) {}

    // Destructor
    ~BNode() {
        delete left;
        delete right;
    }
};

template <typename DataType>
class BinTree {
    BNode<DataType>* root = nullptr;

    BNode<DataType>* inner_insert(BNode<DataType>* p, const DataType& data) {
        if (p == nullptr) {
            return new BNode<DataType>(data);
        }
        if (data == p->data) {
            p->count++;
        } else if (data < p->data) {
            p->left = inner_insert(p->left, data);
        } else {
            p->right = inner_insert(p->right, data);
        }
        return p;
    }

    void inner_visit(BNode<DataType>* p) const {
        if (p) {
            inner_visit(p->left);
            std::cout << p->data << " ";
            inner_visit(p->right);
        }
    }

    BNode<DataType>* find_min(BNode<DataType>* p) {
        while (p && p->left != nullptr) {
            p = p->left;
        }
        return p;
    }

    BNode<DataType>* inner_remove(BNode<DataType>* p, const DataType& data) {
        if (p == nullptr) {
            return nullptr;
        }
        if (data < p->data) {
            p->left = inner_remove(p->left, data);
        } else if (data > p->data) {
            p->right = inner_remove(p->right, data);
        } else {
            // Node found
            if (p->left == nullptr) {
                BNode<DataType>* temp = p->right;
                p->right = nullptr; // Prevents destructor from deleting the subtree
                delete p;
                return temp;
            } else if (p->right == nullptr) {
                BNode<DataType>* temp = p->left;
                p->left = nullptr; // Prevents destructor from deleting the subtree
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

public:
    ~BinTree() {
        delete root;
    }

    void remove(const DataType& data) {
        root = inner_remove(root, data);
    }

    void visit() const {
         std::cout << "---------------Tree Visit-------------------\n ";
        inner_visit(root);
         std::cout << "\n---------------End Tree Visit-------------\n ";
    }

    void insert(const DataType& data) {
        root = inner_insert(root, data);
    }
};

