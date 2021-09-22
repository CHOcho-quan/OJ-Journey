class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> add(n + 1, 0), minus(n + 1, -100001);
        minus[0] = 0;
        
        for (int i = 1; i < n + 1; ++i) {
            add[i] = max(minus[i - 1] + nums[i - 1], add[i - 1]);
            minus[i] = max(add[i - 1] - nums[i - 1], minus[i - 1]);
            // cout << add[i] << ' ' << minus[i] << '\n';
        }
        
        return max(add[n], minus[n]);
    }
};
