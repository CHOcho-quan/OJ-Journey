#include <iostream>
#include <vector>

using namespace std;

bool checkPossibility(vector<int>& nums) {
    int count = 0;
    //int tag = nums[0];
    for(int i = 1; i < nums.size(); i++)
    {
        if(nums[i-1] > nums[i])
        {
            if(i-2 >= 0 && nums[i-2] > nums[i])
                nums[i] = nums[i-1];
            else
                nums[i-1] = nums[i];
            count++;
        }
        if (count > 1) return false;
    }

    return count <= 1;
}