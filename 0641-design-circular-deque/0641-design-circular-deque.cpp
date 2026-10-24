

class MyCircularDeque {
private:
    vector<int> arr;
    int capacity, front, sz;

public:
    MyCircularDeque(int k) {
        capacity = k;
        arr.resize(k);
        front = 0;
        sz = 0;
    }

    bool insertFront(int value) {
        if (isFull())
            return false;

        front = (front - 1 + capacity) % capacity;
        arr[front] = value;
        sz++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull())
            return false;

        int rear = (front + sz) % capacity;
        arr[rear] = value;
        sz++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty())
            return false;

        front = (front + 1) % capacity;
        sz--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty())
            return false;

        sz--;
        return true;
    }

    int getFront() {
        if (isEmpty())
            return -1;

        return arr[front];
    }

    int getRear() {
        if (isEmpty())
            return -1;

        int rear = (front + sz - 1) % capacity;
        return arr[rear];
    }

    bool isEmpty() {
        return sz == 0;
    }

    bool isFull() {
        return sz == capacity;
    }
};
