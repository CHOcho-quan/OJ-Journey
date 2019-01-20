//
//  SJTU1025_最长非重叠区间水枪灭火.cpp
//  
//
//  Created by 铨 on 2019/1/19.
//
//

#include <iostream>
#include <set>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int s, e;
    vector<int> a;
    for (int i = 0;i < n;i++)
    {
        cin >> s >> e;
        long tmp = a.size();
        for (int j = 0;j < tmp;j+=2)
        {
            if (s > a[j])
            {
                if (a[j+1] < s)
                {
                    if (j == tmp - 2) {
                        a.push_back(s);
                        a.push_back(e);
                    }
                }
                else{
                    if (a[j+1] < e) a[j+1] = e;
                }
            }
            else {
                if (e < a[j]) {
                    if (j == tmp - 2) {
                        a.push_back(s);
                        a.push_back(e);
                    }
                }
                else {
                    if (a[j+1] < e) {
                        a[j] = s;
                        a[j+1] = e;
                    }
                    else {
                        a[j] = s;
                    }
                }
            }
        }
        
        if (i==0){
            a.push_back(s);
            a.push_back(e);
        }
    }
    
    int sum = 0;
    set<int> temp(a.begin(), a.end());
    a.assign(temp.begin(), temp.end());
    vector<int>::iterator it;
    //    for (it = a.begin(); it != a.end(); it++) cout << *it <<endl;
    for (int i = 0;i < a.size();i+=2)
    {
        //        cout << a[i] << ' ' << a[i+1] << endl;
        sum += a[i+1] - a[i];
    }
    cout << sum;
}
