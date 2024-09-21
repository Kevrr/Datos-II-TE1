#ifndef BST_H
#define BST_H

#include <queue>

struct TNode {
    int data;
    TNode* left;
    TNode* right;
    TNode(int value) {
        data = value;
        left = right = nullptr;
    }
};

class BST {
private:
    TNode* root;
public:
    BST();
    void insert(int value);
    ~BST();
};

#endif