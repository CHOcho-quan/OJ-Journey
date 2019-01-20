//
//  Leetcode18_FourSum.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

vector<vector<int> > threeSum(vector<int>& num,int target1) {
    vector<vector<int> > result;
    if (num.size() < 3) return result;
    sort(num.begin(), num.end());
    
    for (int i = 0; i < num.size(); i++) {
        
        int target = target1-num[i];
        int front = i + 1;
        int back = num.size() - 1;
        
        while (front < back) {
            
            int sum = num[front] + num[back];
            
            // Finding answer which start from number num[i]
            if (sum < target)
                front++;
            
            else if (sum > target)
                back--;
            
            else {
                vector<int> triplet(3, 0);
                triplet[0] = num[i];
                triplet[1] = num[front];
                triplet[2] = num[back];
                result.push_back(triplet);
                
                while (front < back && num[front] == triplet[1]) front++;
                while (front < back && num[back] == triplet[2]) back--;
            }
            
        }
        
        while (i + 1 < num.size() && num[i + 1] == num[i]) i++;
    }
    return result;
}

bool ifSame(vector<vector<int> > a,vector<int> b)
{
    for (int i = 0;i < a.size();i++)
    {
        sort(a[i].begin(),a[i].end());
        sort(b.begin(),b.end());
        if (a[i]==b) return false;
    }
    return true;
}

void Merge(vector<vector<int> > &a1,vector<vector<int> > a2)
{
    for (int i = 0;i < a2.size();i++)
    {
        if (ifSame(a1,a2[i])) a1.push_back(a2[i]);
    }
}

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > result,tmp;
        
        sort(nums.begin(),nums.end());
        for (int i = 0;i < nums.size();i++)
        {
            int temp = nums[i];
            nums.erase(nums.begin());
            
            tmp = threeSum(nums,target - temp);
            for (int u = 0;u < tmp.size();u++) tmp[u].push_back(temp);
            Merge(result,tmp);
            i--;
        }
        
        return result;    
    }
};
