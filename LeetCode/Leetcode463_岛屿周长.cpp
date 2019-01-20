//
//  Leetcode463_岛屿周长.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

int Sum(vector<vector<int> > &grid,int a,int b)
{
    int per = 4;
    if (a > 0 && grid[a-1][b]) per--;
    if (b > 0 && grid[a][b-1]) per--;
    if (a < grid.size()-1 && grid[a+1][b]) per--;
    if (b < grid[0].size()-1 && grid[a][b+1]) per--;
    //cout << per << endl;
    return per;
}

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int a = 101,b = 101,sum = 0;
        for (int i = 0;i < grid.size();i++)
        {
            for (int j = 0;j < grid[0].size();j++)
            {
                if (grid[i][j]==1)
                {
                    a = i;
                    b = j;
                    sum+=Sum(grid,a,b);
                    cout << sum << endl;
                }
            }
        }
        if (a==101) return 0;
        return sum;   
    }
};
