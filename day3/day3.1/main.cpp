#include <iostream>
#include <vector>
using namespace std;

void swap(int&, int&); // helper
void printVector(const vector<int>&); // helper
void bubbleSort(vector<int>&);
int linearSearch(vector<int>, int);
int binarySearchIterative(vector<int>&, int);
int binarySearchRecursive(vector<int>&, int, int, int);
vector<int> linearSearchMultipleOccurrences(vector<int>&, int);
int main(){
    vector<int> v = {9, 22, 13, 3, 77, 65, 3, 11, 47};

    cout << "\nLinearSearch: ";
    int index = linearSearch(v, 3);
    if(index == -1) cout << "Not found!" << endl;
    else cout << "Found at index[" << index << "]" << endl;

    cout << "LinearSearchMultipleOccurrences: ";
    vector<int> result = linearSearchMultipleOccurrences(v, 3);
    if(result.size() == 0) cout << "Not found!" << endl;
    else {
        cout << "Found at indexes[";
        for(int i=0; i<result.size(); i++){
            cout << result[i] << ((i==result.size()-1) ? "" : ", ");
        }
        cout << "]" << endl;
    }
    cout << "==========================================================\n";

    cout << "\nBefore sort "; printVector(v);
    bubbleSort(v);
    cout << "After  sort "; printVector(v);
    cout << "==========================================================\n";

    cout << "\nBinarySearchIterative: ";
    index = binarySearchIterative(v, 9);
    if(index == -1) cout << "Not found!" << endl;
    else cout << "Found at index[" << index << "]" << endl;

    cout << "BinarySearchRecursive: ";
    index = binarySearchRecursive(v, 0, v.size()-1, 22);
    if(index == -1) cout << "Not found!" << endl;
    else cout << "Found at index[" << index << "]" << endl;
    cout << "==========================================================\n";
    return 0;
}

int linearSearch(vector<int> arr, int target){
    for(int i=0; i<arr.size(); i++){
        if(arr[i] == target) return i;
    }
    return -1;
}
vector<int> linearSearchMultipleOccurrences(vector<int>& arr, int target){
    vector<int> result;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] == target) result.push_back(i);
    }
    return result;
}
void swap(int& a, int& b){
    int tmp = a;
    a = b;
    b = tmp;
}
void bubbleSort(vector<int>& arr){
    int vectorSize = arr.size();
    for(int i=0;i<vectorSize-1;i++){
        for(int j=0;j<vectorSize-i-1;j++){
            if(arr.at(j) > arr.at(j+1)) swap(arr.at(j), arr.at(j+1));
        }
    }
}
int binarySearchIterative(vector<int>& arr, int target){
    int left = 0, right = arr.size()-1;
    while (left<=right){
        int mid = (left + right) / 2;
        if(arr.at(mid) == target) return mid;
        if(arr.at(mid) < target) left = mid+1;
        else right = mid-1;
    }
    return -1;
}
int binarySearchRecursive(vector<int>& arr, int left, int right, int target){
    if (left>right) return -1;
    int mid = (left + right) / 2;
    if(arr.at(mid) == target) return mid;
    if(arr.at(mid) < target) return binarySearchRecursive(arr, mid+1, right, target);
    else return binarySearchRecursive(arr, left, mid-1, target);
}
void printVector(const vector<int>& arr){
    cout << "vector data: [";
    for(int i=0;i<arr.size();i++){
        cout << arr.at(i) << ((i==arr.size()-1) ? "" : ", ");
    }
    cout << "]" << endl;
}
