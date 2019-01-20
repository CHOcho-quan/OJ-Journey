//
//  OJ1233_回溯dfs求图的简单路径.cpp
//  
//
//  Created by 铨 on 2018/5/25.
//
//
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

int result = 0;

class adjListGraph {
private:
    int Vers;
    int Edges;
    
    struct edgeNode {
        int weight;
        int end;
        bool visited;
        int visit;
        edgeNode *next;
        
        edgeNode(int w, int e, edgeNode *n = NULL) {
            weight = w;
            end = e;
            next = n;
            visited = false;
            visit = -1;
        }
    };
    
    struct verNode {
        int ver;
        edgeNode *head;
        
        verNode(int v = 0, edgeNode *h = NULL) {
            ver = v;
            head = h;
        }
    };
    
public:
    verNode *verList;
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
    
    void traverse1() {
        for (int i = 0; i < Vers; i++) {
            edgeNode *p = verList[i].head;
            cout << verList[i].ver << '\t';
            while (p != NULL) {
                cout << p->visited << ' ';
                p = p->next;
            }
            cout << endl;
        }
    }
    
    bool dfs(int start, int M) {
        stack<int> st;
        vector<int> path;
        st.push(start);
        path.push_back(start);
        bool flag = false,flag2 = false;
        
        while (!st.empty()) {
            edgeNode *p = verList[st.top()].head;
            if (p == NULL) {
                edgeNode *tmp = verList[st.top()].head;
                while (tmp != NULL) {
                    tmp->visited = false;
                    tmp = tmp->next;
                }
                st.pop();
                path.pop_back();
                M++;
                continue;
            }
            
            edgeNode *q = p;
            while (q != NULL) {
                for (int i = 0;i < path.size();i++) {
                    if (q->end == path[i] || q->visited) {flag = true;break;}
                }
                if (flag) {q = q->next;flag = false;continue;}
                else break;
            }
            p = q;
            
            if (p != NULL) {
                flag2 = true;
                int s = st.top();
                int e = p->end;
                p->visited = true;
                st.push(p->end);
                path.push_back(p->end);
                M--;
            }
            
            traverse1();
            cout << endl;
            
            if (M == 0) {
                edgeNode *tmp = verList[st.top()].head;
                while (tmp != NULL) {
                    tmp->visited = false;
                    tmp = tmp->next;
                }
                st.pop();
                path.pop_back();
                M++;
                result++;
                flag2 = false;
                continue;
            }
            
            if (!flag2) {
                edgeNode *tmp = verList[st.top()].head;
                while (tmp != NULL) {
                    tmp->visited = false;
                    tmp = tmp->next;
                }
                st.pop();
                path.pop_back();
                M++;
            }
            flag2 = false;
        }
    }
    
    adjListGraph(int vers) {
        Vers = vers;
        Edges = 0;
        verList = new verNode[vers];
        for (int i = 0;i < vers;i++) verList[i] = verNode(i);
    }
    
    void insert(int start,int end,int weight = 1) {
        verList[start].head = new edgeNode(weight,end,verList[start].head);
        Edges++;
    }
    
    bool remove(int start,int ending) {
        edgeNode *pe = verList[start].head;
        if (pe == NULL) return false;
        if (pe->end == ending) {
            verList[start].head = pe->next;
            delete pe;
            Edges--;
            return true;
        }
        
        while (pe != NULL) {
            if (pe->next != NULL) {
                if (pe->next->end == ending) {
                    edgeNode *q = pe->next;
                    pe->next = q->next;
                    delete q;
                    Edges--;
                    return true;
                }
            }
            else return false;
            pe = pe->next;
        }
    }
    
    bool exist(int start, int ending) {
        edgeNode *p = verList[start].head;
        while (p != NULL) {
            if (p->end == ending) return true;
        }
        return false;
    }
};

//int main()
//{
//    adjListGraph alg(10);
//    alg.insert(1,3);
//    alg.insert(0,9);
//    alg.insert(2,7);
//
//    alg.remove(3,5);
//    alg.remove(2,8);
//    alg.remove(1,9);
//    alg.remove(4,5);
//    alg.remove(8,5);
//    alg.remove(1,5);
//
//    alg.remove(1,3);
//    cout << (alg.verList[1].head==NULL);
//
//    alg.traverse();
//}

int main()
{
    int n,m,start,M;
    int a,b;
    cin >> n >> m >> start >> M;
    adjListGraph alg(n);
    
    for (int i = 0;i < m;i++)
    {
        cin >> a >> b;
        alg.insert(a-1,b-1);
    }
    
    alg.traverse();
    cout << endl;
    alg.dfs(start-1,M);
    
    cout << result;
    
    return 0;
}

