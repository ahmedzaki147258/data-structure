#ifndef QUEUELINKEDLIST_H
#define QUEUELINKEDLIST_H
#include <iostream>
#include "./Node.h"
using namespace std;

template <typename T>
class QueueLinkedList {
    Node<T> *front, *rear;
    bool isEmpty(){
        return front == NULL;
    }
    
public:
    QueueLinkedList() { front = rear = NULL; }
    void enqueue(T data) {
        Node<T>* new_node = new Node<T>(data);
        if (this->isEmpty()) {
            front = rear = new_node;
            return;
        }
        rear->next = new_node;
        rear = new_node;
    }
    void dequeue() {
        if (isEmpty()) throw runtime_error("Queue is empty");
        Node<T>* temp = front;
        front = front->next;
        if (front == NULL) rear = NULL; // queue become empty
        delete temp;
    }
    T getFront() {
        if (isEmpty()) throw runtime_error("Queue is empty");
        return front->data;
    }
    T getRear() {
        if (isEmpty()) throw runtime_error("Queue is empty");
        return rear->data;
    }
    void display() {
        Node<T>* current = front;
        cout << "Queue contents: ";
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    ~QueueLinkedList() {
        while (!isEmpty()) dequeue();
    }
};

#endif // QUEUELINKEDLIST_H
