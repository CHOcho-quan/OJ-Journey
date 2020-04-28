#include <string>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.size()==0) return 1;
        set<int> record;
        for (int i = 0;i < nums.size();i++) {
            record.insert(nums[i]);
        }

        // for (auto iter = record.begin();iter != record.end();iter++) cout << *iter << ' ';

        for (int i = 1;i < record.size()+1;i++) {
            if (!record.count(i)) return i;
        }

        return record.size()+1;
    }
};