class Solution {
public:
    Solution(vector<int>& nums) : rem_(move(nums))
    {}
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return rem_;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        if (rem_.empty()) return {};
        vector<int> shuffled(rem_);
        int n = rem_.size();
        for (int i = n - 1; i >= 0; --i) {
            swap(shuffled[i], shuffled[rand() % (i + 1)]);
        }
        
        return shuffled;
    }
private:
    vector<int> rem_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
