class MyCircularQueue {
private:
    int cur, size, now, head;
    vector<int> q;
public:
    MyCircularQueue(int k) : size(k) {
        q = vector<int>(k, -2);
        cur = 0;
        now = 0;
        head = 0;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        ++now;
        q[cur] = value;
        ++cur;
        cur %= size;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        --now;
        ++head;
        head %= size;
        return true;
    }
    
    int Front() {
        if (now == 0) return -1;
        return q[head];
    }
    
    int Rear() {
        if (now == 0) return -1;
        if (cur - 1 < 0) return q[size-1];
        return q[cur-1];
    }
    
    bool isEmpty() {
        return now == 0;
    }
    
    bool isFull() {
        return now == size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */