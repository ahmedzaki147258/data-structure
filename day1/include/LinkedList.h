#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;

template <typename T>
class Node{
public:
    T data;
    Node<T> *next, *prev;
    Node(T data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

template <typename T>
class LinkedList{
    Node<T>* head;
    Node<T>* tail;
    int count = 0; // static

    Node<T>* findElement(T data){
        Node<T>* curr = head;
        while (curr != NULL){
            if(curr->data == data) return curr;
            curr = curr->next;
        }
        return NULL;
    }
    void swapNodeData(Node<T>* a, Node<T>* b){        
        T temp = a->data;
        a->data = b->data;
        b->data = temp;
    }

public:
    LinkedList() {
        this->head = NULL;
        this->tail = NULL;
    }

    void addNode(T data) { // always add at the end
        count++;
        Node<T>* newNode = new Node<T>(data);
        if(head == NULL){
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void addNode(int index, T data){
        if(index < 0 || index > count) return;

        Node<T>* newNode = new Node<T>(data);
        if(index == 0){ // inset at the beginning
            if(head == NULL){ // list is empty
                head = tail = newNode;
            } else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
                // head->prev = NULL; 
            } 
        } else if(index == count){ // insert at the end
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        } else {
            Node<T>* curr = head;
            for(int i=0;i<index;i++){
                curr = curr->next;
            }
            newNode->next = curr;
            newNode->prev = curr->prev;
            curr->prev->next = newNode;
            curr->prev = newNode;
        }
        count++;
    }

    void insertAfter(int afterData, T data){
        Node<T>* curr = findElement(afterData);
        if(curr != NULL){
            Node<T>* newNode = new Node<T>(data);
            newNode->prev = curr;
            newNode->next = curr->next;

            if (curr->next != NULL) {
                curr->next->prev = newNode;
            } else { // in the end
                tail = newNode;
            }

            curr->next = newNode;
            count++;
        }  
    }

    void insertBefore(int beforeData, T data){
        Node<T>* curr = findElement(beforeData);
        if(curr != NULL){
            Node<T>* newNode = new Node<T>(data);
            newNode->next = curr;
            newNode->prev = curr->prev;

            if(curr->prev != NULL){
                curr->prev->next = newNode;
            } else { // in the beginning 
                head = newNode;
            }
            curr->prev = newNode;
            count++;
        }
    }

    int getCount(){
        return count;
    }
    
    T& operator[](int index){ // getDataByIndex
        if (index < 0) {
            throw invalid_argument("Index cannot be negative");
        }

        Node<T>* curr = head;
        for(int i=0;i<index && curr!=NULL;i++){
            curr = curr->next;
        }

        if (curr == NULL) {
            throw out_of_range("Index out of bounds");
        }
        return curr->data;
    }

    void printList() {
        Node<T>* curr = head;
        while(curr != NULL){
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
    
    void removeNode(){
        if (tail == NULL) return; // List is empty

        Node<T>* temp = tail;
        if(tail->prev != NULL){
            tail = tail->prev;
            tail->next = NULL;
        } else { // list become empty
            head = tail = NULL;
        }

        delete temp;
        count--;
    }

    void removeNode(int index){
        if(head == NULL || index < 0 || index >= count) return; // list already empty or validation

        if(index == 0){ // delete at the beginning
            Node<T>* temp = head;
            head = head->next;
            if(head != NULL){
                head->prev = NULL;
            } else {
                tail = NULL; // list become empty
            }
            delete temp; // delete first element
        } else if(count-1 == index){ // delete at the end
            Node<T>* temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete temp; // delete last element
        } else {
            Node<T>* curr = head;
            for(int i=0;i<index;i++){
                curr = curr->next;
            }
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            delete curr;
        }
        count--;
    }

    void reverse(){ // recently requested by Eng. Omar
        Node<T> *start = head, *end = tail;
        for(int i=0;i<count/2;i++){
            swapNodeData(start, end);
            start = start->next;
            end = end->prev;
        }
    }

    LinkedList& operator+=(const LinkedList& other) { // recently requested by Eng. Omar
        this->count += other.count;
        if(!other.head) return *this;
        if(!this->head){
            this->head = other.head;
            this->tail = other.tail;
        } else {
            this->tail->next = other.head;
            other.head->prev = this->tail;
            this->tail = other.tail;
        }
        return *this;
    }

    ~LinkedList() {
        Node<T>* curr = head;
        while (curr != NULL){
            Node<T>* localCurrent = curr->next;
            delete curr;
            curr = localCurrent;
        }
    }
};

#endif // LINKEDLIST_H
