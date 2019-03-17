//
//  SJTU1028_Pascal语句匹配.cpp
//  
//
//  Created by 铨 on 2019/2/4.
//
//

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <stack>
#include <iomanip>

using namespace std;

int main() {
    int n, begins = 0, ifs = 0, thens = 0;
    string tmp;
    cin >> n;
    stack<string> pascal;
    bool judge = true;
    
    for (int i = 0;i < n;i++)
    {
        cin >> tmp;
        //        cout << tmp << endl;
        
        if (judge){
            if (i==0 && (tmp != "if" && tmp != "begin")) {
                //                cout << 1;
                cout << "NO";
                judge = false;
                continue;
            }
            if (i == 0 && (tmp == "if" || tmp == "begin")) {
                pascal.push(tmp);
                if (tmp == "if") ifs++;
                else begins++;
                //                cout << tmp << endl;
                continue;
            }
            
            string t = "";
            if (!pascal.empty()) {
                t = pascal.top();
            }
            
            if (tmp == "if")
            {
                ifs++;
                if (t == "begin" || t == "else" || t == "then") {
                    pascal.push(tmp);
                    //                    cout << tmp << endl;
                    continue;
                }
                else {
                    //                    cout << 2;
                    cout << "NO";
                    judge = false;
                    continue;
                }
            }
            
            if (tmp == "then")
            {
                ifs--;
                if (t == "if") {
                    pascal.push(tmp);
                    //                    cout << tmp << endl;
                    continue;
                }
                else {
                    //                    cout << 3;
                    cout << "NO";
                    judge = false;
                    continue;
                }
            }
            
            if (tmp == "else")
            {
                if (t == "then") {
                    pascal.push(tmp);
                    //                    cout << tmp << endl;
                    continue;
                }
                else {
                    //                    cout << 4;
                    cout << "NO";
                    judge = false;
                    continue;
                }
            }
            
            if (tmp == "begin")
            {
                begins++;
                if (t == "if") {
                    //                    cout << 5;
                    cout << "NO";
                    judge = false;
                    continue;
                }
                else {
                    pascal.push(tmp);
                    //                    cout << tmp << endl;
                }
            }
            
            if (tmp == "end")
            {
                begins--;
                while (t != "begin")
                {
                    if (!pascal.empty()) {
                        pascal.pop();
                        if (!pascal.empty()) t = pascal.top();
                    }
                    else {
                        //                        cout << 6;
                        cout << "NO";
                        judge = false;
                        break;
                    }
                }
                if (!pascal.empty()) pascal.pop();
            }
        }
    }
    
    if (judge){
        if (begins > 0 || ifs > 0 || thens > 0) {
            cout << "NO";
            judge = false;
        }
    }
    if (judge) cout << "YES";
}
