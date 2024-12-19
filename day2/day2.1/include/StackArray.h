#ifndef STACKARRAY_H
#define STACKARRAY_H

template <typename T>
class StackArray {
    T *arr;
    int top, size;

public:
    StackArray(int size) {
        this->size = size;
        arr = new T[size];
        top = -1;
    }
    void push(T item) {
        if (top == size-1) throw runtime_error("Stack is full.");
        else arr[++top] = item;
    }
    T pop() {
        if (top == -1) throw runtime_error("Stack is empty.");
        else return arr[top--];
    }
    T peek() {
       if (top == -1) throw runtime_error("Stack is empty.");
        else return arr[top];
    }
    void display() {
        cout << "Stack data: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << ",\t";
        }
        cout << endl;
    }

    ~StackArray() {
        delete[] arr;
    }
};

#endif // STACKARRAY_H
