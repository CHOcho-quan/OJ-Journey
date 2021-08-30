class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        if (nums.size() == 2) {
            if (nums[0] == nums[1]) return 1;
            return 2;
        }
        
        int first = -1, len = nums.size();
        for (int i = first + 1; i < len - 1; ++i) {
            if (nums[i] != nums[i + 1]) {
                first = i;
                break;
            }
        }
        if (first == -1) return 1;
        
        bool flag = nums[first] - nums[first + 1] > 0;
        int cnt = 0;
        for (int i = first + 1; i < len - 1; ++i) {
            if (flag && nums[i] - nums[i + 1] >= 0) {
                ++cnt;
                continue;
            } else if (flag) {
                flag = !flag;
                continue;
            }
            if (!flag && nums[i] - nums[i + 1] <= 0) {
                ++cnt;
            } else {
                flag = !flag;
            }
        }
        
        return len - first - cnt;
    }
};
