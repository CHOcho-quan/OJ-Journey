#include <iostream>
using namespace std;

template <class ver_type, class edge_type>
class graph
{
public:
    virtual void insert(ver_type x, ver_type y, edge_type w) = 0;
    virtual void remove(ver_type x, ver_type y) = 0;
    virtual bool exist(ver_type x, ver_type y)const = 0;
    int ver_num()const{ return vers;}
    int edge_num()const { return  edges;}

    int vers,edges;
};

template <class ver_type, class edge_type>
class adjListGraph:public graph<ver_type,edge_type>
{
public:
    adjListGraph(int v_size, const ver_type *d);
    ~adjListGraph();
    void insert(ver_type x, ver_type y, edge_type w);
    void remove(ver_type x, ver_type y);
    bool exist(ver_type x, ver_type y)const;

    void insert_1565(ver_type x, ver_type y, edge_type w, edge_type s);
    void dj_1565(ver_type start, ver_type end, edge_type noEdge)const;

private:
    int vers,edges;
    struct edgeNode{
        int end;
        edge_type weight;
        edge_type spend;
        edgeNode *next;

        edgeNode(int e,edge_type w,edge_type s, edgeNode *n = nullptr){
            end = e;weight = w;spend = s;next = n;
        }
    };
    struct verNode{
        ver_type ver;
        edgeNode *head;

        verNode(edgeNode *h = nullptr){head = h;}
    };

    verNode *verList;
    int find(ver_type v)const{
        for (int i = 0; i < vers; ++i) {
            if(verList[i].ver == v) return i;
        }
    }
};

template <class ver_type, class edge_type>
adjListGraph<ver_type, edge_type>::adjListGraph(int v_size, const ver_type *d) {
    vers = v_size;
    edges = 0;
    verList = new verNode[vers];
    for (int i = 0; i < vers; ++i) {
        verList[i].ver = d[i];
    }
}

template <class ver_type, class edge_type>
adjListGraph<ver_type, edge_type>::~adjListGraph() {
    edgeNode *p;
    for (int i = 0; i < vers; ++i) {
        while((p = verList[i].head)!= nullptr){
            verList[i].head = p->next;
            delete p;
        }
    }
    delete [] verList;
}

template <class ver_type, class edge_type>
void adjListGraph<ver_type, edge_type>::insert(ver_type x, ver_type y, edge_type w) {
    int u = find(x);
    int v = find(y);
    verList[u].head = new edgeNode(v,w,0,verList[u].head);
    ++edges;
}

template <class ver_type, class edge_type>
void adjListGraph<ver_type, edge_type>::remove(ver_type x, ver_type y) {
    int u = find(x);
    int v = find(y);
    edgeNode *p = verList[u].head, *q;
    if(p == nullptr)return;
    if(p->end == v){
        verList[u].head = p->next;
        delete p;
        --edges;
        return;
    }
    while(p->next != nullptr && p->next->end != v)p = p->next;
    if(p->next != nullptr){
        q = p->next;
        p->next = q->next;
        delete q;
        --edges;
    }
}

template <class ver_type, class edge_type>
bool adjListGraph<ver_type, edge_type>::exist(ver_type x, ver_type y) const {
    int u = find(x);
    int v = find(y);
    edgeNode *p = verList[u].head;
    while(p!=nullptr && p->end != v)p = p->next;
    return p!= nullptr;
}

template <class ver_type, class edge_type>
void adjListGraph<ver_type, edge_type>::insert_1565(ver_type x, ver_type y, edge_type w, edge_type s) {
    int u = find(x);
    int v = find(y);
    verList[u].head = new edgeNode(v,w,s,verList[u].head);
    ++edges;
}

template <class ver_type, class edge_type>
void adjListGraph<ver_type, edge_type>::dj_1565(ver_type start, ver_type end, edge_type noEdge) const{
    edge_type *distance = new edge_type[vers];
    edge_type *spend = new edge_type[vers];

    int *prev = new int[vers];
    bool *known = new bool[vers];

    int u,sNo,i,j;
    edgeNode *p;
    edge_type mind;
    edge_type mins;

    for (i = 0;  i<vers ; ++i) {
        known[i] = false;
        distance[i] = noEdge;
        spend[i] = noEdge;
    }

    sNo = find(start);
    distance[sNo] = 0;
    spend[sNo] = 0;
    prev[sNo] = sNo;

    for (i = 1;  i<vers ; ++i) {
        mind = noEdge;
        mins = noEdge;

        for (j = 0; j <vers ; ++j) {
            if(!known[j] && distance[j]<mind){
                mind = distance[j];
                mins = spend[j];
                u = j;
            }
        }
        known[u] = true;
        for(p = verList[u].head;p!=nullptr;p = p->next){
            if(!known[p->end] && distance[p->end]>mind+p->weight){
                if(spend[p->end] > mins + p->spend){
                    distance[p->end] = mind + p->weight;
                    spend[p->end] = mins + p->spend;
                    prev[p->end] = u;
                }
            }
        }
    }
    int v = find(end);
    cout<<distance[v]<<' '<<spend[v];
}


int main() {
    int n,m;
    cin>>n>>m;
    auto d = new int[n];
    for (int i = 0; i <n ; ++i) {
        d[i] = i+1;
    }
    adjListGraph<int,int> adjG(n,d);
    int a,b,w,s;
    for (int i = 0; i < m; ++i) {
        cin>>a>>b>>w>>s;
        adjG.insert_1565(a,b,w,s);
    }
    int start,end;
    cin>>start>>end;
    adjG.dj_1565(start,end,0xfffffff);
    return 0;
}