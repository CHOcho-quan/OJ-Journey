//
//  Leetcode5380C_字符串数组子串匹配.cpp
//  
//
//  Created by 铨 on 2020/4/12.
//

#include <stdio.h>
#include <set>
#include <vector>
#include <string>

using namespace std;

vector<string> stringMatching(vector<string>& words) {
    set<string> result;
    for (int i = 0;i < words.size();i++) {
        for (int j = i+1;j < words.size();j++) {
            int word_size = min(words[i].size(), words[j].size());
            int word_ind1 = words[i].size() > words[j].size() ? i : j;
            int word_ind2 = i + j - word_ind1;
            for (int k = 0;k < words[word_ind1].size() - word_size + 1;k++) {
                //                cout << words[word_ind1].substr(k, word_size) << endl;
                if (words[word_ind1].substr(k, word_size) == words[word_ind2]) {
                    result.insert(words[word_ind2]);
                    break;
                }
            }
        }
    }
    vector<string> vec;
    vec.assign(result.begin(), result.end());
    
    return vec;
}
