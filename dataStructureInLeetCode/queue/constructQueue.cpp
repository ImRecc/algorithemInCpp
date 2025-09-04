class MyCircularQueue {
    vector<int> elements; // 固定长度数组
    int front, rear, capacity, size; // 指针和大小
public:
    MyCircularQueue(int k) {
        elements = vector<int>(k); // 固定容量 k
        front = 0;
        rear = 0;
        capacity = k;
        size = 0; // 当前元素数
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        elements[rear] = value;
        rear = (rear + 1) % capacity; // 环形移动
        size++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity; // 环形移动
        size--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return elements[front];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return elements[(rear - 1 + capacity) % capacity]; // 最后一个元素
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};
