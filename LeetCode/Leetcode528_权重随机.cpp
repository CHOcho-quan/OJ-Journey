class Solution {
public:
    Solution(vector<int>& w) : sum_(move(w)) {
        for (int i = 1; i < sum_.size(); ++i) {
            sum_[i] += sum_[i - 1];
        }
    }
    
    int pickIndex() {
        int len = sum_.size() - 1, total = sum_[len];
        int rander = rand() % (total);
        for (int i = 0; i < sum_.size(); ++i) {
            if (rander < sum_[i]) return i;
        }
        
        return len;
    }
private:
    vector<int> sum_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
