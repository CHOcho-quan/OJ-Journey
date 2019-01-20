//
//  1205_Ackerman.cpp
//  
//
//  Created by 铨 on 2018/7/26.
//
//

#include <iostream>
#include <stack>
using namespace std;
class Node
{
public:
    int m;
    int n;
    Node(int a,int b):m(a),n(b){}
    Node(const Node &x)
    {
        m = x.m;
        n = x.n;
    }
};
int Ack(int m,int n)
{
    if (m==0) return n+1;
    else if (n==0) return Ack(m-1,1);
    else return Ack(m-1,Ack(m,n-1));
}
int Ack1(int a,int b)
{
    Node n(a,b);
    stack<Node> s;
    s.push(n);
    while (!s.empty())
    {
        Node c = s.top();
        s.pop();
        if (c.m == 0)
        {
            if (s.empty()) return c.n+1;
            else
            {
                Node u =s.top();
                s.pop();
                u.n = c.n+1;
                s.push(u);
            }
            continue;
        }
        if (c.n==0)
        {
            Node u(c.m-1,1);
            s.push(u);
            continue;
        }
        else
        {
            Node e(c.m-1,-1);
            Node u(c.m,c.n-1);
            s.push(e);
            s.push(u);
            continue;
        }
        
    }
}
int main()
{
    int a,b;
    cin >> a >> b;
    cout << Ack1(a,b);
}
