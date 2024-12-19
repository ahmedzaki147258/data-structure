#ifndef QUEUEARRAY_H
#define QUEUEARRAY_H

template <typename T>
class QueueArray{
    T *arr;        
    int front, rear, size, capacity;    

public:
    QueueArray(int capacity) {
        arr = new T[capacity];
        this->capacity = capacity;
        this->size = 0;
    }
    T getFront() {
        if (size == 0) throw runtime_error("Queue is empty");
        return arr[front];
    }
    T getRear() {
        if (size == 0) throw runtime_error("Queue is empty");
        return arr[rear];
    }
    void enqueue(T data) {
        if(size == 0) {front = 0; rear = -1;}
        if (size == capacity) throw runtime_error("Queue is full.");
        rear = (rear + 1) % capacity;
        arr[rear] = data;
        size++;
    }
    void dequeue() {
        if (size == 0) throw runtime_error("Queue is empty.");
        front = (front + 1) % capacity;
        size--;
    }
    void display() {
        cout << "Queue contents: ";
        for (int i=0; i < size; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
    ~QueueArray() {
        delete[] arr;
    }
};

#endif // QUEUEARRAY_H
