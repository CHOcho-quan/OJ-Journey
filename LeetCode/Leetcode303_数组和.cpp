//
//  Leetcode303_数组和.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

class NumArray {
private:
    vector<int> accu;
public:
    NumArray(vector<int> nums) {
        accu.push_back(0);
        for (int num : nums)
            accu.push_back(accu.back() + num);
    }
    
    int sumRange(int i, int j) {
        return accu[j + 1] - accu[i];
    }
};
