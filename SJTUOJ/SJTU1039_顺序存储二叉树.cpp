//
//  SJTU1039_顺序存储二叉树.cpp
//  
//
//  Created by 铨 on 2019/3/31.
//
//

#include <iostream>
#include <iomanip>
#include <queue>
#include <stack>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int t, l, r;
    int tree[50000];
    int *c;
    c = new int[n+1];
    c[1] = 1;
    for (int &i : tree) i = -1;
    tree[1] = 1;
    for (int i = 0;i < n;i++)
    {
        cin >> t >> l >> r;
        if (l!=-1){
            int tmp = 2 * c[t];
            c[l] = tmp;
            tree[tmp] = l;
        }
        else {
            int tmp = 2 * c[t];
            if (tmp < 50000) tree[tmp] = -1;
        }
        if (r!=-1) {
            int tmp = 2 * c[t] + 1;
            c[r] = tmp;
            tree[tmp] = r;
        }
        else {
            int tmp = 2 * c[t] + 1;
            if (tmp < 50000) tree[tmp] = -1;
        }
    }
    
    for (int i = 1;i < n+1;i++) cout << c[i] << ' ';
    cout << endl;
    
    stack<int> st;
    st.push(1);
    
    while (!st.empty())
    {
        bool flag = false;
        int now = st.top();
        int index = c[now];
        if (2*index+1 < 50000 && tree[2*index+1]!=-1) {
            st.push(tree[2*index+1]);
            flag = true;
        }
        if (2 * index < 50000 && tree[2*index]!=-1) {
            st.push(tree[2*index]);
            flag = true;
        }
        if (!flag) {
            cout << now << ' ';
            tree[index] = -1;
            st.pop();
        }
    }
}
