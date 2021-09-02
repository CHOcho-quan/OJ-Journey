class Solution {
public:
    vector<vector<int>> rem;
    
    int solve(vector<int>& nums, vector<int>& cur, int l, int r) {
        if (l >= r - 1) return 0;
        if (rem[l][r] != -1) return rem[l][r];
        int round = 0;
        for (int i = l + 1; i <= r - 1; ++i) {
            int n = nums[i - 1];
            cur[i] = n;
            round = max(n * cur[l] * cur[r] + solve(nums, cur, l, i) + solve(nums, cur, i, r), round);
            cur[i] = 0;
        }
        
        rem[l][r] = round;
        return round;
    }
    
    int maxCoins(vector<int>& nums) {
        int len = nums.size();
        vector<int> cur(len, 0);
        cur.push_back(1);
        cur.insert(cur.begin(), 1);
        
        rem = vector<vector<int>>(cur.size(), vector<int>(cur.size(), -1));
        
        return solve(nums, cur, 0, cur.size() - 1);
    }
};
