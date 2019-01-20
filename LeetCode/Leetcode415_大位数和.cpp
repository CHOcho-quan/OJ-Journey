//
//  Leetcode415_大位数和.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1,n2,n;
        bool flag = false;
        string result = "";
        while (num1!="" || num2!="")
        {
            if (num1!="")n1 = num1[num1.length()-1] - '0';
            if (num2!="")n2 = num2[num2.length()-1] - '0';
            n = (n1+n2+flag >= 10 ? n1+n2-10+flag : n1 + n2+flag);
            char temp = n+'0';
            result.insert(result.begin(),temp);
            //cout << result <<endl;
            flag = (n1 + n2 + flag >=10);
            if (num1!="")num1.erase(num1.end()-1);
            if (num2!="")num2.erase(num2.end()-1);
            n1 = 0;
            n2 = 0;
        }
        if (flag) result = '1' + result;
        
        return result;  
    }
};
