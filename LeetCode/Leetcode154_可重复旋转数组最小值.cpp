class Solution {
public:
    int findMin(vector<int>& nums) {
        int result = nums[0], low = 0, high = nums.size() - 1, mid;
        while (low <= high) {
            mid = low + (high - low) / 2;
            // std::cout << low << ' ' << mid << ' ' << high << '\n';
            if (nums[low] == nums[mid]) {
                result = std::min(nums[low], result);
                ++low;
            } else if (nums[low] < nums[mid]) {
                result = std::min(nums[low], result);
                low = mid + 1;
            } else {
                result = std::min(nums[mid], result);
                high = mid - 1;
            }
        }
        return result;
    }
};
