class BoundedBlockingQueue {
private:
    mutex mtx;
    condition_variable cond1, cond2;
    int cap;
    atomic<int> cur{0};
    queue<int> q;
public:
    BoundedBlockingQueue(int capacity) : cap(capacity) {}
    
    void enqueue(int element) {
        unique_lock<mutex> l(mtx);
        cond1.wait(l, [this]() -> bool { return cap > q.size(); });
        q.push(element);
        ++cur;
        cond2.notify_all();
    }
    
    int dequeue() {
        unique_lock<mutex> l(mtx);
        cond2.wait(l, [this]() -> bool { return !q.empty(); });

        --cur;
        auto tmp = q.front();
        q.pop();

        cond1.notify_all();

        return tmp;
    }
    
    int size() {
        return cur;
    }
};