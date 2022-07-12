class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        vector<int> bucket(k, 0);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k) return false;
        int target = sum / k;
        
        bool res = false;
        std::function<void(int, int)> dfs = [&](int ind, int tar) {
            if (ind == nums.size()) {
                for (auto& b : bucket) {
                    if (b != tar) return;
                }
                res = true;
                return;
            }
            if (res) return;
            for (int i = 0; i < k; ++i) {
                if (bucket[i] + nums[ind] > tar) continue;
                bucket[i] += nums[ind];
                dfs(ind + 1, tar);
                bucket[i] -= nums[ind];
            }
        };
        
        sort(nums.begin(), nums.end(), greater<int>());
        dfs(0, target);
        
        return res;
    }
};
