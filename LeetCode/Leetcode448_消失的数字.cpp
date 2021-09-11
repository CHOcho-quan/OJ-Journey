class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<bool> c(n, false);
        vector<int> result;
        for (auto& num : nums) c[num - 1] = true;
        for (int i = 1; i < n + 1; ++i) if (!c[i - 1]) result.push_back(i);
        return result;
    }
};
