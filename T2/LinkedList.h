#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node {
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    };
};

class LinkedList {
    private:
        Node* head;

    public:
        LinkedList();
        void insertAtBeginning(int value);
        void insertAtEnd(int value);
        void deleteFromBeginning();
        void deleteFromEnd();
        bool find(int key);
        ~LinkedList();

};

#endif