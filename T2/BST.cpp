#include "BST.h"

BST::BST() {
    this -> root = nullptr;
}

void BST::insert(int value) {
    TNode* newNode = new TNode(value);
    if(!this -> root) {
        this -> root = newNode;
        return;
    }
    
    std::queue<TNode*> q;
    q.push(this -> root);

    while (!q.empty()) {
        TNode* temp = q.front();
        q.pop();

        if (temp -> left == nullptr) {
            temp -> left = new TNode(value);
            break;
        } else {
            q.push(temp->left);
        }
        if (temp -> right == nullptr) {
            temp -> right = new TNode(value);
            break;
        } else {
            q.push(temp -> right);
        }
    }
}