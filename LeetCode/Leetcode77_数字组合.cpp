class Solution {
public:
    std::vector<std::vector<int>> result = {};
    
    void backtrace(vector<int>& nums, vector<int>& tmp, int first, int len, int k) {
        if (tmp.size() == k) {
            result.push_back(tmp);
            return;
        }
        
        for (int i = first; i < len; ++i) {
            tmp.push_back(nums[i]);
            swap(nums[first], nums[i]);
            backtrace(nums, tmp, first + 1, len, k);
            swap(nums[first], nums[i]);
            tmp.pop_back();
            ++first;
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums, tmp;
        for (int i = 0; i < n;) nums.push_back(++i);
        backtrace(nums, tmp, 0, n, k);
        return result;
    }
};
