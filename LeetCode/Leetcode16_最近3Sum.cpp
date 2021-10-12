class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int res = 0, diff = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            int first = nums[i], tar = target - first;
            int l = i + 1, r = nums.size() - 1;
            bool found = false;
            while (l < r) {
                if (nums[l] + nums[r] == tar) {
                    found = true;
                    break;
                } else if (nums[l] + nums[r] > tar) {
                    if (abs(nums[l] + nums[r] -  tar) < diff) {
                        diff = abs(nums[l] + nums[r] -  tar);
                        res = first + nums[l] + nums[r];
                    }
                    --r;
                } else {
                    if (abs(nums[l] + nums[r] -  tar) < diff) {
                        diff = abs(nums[l] + nums[r] -  tar);
                        res = first + nums[l] + nums[r];
                    }
                    ++l;
                }
            }
            if (found) return target;
        }
        
        return res;
    }
};
