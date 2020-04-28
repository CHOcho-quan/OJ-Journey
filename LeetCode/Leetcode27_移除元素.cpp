#include <string>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() <= 0) return nums.size();
        if (nums.size() == 1) {
            if (nums[0] == val) return 0;
            else return 1;
        }

        int i = 0;
        int j = 0;
        while (j < nums.size())
        {
            while (j < nums.size() && nums[j] == val) j++;
            if (j == nums.size()) break;
            nums[i] = nums[j];
            i++;
            j++;
        }

        return i;
    }
};