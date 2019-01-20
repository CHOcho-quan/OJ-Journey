//
//  1565_Dijkstra辣鸡版可是AC不了这是为什么呢.cpp
//  
//
//  Created by 铨 on 2018/6/5.
//
//

#include <iostream>

using namespace std;

class adjListGraph {
private:
    class edgeNode {
    public:
        int weight;
        int dis;
        int end;
        edgeNode *next;
        
        edgeNode(int e,int w,int d,edgeNode *n = NULL) {
            weight = w;
            dis = d;
            next = n;
            end = e;
        }
    };
    
    class verNode {
    public:
        int ver;
        edgeNode * head;
        
        verNode(int v = 0,edgeNode *n = NULL) {
            v = ver;
            head = n;
        }
    };
    
    int Edges;
    int Vers;
    verNode *verList;
public:
    adjListGraph(int verSize) {
        Vers = verSize;
        Edges = 0;
        verList = new verNode[Vers];
        for (int i = 0;i < Vers;i++) {verList[i].ver = i;verList[i].head = NULL;}
    }
    
    void traverse() {
        for (int i = 0;i < Vers;i++) {
            cout << verList[i].ver << ' ';
            edgeNode *p = verList[i].head;
            while (p != NULL) {
                cout << p->end << ' ';
                p = p->next;
            }
            cout << endl;
        }
    }
    
    void insert(int a,int b,int d,int p) {
        verList[a].head = new edgeNode(b,d,p,verList[a].head);
        verList[b].head = new edgeNode(a,d,p,verList[b].head);
        Edges+=2;
    }
    
    void Dijsktra(int start,int end) {
        int MAX = 2147483647;
        int *distance;
        int *cost;
        bool *visit;
        int u;
        distance = new int[Vers];
        cost = new int[Vers];
        visit = new bool[Vers];
        for (int i = 0;i < Vers;i++) {
            distance[i] = MAX;
            visit[i] = false;
            cost[i] = MAX;
        }
        
        distance[start] = 0;
        cost[start] = 0;
        u = start;
        
        for (int i = 0;i < Vers;i++)
        {
            int min = MAX,minc = MAX;
            for (int j = 0;j < Vers;j++) {
                if (!visit[j] && (distance[j] < min || (distance[j] == min && cost[j] < minc))) {
                    min = distance[j];
                    minc = cost[j];
                    u = j;
                }
            }
            visit[u] = true;
            edgeNode *p = verList[u].head;
            while(p != NULL) {
                if (!visit[p->end] && (distance[p->end] > min + p->weight || (distance[p->end] == min + p->weight && cost[p->end] > minc + p->dis))) {
                    distance[p->end] = min + p->weight;
                    cost[p->end] = minc + p->dis;
                }
                p = p->next;
            }
        }
        
        cout << distance[end] << ' ' << cost[end];
    }
};

int main()
{
    int n,m;
    int a,b,d,p;
    int s,t;
    
    cin >> n >> m;
    adjListGraph alg(n);
    
    for (int i = 0;i < m;i++)
    {
        cin >> a >> b >> d >> p;
        alg.insert(a-1,b-1,d,p);
    }
    
    //alg.traverse();
    
    cin >> s >> t;
    alg.Dijsktra(s-1,t-1);
}
