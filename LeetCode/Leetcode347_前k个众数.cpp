//
//  Leetcode347_前k个众数.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

typedef pair<int,int> PAIR;

bool Comp(const PAIR &x,const PAIR &y)
{
    return x.second > y.second;
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        map<int,int> map_r;
        vector<PAIR> pair_vec;
        
        for (int i = 0;i < nums.size();i++)
        {
            map_r[nums[i]]++;
            //sort(map_r.begin(),map_r.end(),Comp);
        }
        
        //	for (map<int, int>::iterator map_iter = map_r.begin(); map_iter != map_r.end(); ++map_iter)
        //	{
        //		cout << map_iter->first << endl;
        //	}
        //
        for (map<int, int>::iterator map_iter = map_r.begin(); map_iter != map_r.end(); ++map_iter)
        {
            pair_vec.push_back(make_pair(map_iter->first, map_iter->second));
        }
        
        sort(pair_vec.begin(),pair_vec.end(),Comp);
        
        for (vector<PAIR>::iterator it = pair_vec.begin();it!=pair_vec.begin()+k;it++)
        {
            result.push_back(it->first);
        }
        
        return result;    
    }
};
