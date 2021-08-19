class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, mid;
        while (low <= high) {
            mid = low + (high - low) / 2;
            // std::cout << low << ' ' << mid << ' ' << high << '\n';
            if (nums[low] < nums[mid]) {
                if (target == nums[mid]) return true;
                else if (target < nums[mid] && target >= nums[low]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else if (nums[low] == nums[mid]) {
                if (target == nums[mid]) return true;
                ++low;
            } else {
                if (target == nums[mid]) return true;
                else if (target > nums[mid] && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};
