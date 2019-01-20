//
//  SJTU1019_小括号匹配.cpp
//  
//
//  Created by 铨 on 2019/1/18.
//
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    int n;
    string tmp;
    cin >> n;
    
    for (int j = 0;j < n;j++){
        cin >> tmp;
        stack<char> a;
        a.push(tmp[0]);
        if (tmp[0]==')') {
            cout << "NO" << endl;
            continue;
        }
        
        bool flag = false;
        for (int i = 1;i < tmp.length();i++)
        {
            if (tmp[i] == '(') a.push(tmp[i]);
            if (tmp[i] == ')')
            {
                if (a.empty()) {
                    cout << "NO" << endl;
                    //                    cout << 2;
                    flag = true;
                    break;
                }
                else {
                    a.pop();
                }
            }
        }
        
        if (!a.empty()) {
            cout << "NO" <<endl;
            //            cout << 1;
            continue;
        }
        if (flag) {
            flag = false;
            continue;
        }
        else cout << "YES" <<endl;
    }
}
