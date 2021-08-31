class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> c;
        set<int> result;
        
        for (auto& n : nums) {
            ++c[n];
            if (c[n] > nums.size() / 3) {
                result.insert(n);
            }
        }
        
        vector<int> re(result.begin(), result.end());
        return re;
    }
};
