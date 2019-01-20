//
//  1232_并查集生成迷宫并记录路径.cpp
//  
//
//  Created by 铨 on 2018/5/18.
//
//

#include <iostream>
#include <cmath>
#include <stack>
#include <vector>

using namespace std;

class DisjointSet {
private:
    int size;
    int *parent;
public:
    DisjointSet(int s)
    {
        size = s;
        parent = new int [s];
        for (int i = 0;i < s;++i) parent[i] = -1;
    }
    ~DisjointSet() {delete []parent;}
    void Union(int root1,int root2);
    int Find(int x);
};

int DisjointSet::Find(int x)
{
    int k,j,r;
    r = x;
    while (parent[r] >= 0) r = parent[r];
    
    k = x;
    while (k != r)
    {
        j = parent[k];
        parent[k] = r;
        k = j;
    }
    
    return r;
}

void DisjointSet::Union(int root1, int root2)
{
    if (root1 == root2) return ;
    if (parent[root1] > parent[root2])
    {
        parent[root2] += parent[root1];
        parent[root1] = root2;
    }
    else
    {
        parent[root1] += parent[root2];
        parent[root2] = root1;
    }
}

int line(int n) //where is n
{
    int result = 0;
    while (1)
    {
        if (n <= result*(result+1)/2) return result;
        else result++;
    }
}

vector<int> result;

bool DFS(vector<vector<int> > s,int start,int end,int n1)
{
    vector<int> tmp;
    int a = line(start);
    
    if (line(start - a) == a-1 && a-1>0) tmp.push_back(start-a);
    else tmp.push_back(-1);
    if (line(start - a + 1) == a-1 && a-1>0) tmp.push_back(start-a+1);
    else tmp.push_back(-1);
    if (line(start + a) == a+1 && a+1<=n1) tmp.push_back(start+a);
    else tmp.push_back(-1);
    if (line(start + a + 1) == a+1 && a+1<=n1) tmp.push_back(start+a+1);
    else tmp.push_back(-1);
    
    //    for (int i = 0;i < s.size();i++)
    //    {
    //        for (int j = 0;j < s.size();j++) cout << s[i][j] << ' ';
    //        cout << endl;
    //    }
    //    cout << endl;
    
    if (tmp[0] == end || tmp[1] == end || tmp[2] == end || tmp[3] == end)
        return false;
    
    for (int i = 0;i < 4;i++)
    {
        if (tmp[i] != -1 && (s[start-1][tmp[i]-1] == -1 || s[start-1][tmp[i]-1] == -2)) continue;
        if (tmp[i] != -1 && s[start-1][tmp[i]-1] == 1)
        {
            s[start-1][tmp[i]-1] = -2;
            s[tmp[i]-1][start-1] = -2;
            if (!DFS(s,tmp[i],end,n1))
            {
                //cout << 'a' << endl;
                result.push_back(tmp[i]);
                return false;
            }
            else continue;
        }
    }
    return true;
}

int main() {
    int n1,n2,n3,t1,t2;
    cin >> n1 >> n2 >> n3;
    DisjointSet test(n1*(n1+1)/2);
    vector<vector<int> > s;
    vector<int> tmp;
    result.push_back(n2);
    
    for (int i = 0;i < n1*(n1+1)/2;i++)
    {
        for (int j = 0;j < n1*(n1+1)/2;j++)
        {
            tmp.push_back(-1);
        }
        s.push_back(tmp);
        tmp.clear();
    }
    
    while (1)
    {
        //create a maze
        cin >> t1 >> t2;
        int tmp = line(t1);
        switch(t2)
        {
            case 0:{
                if (line(t1-tmp) == tmp - 1 && tmp-1 > 0)
                {
                    test.Union(test.Find(t1),test.Find(t1-tmp));
                    s[t1-1][t1-tmp-1] = 1;
                    s[t1-tmp-1][t1-1] = 1;
                }
                break;
            }
            case 1:{
                if (line(t1-tmp+1) == tmp - 1 && tmp-1 > 0)
                {
                    test.Union(test.Find(t1),test.Find(t1-tmp+1));
                    s[t1-1][t1-tmp] = 1;
                    s[t1-tmp][t1-1] = 1;
                }
                break;
            }
            case 2:{
                if (line(t1+tmp) == tmp + 1 && tmp+1 <= n1)
                {
                    test.Union(test.Find(t1),test.Find(t1+tmp));
                    s[t1-1][t1+tmp-1] = 1;
                    s[t1+tmp-1][t1-1] = 1;
                }
                break;
            }
            case 3:{
                if (line(t1+tmp+1) == tmp + 1 && tmp+1 <= n1)
                {
                    test.Union(test.Find(t1),test.Find(t1+tmp+1));
                    s[t1-1][t1+tmp] = 1;
                    s[t1+tmp][t1-1] = 1;
                }
                break;
            }
        }
        
        //find a path
        if (test.Find(n2) == test.Find(n3))
        {
            DFS(s,n3,n2,n1);
            break;
        }
    }
    result.push_back(n3);
    for (int i = 0;i < result.size();i++) cout << result[i] << ' ';
}

