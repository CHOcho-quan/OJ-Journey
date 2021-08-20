class Solution {
public:
    vector<int> bubbleSortArray(vector<int>& nums) {
        // Bubble
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 1; j < nums.size(); ++j) {
                if (nums[j] < nums[j-1]) {
                    swap(nums[j], nums[j-1]);
                }
            }
        }
        return nums;
    }
    
    vector<int> selectionSortArray(vector<int>& nums) {
        // Selection Sort
        int check = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] > nums[j]) check = j;
            }
            swap(nums[i], nums[check]);
        }
        return nums;
    }
    
    vector<int> insertionSortArray(vector<int>& nums) {
        // Insertion Sort
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i; j > 0; --j) {
                if (nums[j] < nums[j - 1]) swap(nums[j - 1], nums[j]);
            }
        }
        return nums;
    }
    
    vector<int> quickSortArray(vector<int>& nums, int l, int r) {
        // Quick Sort
        if (l >= r) return nums;
        int pivot = l, key = nums[pivot], st = l, en = r;
        while (st < en) {
            while (st < en && nums[en] >= key) --en;
            nums[st] = nums[en];
            while (st < en && nums[st] <= key) ++st;
            nums[en] = nums[st];
        }
        nums[st] = key;
        quickSortArray(nums, l, en);
        quickSortArray(nums, en + 1, r);
        return nums;
    }
    
    vector<int> mergeSortArray(vector<int>& nums, int l , int r) {
        // Merge Sort
        if (l >= r) return nums;
        
        int mid = l + (r - l) / 2;
        mergeSortArray(nums, l, mid);
        mergeSortArray(nums, mid + 1, r);
        
        vector<int> tmp;
        int c1 = l, c2 = mid + 1;
        while (c1 <= mid && c2 <= r) {
            if (nums[c1] <= nums[c2]) tmp.push_back(nums[c1++]);
            else tmp.push_back(nums[c2++]);
        }
        while (c1 <= mid) tmp.push_back(nums[c1++]);
        while (c2 <= r) tmp.push_back(nums[c2++]);
        for (int i = l; i <= r; ++i) nums[i] = tmp[i - l];
        return nums;
    }
    
    vector<int> sortArray(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        // return bubbleSortArray(nums);
        // return selectionSortArray(nums);
        // return insertionSortArray(nums);
        // return quickSortArray(nums, 0, nums.size() - 1);
        // return mergeSortArray(nums, 0, nums.size() - 1);
        return nums;
    }
};
