#include <iostream>
#include <vector>

using namespace std;

int search(vector<int> &nums, int low, int high)
{
    if (low > high) return -1;
    int mid = (low + high) / 2;
    if (mid != 0 and mid != nums.size()-1) 
    {
        if (nums[mid] > nums[mid+1] and nums[mid] > nums[mid-1]) return mid;
        else
        {
            if (nums[mid] > nums[mid+1]) return search(nums, low, mid);
            else return search(nums, mid+1, high);
        }
    }
    else 
    {
        if (mid == 0 and nums[mid] > nums[1]) return 0;
        if (mid == nums.size()-1 and nums[mid] > nums[mid-1]) return mid;
    }

    return -1;
}
int findPeakElementBinary(vector<int>& nums) {
    if (nums.size()==1) return 0;
    if (nums.size()==2) {
        if (nums[1] > nums[0]) return 1;
        else return 0;
    }
    return search(nums, 0, nums.size()-1);
}

int findPeakElement(vector<int>& nums) {
    bool flag = true;
    if (nums.size() == 1) return 0;
    for (int i = 0;i < nums.size();i++)
    {
        if (i == nums.size()-1 and nums[i] > nums[i-1]) return nums.size()-1;
        if (flag)
        {
            if (nums[i] > nums[i+1]) return i;
            else flag = true;
        }
        else 
        {
            if (nums[i] < nums[i+1]) flag = true;
            else flag = false;
        }
    }

    return -1;
}

int main()
{
    vector<int> nums = {1,2,3,1};
    cout << findPeakElementBinary(nums);
}