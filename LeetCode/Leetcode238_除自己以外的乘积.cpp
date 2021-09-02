class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> p1(nums), p2(nums), result(nums.size(), 0);
        for (int i = 1; i < p1.size(); ++i) p1[i] *= p1[i - 1];
        for (int i = p2.size() - 1; i > 0; --i) p2[i - 1] *= p2[i];
        
        for (int i = 0; i < p1.size(); ++i) {
            if (i == 0) result[0] = p2[i + 1];
            else if (i == p1.size() - 1) result[i] = p1[i - 1];
            else result[i] = p1[i - 1] * p2[i + 1];
        }
        
        return result;
    }
};
