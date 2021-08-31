class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> c;
        for (auto& n : nums) {
            if (c.count(n)) return true;
            c.insert(n);
        }
        return false;
    }
};
