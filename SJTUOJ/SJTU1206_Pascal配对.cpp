//
//  SJTU1206_Pascal配对.cpp
//  
//
//  Created by 铨 on 2019/3/6.
//
//

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <stack>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    stack<string> a;
    string tmp;
    bool flag = true;
    
    while (cin >> tmp)
    {
        if (tmp == "if")
        {
            a.push(tmp);
        }
        if (tmp == "then")
        {
            string t = a.top();
            a.push(tmp);
            if (t != "if")
            {
                flag = false;
                cout << "Error!";
                break;
            }
        }
        if (tmp == "else")
        {
            string t1, t2;
            if (!a.empty()){
                t1 = a.top();
                a.pop();
            }
            else {
                flag = false;
                cout << "Error!";
                break;
            }
            
            if (!a.empty()){
                t2 = a.top();
                a.pop();
            }
            else {
                flag = false;
                cout << "Error!";
                break;
            }
            
            if (t2 != "if" || t1 != "then")
            {
                flag = false;
                cout << "Error!";
                break;
            }
        }
        if (tmp == "begin")
        {
            a.push(tmp);
        }
        if (tmp == "end")
        {
            string t3;
            while (!a.empty())
            {
                t3 = a.top();
                a.pop();
                if (t3 == "begin") break;
            }
            if (t3 != "begin") {
                flag = false;
                cout << "Error!";
                break;
            }
        }
    }
    
    if (!a.empty())
    {
        cout << "Error";
        flag = false;
    }
    if (flag){
        cout << "Match!";
    }
}


