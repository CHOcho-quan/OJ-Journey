class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;
        
        map<int, int, greater<int>> rem;
        for (int i = 0; i < k; ++i) ++rem[nums[i]];
        
        result.push_back(rem.begin()->first);
        for (int i = k; i < n; ++i) {
            if (--rem[nums[i - k]] == 0) rem.erase(nums[i - k]);
            ++rem[nums[i]];
            result.push_back(rem.begin()->first);
        }
        
        return result;
    }
};
