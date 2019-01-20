//
//  Leetcode119_第n层杨辉三角.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int> > a;
        vector<int> b;
        for (int i = 0;i < rowIndex + 1;i++)
        {
            for (int j = 0;j < i + 1;j++)
            {
                if (j==0||j==i) b.push_back(1);
                else b.push_back(a[i-1][j-1]+a[i-1][j]);
            }
            a.push_back(b);
            b.clear();
        }
        return a[rowIndex];
    }
};
