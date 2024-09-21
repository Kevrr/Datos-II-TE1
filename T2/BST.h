#ifndef BST_H
#define BST_H

#include <queue>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

class BST {
private:
    Node* root;
public:
    BST();
    void insert(int value);
    ~BST();
};

#endif