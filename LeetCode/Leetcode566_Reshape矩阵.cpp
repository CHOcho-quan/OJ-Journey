//
//  Leetcode566_Reshape矩阵.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int index = 0;
        vector<vector<int> > result;
        vector<int> temp,temp2;
        if (r*c!=nums.size()*nums[0].size())
        {
            cout << "输入的行列数不合法！" << endl;
            return nums;
        }
        else
        {
            for (int i = 0;i < nums.size();i++) {for (int j = 0;j < nums[0].size();j++) temp.push_back(nums[i][j]);}
            for (int u = 0;u < r;u++)
            {
                for (int o = 0;o < c;o++)
                {
                    temp2.push_back(temp[index]);
                    index++;
                }
                result.push_back(temp2);
                temp2.clear();
            }
        }
        return result;
    }
};
