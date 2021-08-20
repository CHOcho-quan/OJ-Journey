class Solution {
public:
    int quickSelect(vector<int>& nums, int l, int r, int k) {
        if (l >= r) return nums[l];
        
        int pivot = nums[l], st = l, en = r;
        while (st < en) {
            while (st < en && nums[en] <= pivot) --en;
            nums[st] = nums[en];
            while (st < en && nums[st] >= pivot) ++st;
            nums[en] = nums[st];
        }
        nums[st] = pivot;
        if (st == k - 1) return pivot;
        else if (st > k - 1) return quickSelect(nums, l, st, k);
        return quickSelect(nums, st + 1, r, k);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int ans = quickSelect(nums, 0, nums.size() - 1, k);
        return ans;
    }
};
