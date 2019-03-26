//
//  SJTU1031_黄山的二分查找+BFS.cpp
//
//
//  Created by 铨 on 2019/3/24.
//
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
const int MaxN = 101;

int MAP[MaxN][MaxN];
int n;
int Max=-1,Min=2147483647;
bool vis[MaxN][MaxN];
struct Point
{
    int x;
    int y;
    Point(int a,int b){
        x = a;
        y = b;
    }
};

int to_x[4] = {-1,+1,0,0};
int to_y[4] = {0,0,-1,+1};

queue<Point> q;

bool bfs(int low_bd, int up_bd){
    if(MAP[1][1]>up_bd or MAP[1][1]<low_bd or MAP[n][n]>up_bd or MAP[n][n]<low_bd)
        return false;
    memset(vis,false,sizeof(vis));
    Point start(1,1);
    while(!q.empty())
        q.pop();
    q.push(start);

    while(!q.empty()){
        Point cur =  q.front();
        q.pop();
        vis[cur.x][cur.y] = true;

        for (int i = 0; i < 4; ++i)
        {
            int x = cur.x + to_x[i];
            int y = cur.y + to_y[i];
            if(x<1 or x>n or y<1 or y>n)
                continue;
            if(vis[x][y])
                continue;
            if(MAP[x][y]<low_bd or MAP[x][y]>up_bd)
                continue;
            Point nxt(x,y);
            q.push(nxt);
            vis[x][y] = true;
            if(vis[n][n])
                return true;
        }

    }
    return false;
}


void init(){

}

int BinaryFind(){
    int low = 0, high = Max - Min;
    int mid;

    while(low<high){
        mid = (low + high) / 2;
        bool isOK = false;
        for (int i = Min; i <= Max-mid ; ++i)
        {
            if(bfs(i,i+mid)){
                isOK = true;
                break;
            }
        }

        if(isOK)    high = mid;
        else        low = mid + 1;
    }
    return low;
}

int main()
{
    cin>>n;
    for (int i = 1; i <= n; ++i){
      for (int j = 1; j <= n; ++j){
          cin>>MAP[i][j];
          Max = max(Max,MAP[i][j]);
          Min = min(Min,MAP[i][j]);
      }
    }
    cout<<BinaryFind()<<endl;
}
