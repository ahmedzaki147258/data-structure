#ifndef TREE_H
#define TREE_H
#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node<T>* left;
    Node<T>* right;
    Node(T data) {
        this->data = data;
        this->left = this->right = NULL;
    }
};

template <typename T>
class Tree{
    Node<T>* root;
    void display(Node<T>* node) {
        if(node == NULL) return;
        display(node->left);
        cout << node->data << ", ";
        display(node->right);
    }
    Node<T>* getNodeByData(T data){
        Node<T>* curr = root;
        while(curr != NULL){
            if(data == curr->data) return curr;
            else if(data < curr->data) curr = curr->left;
            else if(data > curr->data) curr = curr->right;
        }
        return NULL;
    }
    Node<T>* getParent(Node<T>* node){
        Node<T>* parent = root;
        while(parent != NULL){
            if(node == parent->left || node == parent->right) return parent;
            else if(node->data < parent->data) parent = parent->left;
            else if(node->data > parent->data) parent = parent->right;
        }
        return NULL;
    }
    Node<T>* getMaxRight(Node<T>* node){
        Node<T>* curr = node;
        while(curr->right != NULL) curr = curr->right;
        return curr;
    }
    Node<T>* getMinLeft(Node<T>* node){
        Node<T>* curr = node;
        while(curr->left != NULL) curr = curr->left;
        return curr;
    }
public:
    Tree() {
        this->root = NULL;
    }
    void insert(T data) {
        Node<T>* newNode = new Node<T>(data);
        if(root == NULL) {
            root = newNode;
        } else {
            Node<T>* curr = root;
            Node<T>* parent = NULL;
            while(curr != NULL) {
                parent = curr;
                if(data == curr->data) return;
                else if(data < curr->data) curr = curr->left;
                else if(data > curr->data) curr = curr->right; 
            }
            if(data < parent->data) parent->left = newNode;
            else if(data > parent->data) parent->right = newNode;
        }
    }
    bool isContains(T data) {
        return getNodeByData(data) != NULL;
    }
    T getParentBydata(T data){
        Node<T>* node = getNodeByData(data);
        if(node == root) throw runtime_error("The Node is Root Not Have Parent.");
        if(node == NULL) throw runtime_error("Node Not Found.");
        else return getParent(node)->data;
    }
    T getMinLeftByData(T data){
        Node<T>* node = getNodeByData(data);
        if(node == NULL) throw runtime_error("Node Not Found.");
        return getMinLeft(node)->data;
    }
    T getMaxRightByData(T data){
        Node<T>* node = getNodeByData(data);
        if(node == NULL) throw runtime_error("Node Not Found.");
        return getMaxRight(node)->data;
    }
    void remove(T data){
        Node<T>* node = getNodeByData(data);
        if (node == NULL) throw runtime_error("Node Not Found.");
        if(node == root){
            if(node->left == NULL && node->right == NULL){
                root = NULL;
                delete node;
                return;
            } else if(node->left == NULL){
                root = node->right;
                delete node;
                return;
            } else if(node->right == NULL){
                root = node->left;
                delete node;
                return;
            } else {
                Node<T>* maxRight = getMaxRight(node->left);
                maxRight->right = node->right;
                root = node->left;
                return;
            }
        } else {
            Node<T>* parent = getParent(node);
            if(node->left == NULL && node->right == NULL){
                if(parent->left == node) parent->left = NULL;
                else parent->right = NULL;
                delete node;
            } else if(node->left == NULL){
                if(parent->left == node) parent->left = node->right;
                else parent->right = node->right;
                delete node;
            } else if(node->right == NULL){
                if(parent->left == node) parent->left = node->left;
                else parent->right = node->left;
                delete node;
            } else {
                Node<T>* maxRight = getMaxRight(node->left);
                maxRight->right = node->right;
                if(parent->left == node) parent->left = node->left;
                else parent->right = node->left;
                delete node;
            }
        }
    }
    void display() {
        cout << "TreeData: [";
        display(root);
        cout << "\b\b]" << endl;
    }
};

#endif // TREE_H
