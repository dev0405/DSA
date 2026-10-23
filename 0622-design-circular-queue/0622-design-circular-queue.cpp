class MyCircularQueue {
private:
    vector<int> arr;
    int capacity;
    int front;
    int rear;
    int sz;

public:
    MyCircularQueue(int k) {
        capacity = k;
        arr.resize(k);
        front = 0;
        rear = 0;
        sz = 0;
    }
    bool enQueue(int value) {
        if (isFull())
            return false;

        arr[rear] = value;
        rear = (rear + 1) % capacity;
        sz++;

        return true;
    }
    bool deQueue() {
        if (isEmpty())
            return false;

        front = (front + 1) % capacity;
        sz--;

        return true;
    }
    int Front() {
        if (isEmpty())
            return -1;

        return arr[front];
    }
    int Rear() {
        if (isEmpty())
            return -1;

        int lastIndex = (rear - 1 + capacity) % capacity;
        return arr[lastIndex];
    }
    bool isEmpty() {
        return sz == 0;
    }
    bool isFull() {
        return sz == capacity;
    }
};