//
//  POJ2135_超时的MCMF呵呵哒.cpp
//  
//
//  Created by 铨 on 2018/11/5.
//
//

#include <iostream>
#include <queue>

using namespace std;

int pre[2010];
int dist[2010];

class edgeNode {
public:
    int weight;
    int end;
    int flow;
    edgeNode *next;
    
    edgeNode(int w, int e, int f, edgeNode *n = NULL) {
        weight = w;
        end = e;
        flow = f;
        next = n;
    }
};

class verNode {
public:
    edgeNode *head;
    int num;
    
    verNode(int v = 0, edgeNode *h = NULL) {
        head = h;
        num = v;
    }
};

class adjGraph
{
public:
    int Ver;
    int Edges;
    verNode *verlist;
    adjGraph(int ver)
    {
        Ver = ver;
        Edges = 0;
        
        verlist = new verNode[Ver];
        for (int i = 0;i < Ver;i++) verlist[i].num = i;
    }
    
    edgeNode * getEdge(int start, int end)
    {
        for (edgeNode *s = verlist[start].head;s != NULL;s = s->next) {
            if (s->end == end) return s;
        }
    }
    
    void addEdge(int f, int w, int u, int v) {
        verlist[u].head = new edgeNode(w, v, f, verlist[u].head);
        Edges++;
    }
    
    void traverse()
    {
        for (int i = 0;i < Ver;i++)
        {
            cout << verlist[i].num << ' ';
            for (edgeNode *h = verlist[i].head;h != NULL;h = h->next) {
                cout << h->end << ' ';
            }
            cout << endl;
        }
    }
    
    bool spfa()
    {
        queue<int> queue1;
        bool *inqueue;
        inqueue = new bool[Ver];
        for (int i = 0;i < Ver;i++) {
            pre[i] = -1;
            dist[i] = 2147483647;
            inqueue[i] = false;
        }
        
        queue1.push(0);
        dist[0] = 0;
        inqueue[0] = true;
        while (not queue1.empty())
        {
            int now = queue1.front();
            queue1.pop();
            inqueue[now] = false;
            
            for (edgeNode *h = verlist[now].head;h != NULL;h = h->next) {
                if (h->flow != 0 && dist[h->end] > dist[now] + h->weight)
                {
                    if (!inqueue[h->end]) {
                        queue1.push(h->end);
                        inqueue[h->end] = true;
                    }
                    dist[h->end] = dist[now] + h->weight;
                    pre[h->end] = now;
                    edgeNode *past = verlist[h->end].head;
                }
            }
            
            //            for (int i = 0;i < Ver;i++) cout << dist[i] << ' ';
            //            cout << endl;
        }
        
        return pre[Ver-1] != -1;
    }
};

int main()
{
    int M, N, u, v, w;
    cin >> N >> M;
    
    adjGraph graph = adjGraph(N+2);
    for (int i = 0;i < M;i++)
    {
        cin >> u >> v >> w;
        graph.addEdge(1, w, u, v);
        graph.addEdge(1, w, v, u);
        graph.addEdge(0, -w, v, u);
        graph.addEdge(0, -w, u, v);
    }
    graph.addEdge(2, 0, 0, 1);
    graph.addEdge(2, 0, N, N+1);
    
    int result = 0;
    while (graph.spfa())
    {
        int now = N+1;
        int last=pre[now];
        
        while (now!=0)
        {
            //            cout << last << ' ' << now << endl;
            for (edgeNode *h = graph.verlist[last].head;h != NULL;h = h->next) {
                if (h->end == now) {
                    if (h->flow == 0) continue;
                    h->flow--;
                    break;
                }
            }
            
            for (edgeNode *h = graph.verlist[now].head;h != NULL;h = h->next) {
                if (h->end == last) {
                    if (h->flow == 1) continue;
                    h->flow++;
                    break;
                }
            }
            
            now = last;
            last = pre[now];
        }
        result+=dist[N+1];//累计花费
    }
    cout << result << endl;
}

