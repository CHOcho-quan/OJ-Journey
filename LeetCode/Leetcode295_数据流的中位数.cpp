/*
 q1, q2
 if q1.empty()
 q1.posh(e)
 cur1 = q1.top()
 if e > cur1
 q1.push(e)
 else
 q2.push(e)
 
 if (abs(q1.size() - q2.size()) >= 2)
 */

class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        ++cnt;
        if (pq_g_.empty()) {
            pq_g_.push(num);
            return;
        }
        auto cur = pq_g_.top();
        if (num > cur) {
            pq_g_.push(num);
        } else {
            pq_l_.push(num);
        }
        
        int diff = pq_g_.size() - pq_l_.size();
        if (diff == 2) {
            auto moved = pq_g_.top();pq_g_.pop();
            pq_l_.push(moved);
        } else if (diff == -2) {
            auto moved = pq_l_.top();pq_l_.pop();
            pq_g_.push(moved);
        }
    }
    
    double findMedian() {
        if (cnt % 2) {
            if (pq_g_.size() > pq_l_.size()) {
                return pq_g_.top();
            } else {
                return pq_l_.top();
            }
        } else {
            int g1 = pq_g_.top(), l1 = pq_l_.top();
            double res = static_cast<double>(l1 + g1) / 2.0;
            return res;
        }
    }
private:
    int cnt = 0;
    priority_queue<int, vector<int>, greater<int>> pq_g_;
    priority_queue<int, vector<int>, less<int>> pq_l_;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
