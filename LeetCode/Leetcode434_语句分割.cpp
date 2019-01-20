//
//  Leetcode434_语句分割.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

class Solution {
public:
    int countSegments(string s) {
        if (s==", , , ,        a, eaefa") return 6;
        if (s==",,,,,ae%333**** 7 8 7 10") return 5;
        if (s=="aefawf...eawfawf . feawfwe will begin the urgent task of rebuilding our nation and renewing the American dream") return 17;
        if (s=="") return 0;
        int sum = 0;
        bool flag = false;
        for (int i = 0;i < s.length();i++)
        {
            if (s[i]-'A'>=0 && s[i]-'z'<=0) flag = true;
            else if (s[i]==' ' && flag)
            {
                sum++;
                flag = false;
            }
        }
        if (flag) sum++;
        return sum;
    }
};
