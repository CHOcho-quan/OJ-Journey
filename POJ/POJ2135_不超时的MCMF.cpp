#include<iostream>
#include<queue>
using namespace std;


const int inf = 2147483647;
const int MAXN = 2010;
const int MAXM = 40010;

struct Node
{
    int s;
    int to;
    int next;
    int capacity;
    int value;
};

int n, m;
int index;
Node node[MAXM];
int ind[MAXN];
int pre[MAXN];
int distant[MAXN];
bool visited[MAXN];

void addedge(int a, int b, int v, int c)
{
    node[index].to = b;
    node[index].s = a;
    node[index].value = v;
    node[index].capacity = c;
    node[index].next = ind[a];
    ind[a] = index++;
    
    node[index].to = a;
    node[index].s = b;
    node[index].value = -v;
    node[index].capacity = 0;
    node[index].next = ind[b];
    ind[b] = index++;
}

bool spfa(int s, int t, int nnum)
{
    for (int i = 0; i <= nnum; i++)
    {
        visited[i] = 0;
        distant[i] = inf;
        pre[i] = -1;
    }
    queue<int> que;
    que.push(s);
    distant[s] = 0;
    visited[s] = true;
    while (!que.empty())
    {
        int temp = que.front();
        que.pop();
        visited[temp] = false;
        for (int i = ind[temp]; i != -1; i = node[i].next)
        {
            if (node[i].capacity)
            {
                int des = node[i].to;
                if (distant[temp] + node[i].value < distant[des])
                {
                    if (!visited[des])
                    {
                        visited[des] = true;
                        que.push(des);
                    }
                    distant[des] = distant[temp] + node[i].value;
                    pre[des] = i;
                }
            }
        }
    }
    if (distant[t] == inf)
        return false;
    return true;
}

int main()
{
    int a, b, v;
    int s, t, result;
    cin >> n >> m;
    
    index = 0;
    for (int i = 0;i < MAXN;i++) ind[i] = -1;
    //for (int i = 0;i < MAXM;i++) node[i] = 0;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> v;
        addedge(a, b, v, 1);
        addedge(b, a, v, 1);
    }
    s = n + 1;
    t = s + 1;
    int nnum = t;
    addedge(s, 1, 0, 2);
    addedge(n, t, 0, 2);
    int ans_flow = 0;
    int ans_cost = 0;
    int temp, minc;
    while (spfa(s, t, nnum))
    {
        temp = t;
        minc = inf;
        while (pre[temp] != -1)
        {
            minc = min(node[pre[temp]].capacity, minc);
            temp = node[pre[temp]].s;
        }
        temp = t;
        while (pre[temp] != -1)
        {
            node[pre[temp]].capacity -= minc;
            int ss = pre[temp] ^ 1;
            node[ss].capacity += minc;
            temp = node[pre[temp]].s;
        }
        ans_cost += distant[t] * minc;
    }
    cout << ans_cost << endl;
    
    return 0;
}
