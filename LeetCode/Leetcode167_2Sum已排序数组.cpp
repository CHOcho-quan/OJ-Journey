//
//  Leetcode167_2Sum已排序数组.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> search,result;
        int now = 218,a,b;
        for (int i = 0;i < numbers.size();i++)
        {
            if (numbers[i]!=now)
            {
                search.push_back(target-numbers[i]);
                search.push_back(i);
                now = search[search.size()-2];
            }
            for (int j = 0;j < search.size();j+=2)
            {
                if (numbers[i]==search[j] && search[j+1]!=i)
                {
                    a = i;
                    b = search[j+1];
                    result.push_back(b+1);
                    result.push_back(a+1);
                    return result;	
                }
            }
        }  
        return result;
    }
};
