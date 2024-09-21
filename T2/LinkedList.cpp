#include "LinkedList.h"

LinkedList::LinkedList() {
    this -> head = nullptr;
}

void LinkedList::insertAtBeginning(int value) {
    Node* newNode = new Node(value);
    newNode -> next = this -> head;
    this -> head = newNode;

}

void LinkedList::insertAtEnd(int value) {
    Node* newNode = new Node(value);
    
    if (!this -> head) {
        this -> head = newNode;
        return;
    }    

    Node* temp = this -> head;
    while (temp -> next) {
        temp = temp -> next;
    }
    temp -> next = newNode;
}

void LinkedList::deleteFromBeginning() {
    if (!this -> head) {
        return;
    }

    Node* temp = this -> head; 
    this -> head = this -> head -> next; 
    delete temp;      
}

void LinkedList::deleteFromEnd() {
    if (!this -> head) {
        return;
    }

    if (!this -> head -> next) {
        delete head;   
        head = nullptr;   
        return;
    }

    Node* temp = this -> head;
    while (temp -> next -> next) {
        temp = temp -> next;
    }
    delete temp -> next; 
    temp -> next = nullptr; 
}

bool LinkedList::find(int key) {
    Node* current = this -> head;
    while (current -> next) {
        if (current -> data == key) {
            return true;
        } else if (current -> data > key) {
            break;
        }
        current = current -> next;
    }
    return false;
}