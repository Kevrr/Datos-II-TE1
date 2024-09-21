#include "BST.h"

BST::BST() {
    this -> root = nullptr;
}

void BST::insert(int value) {
    Node* newNode = new Node(value);
    if(!this -> root) {
        this -> root = newNode;
        return;
    }
    
    std::queue<Node*> q;
    q.push(this -> root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp -> left == nullptr) {
            temp -> left = new Node(value);
            break;
        } else {
            q.push(temp->left);
        }
        if (temp -> right == nullptr) {
            temp -> right = new Node(value);
            break;
        } else {
            q.push(temp -> right);
        }
    }
}