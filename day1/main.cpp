#include <iostream>
#include "./include/LinkedList.h"
using namespace std;
int main(){
    LinkedList<double> list;
    list.addNode(4); // insert with (data)
    list.addNode(11);
    list.addNode(23);
    list.addNode(7);
    list.addNode(19);
    list.addNode(0, 45); // insert with (index, data)
    list.insertAfter(7, 130.7); // insert with (afterData, data)
    list.insertBefore(45, 46.5); // insert with (beforeData, data)
    list.removeNode(); // remove at the end
    list.removeNode(2); // remove with (index)
    list.printList();

    int lengthOfLinkedList = LinkedList<double>::getCount();
    cout << "count: " << lengthOfLinkedList << endl;
    
    for(int i=0; i<lengthOfLinkedList; i++){
        try {
            cout << "list[" << i << "]: " << list.getDataByIndex(i) << endl;
        } catch (const exception& e) {
            cout << e.what() << endl;
        }
    }
   
    return 0;
}
