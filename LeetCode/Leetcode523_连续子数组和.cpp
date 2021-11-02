class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int> presum = {0};
        for (int i = 0; i < nums.size(); ++i) {
            presum.push_back(presum[i] + nums[i]);
        }
        unordered_map<int, int> divided;
        for (int i = 1; i < presum.size(); ++i) {
            auto cur = presum[i] % k;
            if (cur == 0 && i >= 2) return true;
            if (divided.count(cur)) {
                if (i - divided[cur] >= 2) return true;
                divided[cur] = min(i, divided[cur]);
            } else {
                divided[cur] = i;
            }
        }
        
        return false;
    }
};
