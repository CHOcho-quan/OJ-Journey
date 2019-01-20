#include <iostream>
#include <vector>

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
        
        edgeNode(int e,int w,edgeNode *n = NULL) {
            end = e;
            weight = w;
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
    
    int Vers;
    int Edges;
    verNode *verList;
public:
    adjListGraph(int n) {
        Vers = n;
        Edges = 0;
        verList = new verNode[Vers];
        
        for (int i = 0;i < Vers;i++) {
            verList[i].ver = i;
        }
    }
    
    void insert(int s,int e,int w) {
        verList[s].head = new edgeNode(e,w,verList[s].head);
        verList[e].head = new edgeNode(s,w,verList[e].head);
        Edges++;
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
    
    void Kruskal(WeightNode * v,int size) {
        DisjointSet djs(Vers);
        int t = 0,sum = 0;
        
        for (t;t < size;t++){
            if (djs.Find(v[t].ver1)!=djs.Find(v[t].ver2)) {
                djs.Union(djs.Find(v[t].ver1),djs.Find(v[t].ver2));
                sum+=v[t].weight;
            }
        }
        
        cout << sum;
    }
    
    void Prim() {
        bool *visit;
        int *lowCost,MAX=2147483647,result = 0;
        lowCost = new int[Vers];
        visit = new bool[Vers];
        for (int i = 0;i < Vers;i++) {
            visit[i] = false;
            lowCost[i] = MAX;
        }
        
        int now = 0;
        bool flag = true;
        while (flag) {
            visit[now] = true;
            for (edgeNode *p = verList[now].head;p != NULL;p = p->next) {
                if (!visit[p->end] && lowCost[p->end] > p->weight) lowCost[p->end] = p->weight;
            }
            
            int min = MAX;
            for (int i = 0;i < Vers;i++) {
                if (!visit[i] && lowCost[i] < min) {
                    min = lowCost[i];
                    now = i;
                }
            }
            //cout << now << endl;
            if (min != MAX) result+=min;
            
            for (int i = 0;i < Vers;i++) {
                if (!visit[i]) {
                    flag = false;
                    break;
                }
            }
            if (!flag) flag = true;
            else break;
        }
        cout<< result;
    }
};

int main()
{
    int n,count = 0;
    char village;
    int paths;
    int cost;
    char end;
    
    cin >> n;
    adjListGraph alg(n);
    vector<WeightNode> v;
    WeightNode *we;
    
    for (int i = 0;i < n-1;i++) {
        cin >> village >> paths;
        int start = village - 'A';
        count+=paths;
        for (int j = 0;j < paths;j++) {
            cin >> end >> cost;
            int ending = end - 'A';
            WeightNode tmp(cost,start,ending);
            v.push_back(tmp);
            alg.insert(start,ending,cost);
        }
    }
    
    we = new WeightNode[count];
    for (int i = 0;i < count;i++) we[i] = v[i];
    QuickSort(we,0,count-1);
    
    //alg.traverse();
    
    alg.Prim();
}
