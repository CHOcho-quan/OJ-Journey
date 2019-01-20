//
//  1235_优先级队列优化Dijkstra算法节点最少最短路径.cpp
//  
//
//  Created by 铨 on 2018/5/26.
//
//

#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

template <class T>
class Node {
public:
    Node *left;
    Node *right;
    T data;
    Node():left(NULL),right(NULL){}
    Node(T datai,Node *lefti = NULL,Node *righti=NULL)
    {
        data = datai;
        left = lefti;
        right = righti;
    }
    ~Node(){}
};

class node {
    friend bool operator< (node n1,node n2) { return n1.weight < n2.weight;}
    friend bool operator> (node n1,node n2) { return n1.weight > n2.weight;}
public:
    int num;
    int weight;
    
    node(int n,int w):num(n),weight(w) {}
    node() {}
};

class priorityQueue {
private:
    int currentSize;
    node *data;
    int maxSize;
    void doubleSpace();
    void buildHeap();
    void percolateUp(int hole);
    void percolateDown(int hole);
    int parent(int x) {return ((x+1)/2-1);}
public:
    priorityQueue(int initSize = 100)
    {
        data = new node[initSize];
        maxSize = initSize;
        currentSize = 0;
    }
    priorityQueue(const node datum[],int size)
    {
        data = new node[2*size];
        currentSize = size;
        maxSize = 2*size;
        for (int i = 0;i < size;i++) data[i] = datum[i];
        buildHeap();
    }
    ~priorityQueue() {delete [] data;}
    void traverse() const {for (int i = 0;i < currentSize;i++) cout << data[i].num << ' ';}
    bool isEmpty() const {return currentSize==0;}
    void enQueue(const node &x);
    node deQueue();
    node getHead() {return data[0];}
};

void priorityQueue::buildHeap()
{
    for (int i = parent(currentSize-1);i >= 0;i--) percolateDown(i);
}

void priorityQueue::doubleSpace()
{
    node *tmp = data;
    data = new node[2*maxSize];
    for (int i = 0;i < currentSize;i++) data[i] = tmp[i];
}

void priorityQueue::percolateUp(int hole)
{
    while (hole!=0)
    {
        if (data[parent(hole)].weight < data[hole].weight) break;
        else
        {
            node tmp = data[parent(hole)];
            data[parent(hole)] = data[hole];
            data[hole] = tmp;
            hole = parent(hole);
        }
    }
}

void priorityQueue::enQueue(const node &x)
{
    if (currentSize == maxSize) doubleSpace();
    data[currentSize] = x;
    currentSize++;
    percolateUp(currentSize-1);
}

void priorityQueue::percolateDown(int hole)
{
    node tmp;
    while (2 * hole + 2 < currentSize)
    {
        if (data[2 * hole + 1].weight <= data[2 * hole + 2].weight && data[2 * hole + 1].weight < data[hole].weight)
        {
            tmp = data[2 * hole + 1];
            data[2 * hole + 1] = data[hole];
            data[hole] = tmp;
            hole = 2 * hole + 1;
            continue;
        }
        if (data[2 * hole + 2].weight < data[2 * hole + 1].weight && data[2 * hole + 2].weight < data[hole].weight)
        {
            tmp = data[2 * hole + 2];
            data[2 * hole + 2] = data[hole];
            data[hole] = tmp;
            hole = 2 * hole + 2;
            continue;
        }
        if (data[2 * hole + 1].weight >= data[hole].weight && data[2 * hole + 2].weight >= data[hole].weight) break;
    }
    if (2 * hole + 2 == currentSize)
    {
        if (data[2 * hole + 1].weight < data[hole].weight)
        {
            tmp = data[2 * hole + 1];
            data[2 * hole + 1] = data[hole];
            data[hole] = tmp;
        }
    }
}

node priorityQueue::deQueue()
{
    node result = data[0];
    data[0] = data[currentSize - 1];
    currentSize--;
    percolateDown(0);
    return result;
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
    
    verNode() {}
    
    verNode(int v,edgeNode *h = NULL) {
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
    void traverse() {
        for (int i = 0; i < Vers; i++) {
            edgeNode *p = verList[i].head;
            cout << verList[i].ver << '\t';
            while (p != NULL) {
                cout << p->end << ' ';
                p = p->next;
            }
            cout << endl;
        }
    }
    
    adjListGraph(int vers) {
        Vers = vers;
        Edges = 0;
        
        verList = new verNode[Vers];
        for (int i = 0;i < vers;i++) verList[i] = i;
    }
    
    void insert(int start,int ending,int weigh) {
        verList[start].head = new edgeNode(weigh,ending,verList[start].head);
        Edges++;
    }
    
    void printPath(int start,int end,int *prev) {
        if (start == end) {
            cout << start+1 << ' ';
            return;
        }
        printPath(start,prev[end],prev);
        cout << end+1 << ' ';
    }
    
    int dijkstra(int start,int end) {
        priority_queue<node,vector<node>,greater<node> > pQ;
        int MAX = 2147483646;
        
        bool *visit;
        visit = new bool[Vers];
        int *distance;
        distance = new int[Vers];
        int *hop;
        hop = new int[Vers];
        int *prev;
        prev = new int[Vers];
        for (int i = 0;i < Vers;i++) {
            visit[i] = false;
            distance[i] = MAX;
            hop[i] = 0;
        }
        
        pQ.push(node(start,0));
        distance[start] = 0;
        prev[start] = start;
        
        while (!pQ.empty()) {
            node tmp = pQ.top();
            pQ.pop();
            if (visit[tmp.num]) continue;
            visit[tmp.num] = true;
            
            //更新S集周边邻接的节点
            edgeNode *p = verList[tmp.num].head;
            while (p != NULL) {
                if (!visit[p->end] && (distance[tmp.num]+p->weight < distance[p->end])
                    || distance[p->end] == distance[tmp.num]+p->weight && hop[p->end] > hop[tmp.num] + 1) {
                    distance[p->end] = distance[tmp.num] + p->weight;
                    pQ.push(node(p->end,distance[p->end]));
                    hop[p->end] = hop[tmp.num] + 1;
                    prev[p->end] = tmp.num;
                }
                p = p->next;
            }
        }
        cout << distance[end] << endl;
        printPath(start,end,prev);
    }
};

int main()
{
    int n,m,start,end;
    int a,b,p;
    cin >> n >> m >> start >> end;
    
    vector<int> result;
    
    adjListGraph alg(n);
    
    for (int i = 0;i < m;i++) {
        cin >> a >> b >> p;
        alg.insert(a-1,b-1,p);
    }
    
    //alg.traverse();
    
    alg.dijkstra(start-1,end-1);
}
