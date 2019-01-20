//
//  Leetcode400_第n个数字.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

int LengthofNumber(int n)
{
    int sum = 0,i = 1,c = n;
    while (c!=0)
    {
        //cout << c <<endl;
        c = c/10;
        i++;
        sum++;
    }
    return sum;
}

string NumToString(int n)
{
    int c = LengthofNumber(n);
    //cout << c;
    int d = n,f = c;
    string s = "";
    for (int i = 0;i < f;i++)
    {
        int t=d/pow(10,c-1);
        //cout << t << endl;
        d = d - t*pow(10,c-1);
        c--;
        char y = t +'0';
        s+=y;
    }
    return s;
}

class Solution {
public:
    int findNthDigit(int n) {
        int array[9] = {0,9,189,2889,38889,488889,5888889,68888889,788888889};
        int u = -1;
        for (int i = 0;i < 9;i++)
        {
            if (n <= array[i])
            {
                u = i;
                break;
            }
        }
        if (u==-1) u = 9;
        cout << "Type2;"<<endl;
        cout << u << endl;
        string s = "";
        int c = (n - array[u-1] - 1)/u,d = (n-array[u-1])%u;
        cout << "d:" << d << endl;
        //cout << c << endl;
        int a = pow(10,u-1)+c;
        cout << a << endl;
        s+=NumToString(a);
        if (d==0) return s[u-1-d] -'0';
        else
        {
            return s[d-1]-'0';
        }
    }
};
