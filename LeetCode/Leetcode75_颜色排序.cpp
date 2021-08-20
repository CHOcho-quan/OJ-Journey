class Solution {
public:
    void quickSort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        
        int st = l, en = r, pivot = nums[l];
        while (st < en) {
            // std::cout << st << ' ' << en;
            while (st < en && nums[en] >= pivot) --en;
            nums[st] = nums[en];
            while (st < en && nums[st] <= pivot) ++st;
            nums[en] = nums[st];
        }
        nums[st] = pivot;
        quickSort(nums, l, st);
        quickSort(nums, st + 1, r);
    }
    
    void sortColors(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        // for (auto& n : nums) {
        //     std::cout << n << ' ';
        // }
    }
};
