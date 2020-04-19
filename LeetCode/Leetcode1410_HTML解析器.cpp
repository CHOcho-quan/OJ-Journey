//
//  Leetcode5382C_HTML解析器.cpp
//  
//
//  Created by 铨 on 2020/4/12.
//

#include <stdio.h>
#include <iostream>
#include <map>
#include <string>

using namespace std;

string entityParser(string text) {
    string result = "";
    map<string, string> mapping;
    mapping["&quot;"] = "\"";
    mapping["&apos;"] = "\'";
    mapping["&amp;"] = "&";
    mapping["&gt;"] = ">";
    mapping["&lt;"] = "<";
    mapping["&frasl;"] = "/";
    
    for (int i = 0;i < text.length();i++) {
        if (text[i] != '&') result += text[i];
        else{
            bool flag = false;
            if (!flag && i+6 <= text.length() && mapping.count(text.substr(i, 6))) {
                result += mapping[text.substr(i, 6)];
                i+=5;
                flag = true;
            }
            if (!flag && i+5 <= text.length() && mapping.count(text.substr(i, 5))) {
                result += "&";
                i+=4;
                flag = true;
            }
            if (!flag && i+4 <= text.length() && mapping.count(text.substr(i, 4))) {
                result += mapping[text.substr(i, 4)];
                i+=3;
                flag = true;
            }
            if (!flag && i+7 <= text.length() && mapping.count(text.substr(i, 7))) {
                result += "/";
                i+=6;
                flag = true;
            }
            if (!flag) result += text[i];
        }
    }
    
    return result;
}
