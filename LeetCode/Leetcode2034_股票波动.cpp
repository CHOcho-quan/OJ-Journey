class StockPrice {
public:
    StockPrice() {

    }
    
    void update(int timestamp, int price) {
        latest = max(timestamp, latest);
        t2p[timestamp] = price;
        pq_max.push(pair<int, int>(price, timestamp));
        pq_min.push(pair<int, int>(price, timestamp));
    }
    
    int current() {
        return t2p[latest];
    }
    
    int maximum() {
        bool flag = true;
        while (flag) {
            auto cur_max = pq_max.top();
            if (t2p[cur_max.second] == cur_max.first) flag = false;
            else pq_max.pop();
        }
        return pq_max.top().first;
    }
    
    int minimum() {
        bool flag = true;
        while (flag) {
            auto cur_min = pq_min.top();
            if (t2p[cur_min.second] == cur_min.first) flag = false;
            else pq_min.pop();
        }
        return pq_min.top().first;
    }

    priority_queue<pair<int, int>> pq_max;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq_min;
    unordered_map<int, int> t2p;
    int latest = 0;
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */