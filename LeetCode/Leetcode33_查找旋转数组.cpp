class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, mid;
        while (l <= r) {
            mid = l + (r - l) / 2;
            // cout << l << ' ' << mid << ' ' << r << '\n';
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) {
                if (nums[mid] >= nums[l]) {
                    if (nums[l] == target) return l;
                    else if (nums[l] < target) {
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                } else {
                    r = mid - 1;
                }
            } else {
                if (nums[mid] >= nums[l]) {
                    l = mid + 1;
                } else {
                    if (nums[r] == target) return r;
                    else if (nums[r] < target) {
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                }
            }
        }
        
        return -1;
    }
};
