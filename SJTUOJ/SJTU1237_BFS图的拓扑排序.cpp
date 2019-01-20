//
//  1237_BFS图的拓扑排序.cpp
//  
//
//  Created by 铨 on 2018/6/6.
//
//

#include <iostream>
#include <queue>

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


class adjListGraph {
private:
    class edgeNode {
    public:
        int end;
        edgeNode *next;
        
        edgeNode(int e,edgeNode *n = NULL) {
            end = e;
            next = n;
        }
    };
    
    class verNode {
    public:
        int ver;
        int in;
        edgeNode *head;
        
        verNode(int v = 0,int i = 0,edgeNode *h = NULL) {
            ver = v;
            in = i;
            head = h;
        }
    };
    int Vers;
    int Edges;
    verNode *verList;
    
public:
    adjListGraph(int verSize) {
        Vers = verSize;
        Edges = 0;
        
        verList = new verNode[Vers];
        for (int i = 0;i < Vers;i++) verList[i].ver = i;
    }
    
    void traverse() {
        for (int i = 0;i < Vers;i++) {
            cout << verList[i].ver << ' ';
            for (edgeNode *p = verList[i].head;p!=NULL;p=p->next) {
                cout << p->end << ' ';
            }
            cout << endl;
        }
    }
    
    void insert(int start,int end) {
        verList[start].head = new edgeNode(end,verList[start].head);
        verList[end].in++;
        Edges++;
    }
    
    void topology() {
        Queue<int> q(10000);
        int result = 0,count = 0,count1 = 0;
        for (int i = 0;i < Vers;i++) {
            if (verList[i].in == 0) {
                q.push(i);
                count++;
            }
        }
        
        while (!q.isEmpty()) {
            for (int i = 0;i < count;i++) {
                int now = q.front();
                q.pop();
                for (edgeNode *p = verList[now].head;p!=NULL;p=p->next) {
                    verList[p->end].in--;
                    if (verList[p->end].in == 0) {
                        q.push(p->end);
                        count1++;
                    }
                }
            }
            
            count = count1;
            count1 = 0;
            result++;
        }
        
        cout << result;
    }
};

int main()
{
    int n,m,a,b;
    cin >> n >> m;
    adjListGraph alg(n);
    
    for (int i = 0;i < m;i++) {
        cin >> a >> b;
        alg.insert(a-1,b-1);
    }
    
    //alg.traverse();
    alg.topology();
}
