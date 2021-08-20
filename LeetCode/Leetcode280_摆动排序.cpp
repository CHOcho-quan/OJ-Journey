class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<int> result = {};
        int half = (nums.size() - 1) / 2;
        for (int i = 0; i <= half; ++i) {
            result.push_back(nums[i]);
            result.push_back(0);
        }
        if (result.size() != nums.size()) {
            result.erase(result.end() - 1);
        }
        // for (auto & r : result) std::cout << r << ' ';
        int cur = 1;
        for (int i = half + 1; i < nums.size(); ++i) {
            result[cur] = nums[i];
            cur += 2;
        }
        nums = result;
    }
};
