#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;

template <typename T>
class Node{
public:
    T data;
    Node<T>* next;
    Node<T>* prev;

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
    static int count;

    Node<T>* findElement(T data){
        Node<T>* curr = head;
        while (curr != NULL){
            if(curr->data == data) return curr;
            curr = curr->next;
        }
        return NULL;
    }
public:
    LinkedList() {
        this->head = NULL;
        this->tail = NULL;
    }

    void addNode(T data) { // always add at the end
        LinkedList::count++;
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
        if(index < 0 || index > LinkedList::count) return;

        Node<T>* newNode = new Node<T>(data);
        if(index == 0){ // inset at the beginning
            if(head == NULL){ // list is empty
                head = tail = newNode;
            } else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
                head->prev = NULL; 
            } 
        } else if(index == LinkedList::count){ // insert at the end
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
        LinkedList::count++;
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
            LinkedList::count++;
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
            LinkedList::count++;
        }
    }

    static int getCount(){
        return LinkedList::count;
    }
    
    T getDataByIndex(int index){
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
        LinkedList::count--;
    }

    void removeNode(int index){
        if(head == NULL || index < 0 || index >= LinkedList::count) return; // list already empty or validation

        if(index == 0){ // delete at the beginning
            Node<T>* temp = head;
            head = head->next;
            if(head != NULL){
                head->prev = NULL;
            } else {
                tail = NULL; // list become empty
            }
            delete temp; // delete first element
        } else if(LinkedList::count-1 == index){ // delete at the end
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
        LinkedList::count--;
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

template <typename T>
int LinkedList<T>::count = 0;

#endif // LINKEDLIST_H
