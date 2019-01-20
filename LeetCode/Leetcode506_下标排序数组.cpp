//
//  Leetcode506_下标排序数组.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

int GetNum(int n)
{
    int ans = 0;
    while (n!=0)
    {
        n/=10;
        ans++;
    }
    return ans;
}

string Getstring(int n)
{
    int c,t = GetNum(n),i=0;
    //cout << t << endl;
    string result = "";
    char temp;
    for (int j = 0;j < t;j++)
    {
        c = n/pow(10,t-1-i);
        temp = c+'0';
        result+=temp;
        n = n - c*pow(10,t-i-1);
        i++;
    }
    return result;
}

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<string> result;
        vector<int> a = nums;
        int len = nums.size(),now;
        sort(a.begin(),a.end());
        map<int,int> temp;
        for (int i = 0;i < len;i++)
        {
            temp[a[i]] = len-i;
        }
        for (int i = 0;i < len;i++)
        {
            now = temp.find(nums[i])->second;
            switch(now)
            {
                case 1:result.push_back("Gold Medal");break;
                case 2:result.push_back("Silver Medal");break;
                case 3:result.push_back("Bronze Medal");break;
                default:result.push_back(Getstring(now));break;
            }
        }
        return result;        
    }
};
