//
//  adjGraph.cpp
//  
//
//  Created by 铨 on 2019/4/10.
//
//

#include <iostream>
#include <iomanip>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

template <class T>
class adjGraph
{
private:
    int Edges;
    int Vers;
    class EdgeNode
    {
    public:
        T weight;
        int end;
        EdgeNode *next;
        
        EdgeNode(T w, int e, EdgeNode *n = NULL) {
            weight = w;
            end = e;
            next = n;
        }
    };
    class verNode
    {
    public:
        int node;
        EdgeNode *head;
        
        verNode(int no, EdgeNode *h = NULL) {
            node = no;
            head = h;
        }
        
        verNode() {}
    };
    verNode *storage;
public:
    adjGraph(int nodes) {
        Edges = 0;
        Vers = nodes;
        storage = new verNode[Vers];
        for (int i = 0;i < Vers;i++) storage[i] = verNode(i);
    }
    
    void insert(int s, int e, T weight);
    void remove(int s, int e);
    bool exist(int s, int e);
    void DFS(verNode r);
    void BFS(verNode r);
};

template <class T>
void adjGraph<T>::insert(int s, int e, T weight)
{
    Edges++;
    storage[s].head = new adjGraph<T>::EdgeNode(weight, e, storage[s].head);
}

template <class T>
void adjGraph<T>::remove(int s, int e)
{
    adjGraph<T>::verNode tmp = storage[s];
    adjGraph<T>::EdgeNode *temp = tmp.head;
    adjGraph<T>::EdgeNode *temp_l = tmp.head;
    bool findFlag = false;
    
    while (temp != NULL)
    {
        if (temp->end == e)
        {
            adjGraph<T>::EdgeNode *a = temp;
            temp_l->next = temp->next;
            delete a;
            findFlag = true;
            break;
        }
        temp_l = temp;
        temp = temp->next;
    }
    
    if (findFlag) return ;
    else cout << "No such edge!" << endl;
}

template <class T>
bool adjGraph<T>::exist(int s, int e)
{
    adjGraph<T>::verNode tmp = storage[s];
    adjGraph<T>::EdgeNode *temp = tmp.head;
    adjGraph<T>::EdgeNode *temp_l = tmp.head;
    bool findFlag = false;
    
    while (temp != NULL)
    {
        if (temp->end == e)
        {
            adjGraph<T>::EdgeNode *a = temp;
            temp_l->next = temp->next;
            delete a;
            findFlag = true;
            break;
        }
        temp_l = temp;
        temp = temp->next;
    }
    
    return findFlag;
}

template <class T>
void adjGraph<T>::DFS(adjGraph<T>::verNode r)
{
    bool *visit;
    visit = new bool[Vers];
    for (int i = 0;i < Vers;i++) visit[i] = false;
    stack<adjGraph<T>::verNode> st;
    st.push(r);
    
    while (!st.empty())
    {
        adjGraph<T>::verNode a = st.top();
        cout << a.node << ' ';
        visit[a.node] = true;
        adjGraph<T>::EdgeNode *tmp = st.top().head;
        while (tmp != NULL && visit[tmp->end])
        {
            tmp = tmp->next;
        }
        if (tmp != NULL) {
            st.push(storage[tmp->end]);
        }
    }
}

template <class T>
void adjGraph<T>::BFS(adjGraph<T>::verNode r)
{
    bool *visit;
    visit = new bool[Vers];
    for (int i = 0;i < Vers;i++) visit[i] = false;
    queue<adjGraph<T>::verNode> q;
    q.push(r);
    
    while (!q.empty())
    {
        adjGraph<T>::verNode a = q.front();
        cout << a.node << ' ';
        visit[a.node] = true;
        adjGraph<T>::EdgeNode *tmp = q.front().head;
        q.pop();
        while (tmp != NULL)
        {
            adjGraph<T>::verNode n = storage[tmp->end];
            if (!visit[tmp->end]) q.push(n);
            tmp = tmp->next;
        }
    }
}

int main()
{
    
}
