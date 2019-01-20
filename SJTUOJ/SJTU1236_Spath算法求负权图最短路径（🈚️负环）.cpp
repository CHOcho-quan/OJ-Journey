//
//  1236_Spath算法求负权图最短路径（🈚️负环）.cpp
//  
//
//  Created by 铨 on 2018/5/26.
//
//

#include <iostream>
using namespace std;

template <class T>
class Queue
{
private:
    T *data;
    int count;
    int maxsize;
    void doublespace();
public:
    Queue(int initSize = 10);
    void push(const T &x);
    int size();
    T front() const;
    T back() const;
    T pop();
    bool isEmpty()const;
    void traverse() const;
    ~Queue() {delete []data;}
};

template <class T>
Queue<T>::Queue(int initSize)
{
    data = new T[initSize];
    count = -1;
    maxsize = initSize;
}

template <class T>
T Queue<T>::front() const
{
    return data[0];
}

template <class T>
T Queue<T>::back() const
{
    return data[count];
}

template <class T>
bool Queue<T>::isEmpty()const
{
    return (count==-1);
}

template <class T>
T Queue<T>::pop()
{
    T tmp = data[0];
    for (int i = 1;i < count+1;i++) data[i-1] = data[i];
    count--;
    return tmp;
}

template <class T>
void Queue<T>::push(const T &x)
{
    if (count>=maxsize-1) doublespace();
    data[++count] = x;
}

template <class T>
int Queue<T>::size()
{
    return (count+1);
}

template <class T>
void Queue<T>::traverse() const
{
    for (int i = 0;i < count+1;i++) cout << data[i] << ' ';
    cout << endl;
}

template <class T>
void Queue<T>::doublespace()
{
    T *tmp = data;
    data = new T[2*maxsize];
    for (int i = 0;i < count+1;i++) data[i] = tmp[i];
    delete tmp;
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
    
    verNode(int v = 0,edgeNode *h = NULL) {
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
    adjListGraph(int v) {
        Vers = v;
        Edges = 0;
        verList = new verNode[v];
        
        for (int i = 0;i < v;i++) verList[i] = i;
    }
    
    void insert(int start,int ending,int weight) {
        Edges++;
        verList[start].head = new edgeNode(weight,ending,verList[start].head);
    }
    
    void traverse() {
        edgeNode *p;
        for (int i = 0;i < Vers;i++) {
            verNode q = verList[i];
            p = q.head;
            cout << q.ver << ' ';
            while (p != NULL) {
                cout << p->end << ' ';
                p = p->next;
            }
            cout << endl;
        }
    }
    
    void sPath(int start,int end) {
        Queue<int> q;
        int *distance;
        distance = new int[Vers];
        for (int i = 0;i < Vers;i++) distance[i] = 2147483647;
        
        distance[start] = 0;
        q.push(start);
        
        while (!q.isEmpty()) {
            int v = q.front();
            q.pop();
            for (edgeNode *p = verList[v].head;p != NULL;p = p->next) {
                if (distance[v] + p->weight < distance[p->end]) {
                    distance[p->end] = distance[v] + p->weight;
                    q.push(p->end);
                }
            }
            //            for (int i = 0;i < Vers;i++) cout << distance[i] << ' ';
            //            cout << endl;
        }
        
        cout << distance[end];
    }
};

int main()
{
    int n,m,start,end;
    int a,b,p;
    cin >> n >> m >> start >> end;
    
    adjListGraph alg(n);
    
    for (int i = 0;i < m;i++) {
        cin >> a >> b >> p;
        alg.insert(a-1,b-1,p);
    }
    
    //alg.traverse();
    
    alg.sPath(start-1,end-1);
}
