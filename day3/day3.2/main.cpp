#include <iostream>
#include "./include/Sort.h"
using namespace std;

int main(){
    // vector<int> arr = {5, 2, 3, 1, 4, 6, 14, 12, 11, 10, 9, 8, 7, 15, 13};
    vector<double> arr = {3.14, 2.71, 1.62, 9.81, 7.89, 6.28, 4.56, 8.77, 5.43, 0.99, 10.01, 12.34, 11.11, 14.58, 13.37};
    Sort<double> sort(arr);

    sort.shuffle();
    sort.bubbleSort();
    sort.print("Bubble    Sort");

    sort.shuffle();
    sort.selectionSort();
    sort.print("Selection Sort");

    sort.shuffle();
    sort.insertionSort();
    sort.print("Insertion Sort");

    sort.shuffle();
    sort.mergeSort(0, arr.size()-1);
    sort.print("Merge     Sort");

    sort.shuffle();
    sort.quickSort(0, arr.size()-1);
    sort.print("Quick     Sort");
    return 0;
}
