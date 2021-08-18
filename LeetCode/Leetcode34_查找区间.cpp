class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int high = nums.size() - 1, low = 0, mid;
        vector<int> result = {-1, -1};
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (nums[mid] == target) break;
            if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        // std::cout << low << ' ' << mid << ' ' << high;
        if (low > high) {
            return result;
        }
        for (int i = mid; i >= 0; --i) {
            if (nums[i] == target) result[0] = i;
            else break;
        }
        for (int i = mid; i < nums.size(); ++i) {
            if (nums[i] == target) result[1] = i;
            else break;
        }
        return result;
    }
};
