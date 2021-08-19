class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, mid, result = nums[0];
        if (nums.size() == 1) return result;
        // Special
        if (nums[1] != nums[0]) return nums[0];
        if (nums[high] != nums[high - 1]) return nums[high];
        while (low <= high) {
            mid = low + (high - low) / 2;
            // std::cout << low << ' ' << mid << ' ' << high  << '\n';
            if ((mid) % 2) {
                // mid to high consist of even number
                if (mid != 0 && nums[mid-1] == nums[mid]) {
                    low = mid + 1;
                } else if (mid != nums.size() - 1 && nums[mid+1] == nums[mid]) {
                    high = mid - 1;
                } else return nums[mid];
            } else {
                // low to mid-1 consist of even number
                if (mid != 0 && nums[mid-1] == nums[mid]) {
                    high = mid - 1;
                } else if (mid != nums.size() - 1 && nums[mid+1] == nums[mid]) {
                    low = mid + 1;
                } else return nums[mid];
            }
        }
        // std::cout << low << ' ' << mid << ' ' << high  << '\n';
        return result;
    }
};
