class RLEIterator {
public:
    RLEIterator(vector<int>& encoding) {
        int st = 0;
        for (int i = 0; i < encoding.size(); i+=2) {
            i2v[st] = encoding[i + 1];
            i2n[st++] = encoding[i];
        }
    }
    
    int next(int n) {
        if (i2v.find(cur) == i2v.end()) return -1;
        while (n - i2n[cur] > 0) {
            n -= i2n[cur];
            ++cur;
            if (i2v.find(cur) == i2v.end()) return -1;
        }
        i2n[cur] -= n;
        return i2v[cur];
    }
private:
    int cur = 0;
    unordered_map<int, int> i2v;
    unordered_map<int, int> i2n;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */