class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int len = q1.size() - 1;
        while (len--) {
            int tmp = q1.front();
            q1.pop();
            q1.push(tmp);
        }
        int tmp = q1.front();
        q1.pop();
        return tmp;
    }
    
    /** Get the top element. */
    int top() {
        int len = q1.size(), tmp = -1;
        while (len--) {
            tmp = q1.front();
            q1.pop();
            q1.push(tmp);
        }
        return tmp;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }
    
private:
    queue<int> q1, q2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
