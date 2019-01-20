//
//  1337_最小生成树与女友的分手.cpp
//  
//
//  Created by 铨 on 2018/6/7.
//
//

#include <iostream>

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
    bool allUnion();
    int Find(int x);
};

bool DisjointSet::allUnion()
{
    int t = Find(0);
    for (int i = 0;i < size;i++) {
        if (Find(i) == t) continue;
        else return false;
    }
    return true;
}

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

class WeightNode {
public:
    int weight;
    int ver1;
    int ver2;
    
    WeightNode(int w,int v1,int v2) {
        weight = w;
        ver1 = v1;
        ver2 = v2;
    }
    WeightNode() {}
};

int divide(WeightNode * n,int low,int high) {
    WeightNode k = n[low];
    
    while (low != high) {
        while (low < high && n[high].weight >= k.weight) --high;
        if (low < high) {n[low] = n[high];++low;}
        while (low < high && n[low].weight <= k.weight) ++low;
        if (low < high) {n[high] = n[low];--high;}
    }
    
    n[low] = k;
    return low;
}

void QuickSort(WeightNode * n,int low,int high) {
    int mid;
    if (low >= high) return;
    
    mid = divide(n,low,high);
    QuickSort(n,low,mid-1);
    QuickSort(n,mid+1,high);
}

class adjListGraph {
private:
    class edgeNode {
    public:
        int end;
        int weight;
        edgeNode *next;
        
        edgeNode(int e, int w, edgeNode *n = NULL) {
            end = e;
            weight = w;
            next = n;
        }
    };
    
    class verNode {
    public:
        int ver;
        edgeNode *head;
        
        verNode(int v = 0, edgeNode *h = NULL) {
            ver = v;
            head = h;
        }
    };
    
    int Vers;
    int Edges;
    verNode *verList;
public:
    adjListGraph(int n) {
        Vers = n;
        Edges = 0;
        verList = new verNode[Vers];
        
        for (int i = 0; i < Vers; i++) {
            verList[i].ver = i;
        }
    }
    
    void insert(int s, int e, int w) {
        verList[s].head = new edgeNode(e, w, verList[s].head);
        verList[e].head = new edgeNode(s, w, verList[e].head);
        Edges++;
    }
    
    void traverse() {
        for (int i = 0; i < Vers; i++) {
            cout << verList[i].ver << ' ';
            for (edgeNode *p = verList[i].head; p != NULL; p = p->next) {
                cout << p->end << ' ';
            }
            cout << endl;
        }
    }
    
    void social(WeightNode *ti,int size) {
        DisjointSet djs(size);
        int result = 0;
        
        for (int i = 0;i < size;i++) {
            if (djs.Find(ti[i].ver1) != djs.Find(ti[i].ver2)) {
                result+=ti[i].weight;
                djs.Union(djs.Find(ti[i].ver2),djs.Find(ti[i].ver1));
            }
            
            if (djs.allUnion()) break;
        }
        
        cout << result;
    }
};

int main()
{
    int n,m,x,y,w;
    cin >> n >> m;
    WeightNode *ti;
    adjListGraph alg(n+1);
    ti = new WeightNode[n+m];
    for (int i = 0;i < n;i++) {
        cin >> x;
        alg.insert(0,i+1,x);
        ti[i] = WeightNode(x,0,i+1);
    }
    
    for (int i = 0;i < m;i++) {
        cin >> x >> y >> w;
        alg.insert(x,y,w);
        ti[i+n] = WeightNode(w,x,y);
    }
    //alg.traverse();
    QuickSort(ti,0,n+m-1);
    alg.social(ti,n+m);
}
