class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> c;
        for (auto& n : nums) {
            if (c.count(n) && c[n] == 2) {
                c.erase(n);
                continue;
            }
            ++c[n];
        }
        return c.begin()->first;
    }
};
