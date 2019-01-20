//
//  1234_并查集+快排完成Kruskal算法最小生成树.cpp
//  
//
//  Created by 铨 on 2018/5/25.
//
//

#include <iostream>
#include <cmath>

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

class edgeNode {
public:
    int weight;
    int end;
    edgeNode *next;
    
    edgeNode(int w,int e,edgeNode *n = NULL) {
        weight = w;
        end = e;
        next = n;
    }
};

class verNode {
public:
    int ver;
    edgeNode *head;
    
    verNode(int v = -1,edgeNode *h = NULL) {
        ver = v;
        head = h;
    }
};

class adjListGraph {
private:
    int Edges;
    int Vers;
    verNode *verList;
public:
    adjListGraph(int vers) {
        Vers = vers;
        Edges = 0;
        
        verList = new verNode[vers];
        for (int i = 0;i < vers;i++) verList[i] = i;
    }
    bool insert(int start,int end,int weight) {
        verList[start].head = new edgeNode(weight,end,verList[start].head);
        Edges++;
    }
};

class WeightNode {
public:
    int weight;
    int ver1;
    int ver2;
    
    WeightNode(int a,int b,int p) {
        ver1 = a;
        ver2 = b;
        weight = p;
    }
    WeightNode() {}
};

int divide(WeightNode *n,int low,int high) {
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

void QuickSort(WeightNode *n,int low,int high) {
    int mid;
    if (low >= high) return;
    
    mid = divide(n,low,high);
    QuickSort(n,low,mid-1);
    QuickSort(n,mid+1,high);
}

int main()
{
    int n,m;
    int a,b,p;
    int result = 0;
    WeightNode *weight;
    cin >> n >> m;
    weight = new WeightNode[m];
    
    DisjointSet connected(n);
    
    for (int i = 0;i < m;i++) {
        cin >> a >> b >> p;
        WeightNode tmp(a-1,b-1,p);
        weight[i] = tmp;
    }
    
    QuickSort(weight,0,m-1);
    
    //    for (int i = 0;i < m;i++) cout << "ver1: " << weight[i].ver1 << "ver2: " << weight[i].ver2 << "weight: " << weight[i].weight << endl;
    //    cout << endl;
    
    for (int i = 0;i < m;i++) {
        if (connected.Find(weight[i].ver1) != connected.Find(weight[i].ver2))
        {
            result+=weight[i].weight;
            //cout << result << ' ';
            connected.Union(connected.Find(weight[i].ver1),connected.Find(weight[i].ver2));
        }
    }
    //cout << endl;
    cout << result;
}
