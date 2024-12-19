#ifndef STACKLINKEDLIST_H
#define STACKLINKEDLIST_H
#include <iostream>
#include "./Node.h"
using namespace std;

template <typename T>
class StackLinkedList {
    Node<T>* head;
    bool isEmpty() {
        return head == NULL;
    }

public:
    StackLinkedList() { this->head = NULL; }
    void push(T data) {
        Node<T>* new_node = new Node<T>(data);
        new_node->next = head;
        head = new_node;
    }
    void pop() {
        if (this->isEmpty()) {
           throw runtime_error("Stack is empty");
        } else {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
    T peek() {
        if (isEmpty()) throw runtime_error("Stack is empty");
        else return head->data;
    }
    void display() {
        Node<T>* current = head;
        cout << "Stack contents: ";
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    ~StackLinkedList() {
        while (!isEmpty()) pop();
    }
};

#endif // STACKLINKEDLIST_H
