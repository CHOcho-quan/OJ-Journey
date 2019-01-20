//
//  Leetcode28_strStr.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.length(),len2 = needle.length();
        if (needle=="") return 0;
        for (int i = 0;i < len1;i++)
        {
            if (i > len1 - len2) return -1;
            if (haystack.substr(i,len2)==needle) return i;
        }    
        return -1;
    }
};
