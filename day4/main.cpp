#include <iostream>
#include "./include/Tree.h"
using namespace std;

int main(){
    Tree<double> tree;
    tree.insert(50.2);
    tree.insert(40.2);
    tree.insert(70.2);
    tree.insert(30.2);
    tree.insert(65.2);
    tree.insert(60.2);
    tree.insert(35.2);
    tree.insert(42.2);
    tree.insert(45.2);
    tree.insert(48.2);
    tree.insert(25.2);
    tree.insert(22.2);

    tree.isContains(70.2)?cout<<"Found \n":cout<<"Not Found \n";//Found
    tree.isContains(90.2)?cout<<"Found \n":cout<<"Not Found \n";//Not Found
    try{
        // tree.getParentBydata(50.2);
        cout << "Parent: " << tree.getParentBydata(35.2) << endl;
        cout << "MinLeft : "<< tree.getMinLeftByData(40.2) << endl;
        cout << "MaxRight: "<< tree.getMaxRightByData(40.2) << endl;
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    tree.display();
    try {
        tree.remove(50.2);
        tree.remove(35.2);
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
    tree.display();
    return 0;
}
