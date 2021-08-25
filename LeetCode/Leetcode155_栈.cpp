class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        ms.push_back(x);
        ++rem[x];
    }
    
    void pop() {
        int x = ms.back();
        ms.pop_back();
        if (--rem[x] == 0) rem.erase(x);
    }
    
    int top() {
        return ms.back();
    }
    
    int getMin() {
        return rem.begin()->first;
    }
private:
    vector<int> ms;
    map<int, int, less<int>> rem;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
