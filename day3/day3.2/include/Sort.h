#ifndef SORT_H
#define SORT_H
#include <iostream>
#include <vector>
using namespace std;

template <typename T>  
class Sort{
    int size;
    vector<T> arr;
    void swap(T& a, T& b){
        T temp = a;
        a = b;
        b = temp;
    }
    void merge(int left, int mid, int right){
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<T> L(n1), R(n2);
        for (int i = 0; i < n1; i++) L[i] = arr[left + i];
        for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
    int partition(int low, int high) {
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return (i + 1);
    }
public:
    Sort(vector<T> arr) {
        this->arr = arr;
        this->size = arr.size();
    }
    void bubbleSort(){ // Time: O(n^2), Space: O(1)
        bool f=false;
        for(int i = 0; f==false; i++){
            f = true;
            for(int j = 0; j < size - i - 1; j++){
                if(arr[j] > arr[j+1]){
                    swap(arr[j], arr[j+1]);
                    f = false;
                }
            }
        }
    }
    void selectionSort(){ // Time: O(n^2), Space: O(1)  
        for (int i = 0; i < size - 1; ++i) {
            int min_idx = i;
            for (int j = i + 1; j < size; ++j) {
                if (arr[j] < arr[min_idx]) {
                    min_idx = j; 
                }
            }
            swap(arr[i], arr[min_idx]);
        }
    }
    void insertionSort(){ // Time: O(n^2), Space: O(1)
        for (int i = 1; i < size; i++) {
            T key = arr[i];
            int j = i-1;
            while (j>=0 && arr[j]>key) {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
        }
    }
    void mergeSort(int left, int right){ // Time: O(nlogn), Space: O(n)
        if (left >= right) return;
        int mid = (left + right) / 2;
        mergeSort(left, mid);
        mergeSort(mid+1, right);
        merge(left, mid, right);
    }
    void quickSort(int low, int high){ // Time: O(nlogn)/O(n^2), Space: O(logn)/O(n)
        if (low < high) {
            int pi = partition(low, high);
            quickSort(low, pi - 1);
            quickSort(pi + 1, high);
        }
    }
    void shuffle(){
        for(int i = 0; i < size; i++){
            int j = rand() % size;
            swap(arr[i], arr[j]);
        }
    }
    void print(string msg="Array"){
        cout << msg << ": [";
        for(int i = 0; i < size; i++){
            cout << arr.at(i) << ((i==size-1) ? "" : ", ");
        }
        cout << "]" << endl;
    }
};

#endif // SORT_H
