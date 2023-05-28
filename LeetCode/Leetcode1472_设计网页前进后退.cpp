class BrowserHistory {
private:
    int cur{0}, last{1};
    unordered_map<int, string> id2page;
public:
    BrowserHistory(string homepage) {
        id2page[cur] = homepage;
    }
    
    void visit(string url) {
        id2page[++cur] = url;
        last = cur+1;
    }
    
    string back(int steps) {
        if (cur - steps < 0) {
            cur = 0;
            return id2page[cur];
        }
        cur -= steps;
        return id2page[cur];
    }
    
    string forward(int steps) {
        if (cur + steps >= last) {
            cur = last - 1;
            return id2page[cur];
        }
        cur += steps;
        return id2page[cur];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */