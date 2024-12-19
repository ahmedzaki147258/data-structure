#include <iostream>
#include "./include/StackLinkedList.h"
#include "./include/QueueLinkedList.h"
#include "./include/StackArray.h"
#include "./include/QueueArray.h"
using namespace std;

int main(){
    // using StackLinkedList
    cout << "StackLinkedList:\n";
    StackLinkedList<double> s1;
    s1.push(11.6);
    s1.push(-22.4);
    s1.push(33.9);
    s1.push(-44.2);

    try{
        cout << "top stacklinkedlist: " << s1.peek() << endl;
        s1.pop();
        s1.pop();
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
    s1.display();


    // using StackArray
    cout << "\nStackArray:\n";
    StackArray<string> s2(5);
    try{
        s2.push("A7med");
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    try{
        s2.push("zaki");
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    try{
        s2.push("ay 7aga");
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    try{
        s2.push("wahed man4rfhosh");
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    try{
        s2.pop();
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    try{
        s2.pop();
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
 
    try{
        cout << "top stackarray: " << s2.peek() << endl;
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
    s2.display();

    /******************************************* *******************************************/
    // using QueueLinkedList
    cout << "\nQueueLinkedList:\n";
    QueueLinkedList<double> q1;
    q1.enqueue(11.6);
    q1.enqueue(-22.4);
    q1.enqueue(33.9);
    q1.enqueue(-44.2);

    try{
       cout<< "front queue: " << q1.getFront() << endl;
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    try{
        cout<< "rear queue: " << q1.getRear() << endl;
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
    q1.display();

    try{
        q1.dequeue();
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
    
    try{
        q1.dequeue();
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
    q1.display();


    // using QueueArray
    cout << "\nQueueArray:\n";
    QueueArray<double> q2(5);
    try{
       q2.enqueue(11.6);
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    try{
       q2.enqueue(-22.4);
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    try{
        q2.enqueue(33.9);
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    try{
       q2.enqueue(-44.2);
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    try{
       cout<< "front queue: " << q2.getFront() << endl;
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    try{
        cout<< "rear queue: " << q2.getRear() << endl;
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
    q2.display();

    try{
        q2.dequeue();
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
    
    try{
        q2.dequeue();
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
    q2.display();

    try{
       q2.enqueue(-40.99);
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    try{
       q2.enqueue(3.14);
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
    try{
       cout<< "front queue: " << q2.getFront() << endl;
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    try{
        cout<< "rear queue: " << q2.getRear() << endl;
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
    q2.display();

    return 0;
}
