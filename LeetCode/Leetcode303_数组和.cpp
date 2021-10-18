class NumArray {
public:
    NumArray(vector<int>& nums) : prefix(nums.size() + 2, 0) {
        prefix[1] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        prefix[nums.size() + 1] = prefix[nums.size()];
        // for (auto& ps : prefix) cout << ps << ' ';
    }
    
    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
private:
    vector<int> prefix;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
