//
//  POJ1815_网络流与柴电.cpp
//  
//
//  Created by 铨 on 2018/11/6.
//
//

#include<iostream>
#include<queue>

using namespace std;

const int MAXN=1010;
const int MAXM=400020;
const int INF=2147483647;

struct Edge{
    int to,nxt,cap;
};

Edge edge[MAXM];

int n,cnt,head[MAXN],src,des;
int dep[MAXN];

void addedge(int cu,int cv,int cw)
{
    edge[cnt].to=cv;
    edge[cnt].cap=cw;
    edge[cnt].nxt=head[cu];
    head[cu]=cnt++;
    
    edge[cnt].to=cu;
    edge[cnt].cap=0;
    edge[cnt].nxt=head[cv];
    head[cv]=cnt++;
}

int BFS(){
    queue<int> q;
    while(!q.empty())
        q.pop();
    for (int i = 0;i < MAXN;i++) dep[i] = -1;
    dep[src]=0;
    q.push(src);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=head[u];i!=-1;i=edge[i].nxt){
            int v=edge[i].to;
            if(edge[i].cap>0 && dep[v]==-1){
                dep[v]=dep[u]+1;
                q.push(v);
            }
        }
    }
    return dep[des]!=-1;
}

int DFS(int u,int minx){
    if(u==des)
        return minx;
    int tmp;
    for(int i=head[u];i!=-1;i=edge[i].nxt){
        int v=edge[i].to;
        if(edge[i].cap>0 && dep[v]==dep[u]+1 && (tmp=DFS(v,min(minx,edge[i].cap)))){
            edge[i].cap-=tmp;
            edge[i^1].cap+=tmp;
            return tmp;
        }
    }
    dep[u]=-1;
    return 0;
}

int Dinic(){
    int ans=0,tmp;
    while(BFS()){
        while(true){
            tmp=DFS(src,INF);
            if(tmp==0)
                break;
            ans+=tmp;
        }
    }
    return ans;
}

int s,t,map[MAXN][MAXN],g[MAXN][MAXN];

void buildgraph()
{
    cnt=0;
    for (int i = 0;i < MAXN;i++) head[i] = -1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j){
                if(map[i][j]==1)    //拆点建边，连通着的两点边权为INF保证不会成为割边
                    addedge(n+i,j,INF);
            }
            else{
                if(i==s || i==t)    //s点，t点，题意表明不会出现问题，即拆成的两点不会成为割边
                    addedge(i,n+i,INF);
                else
                    addedge(i,n+i,1);   //其余点则有可能成为割边，边权为1保证只切割一次
            }
}

int main()
{
    int res[MAXN];
    cin >> n >> s >> t;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin >> map[i][j];
    if(map[s][t]==1){
        puts("NO ANSWER!");
        return 1; }buildgraph();
    src=s,  des=n+t;
    int ans=Dinic();
    cout << ans << ' ';
    if(ans==0)
        return 1;
    int tot=0;
    for(int i=1;i<=n;i++){
        if(i==s || i==t)
            continue;
        for(int j=1;j<=n;j++) {
            for (int k = 1; k <= n; k++) {
                g[j][k] = map[j][k];
                if (j == i || k == i)
                    map[j][k] = 0; }}buildgraph();
        int tmp=Dinic();
        if(ans>tmp){
            ans--;
            res[tot++]=i; }else{
                for(int j=1;j<=n;j++)
                    for(int k=1;k<=n;k++)
                        map[j][k]=g[j][k]; }if(tmp==0)break; }for(int i=0;i<tot-1;i++)cout << res[i] << ' ';
    cout << res[tot-1];
    
    return 0;
}
