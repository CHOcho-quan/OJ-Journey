class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> rec;
        for (auto& n : nums) rec.insert(n);
        
        int res = 0;
        for (auto n : rec) {
            if (!rec.count(n + 1)) {
                int cur = 1;
                while (rec.count(n - 1)) {
                    n = n - 1;
                    ++cur;
                }
                res = max(cur, res);
            }
        }
        
        return res;
    }
};
