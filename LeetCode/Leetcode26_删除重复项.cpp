#include <string>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int last = nums[0];
        for (int i = 1;i < nums.size();i++)
        {
            if (nums[i] == last) {
                nums.erase(nums.begin()+i);
                i--;
                continue;
            }
            last = nums[i];
        }

        return nums.size();
    }
};