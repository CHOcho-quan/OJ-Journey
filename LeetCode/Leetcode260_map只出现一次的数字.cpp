#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>

using namespace std;

vector<int> singleNumber(vector<int>& nums) 
{
    map<int, int> num_mp;
    vector<int> result;

    for (int i = 0;i < nums.size();i++)
    {
        if (num_mp.count(nums[i])) {
            num_mp.erase(nums[i]);
            cout << nums[i] << endl;
        }
        else num_mp[nums[i]] = 1;
    }

    for (auto p = num_mp.begin();p != num_mp.end();p++) result.push_back(p->first);

    return result;
}

int main()
{
    vector<int> nums = {1, 2, 1, 3, 2, 5};
    vector<int> re = singleNumber(nums);
    for (auto p : re)
    {
        cout << p << ' ';
    }
}