//
//  Leetcode15_3Sum.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& num) {
        vector<vector<int> > result;
        
        std::sort(num.begin(), num.end());
        
        for (int i = 0; i < num.size(); i++) {
            
            int target = -num[i];
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
};
