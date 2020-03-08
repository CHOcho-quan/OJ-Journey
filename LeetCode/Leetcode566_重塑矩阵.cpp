#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) 
{
    if (nums.size()==0) return nums;
    int total = nums.size() * nums[0].size();
    if (r * c != total) return nums;

    vector<vector<int>> result; 
    vector<int> flatten, tmp;
    for (int i = 0;i < nums.size();i++) for (int j = 0;j < nums[0].size();j++) flatten.push_back(nums[i][j]);

    for (int i = 0;i < r;i++)
    {
        for (int j = 0;j < c;j++)
        {
            tmp.push_back(flatten[i*c+j]);
        }
        result.push_back(tmp);
        tmp.clear();
    }

    return result;
}

int main()
{
    vector<vector<int>> nums = {{1, 2}, {3, 4}}, tmp;
    tmp = matrixReshape(nums, 4, 1);
    cout << tmp.size() << ' ' << tmp[0].size();
}