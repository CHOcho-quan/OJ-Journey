//
//  Leetcode5381C_查询带键排列.cpp
//  
//
//  Created by 铨 on 2020/4/12.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> processQueries(vector<int>& queries, int m) {
    map<int, int> mapping;
    vector<int> result;
    for (int i = 0;i < m;i++) mapping[i+1] = i;
    
    for (int i = 0;i < queries.size();i++)
    {
        result.push_back(mapping[queries[i]]);
        
        for (auto it = mapping.begin();it != mapping.end();it++) {
            if (it->second < mapping[queries[i]]) mapping[it->first] += 1;
        }
        
        mapping[queries[i]] = 0;
    }
    
    return result;
}
