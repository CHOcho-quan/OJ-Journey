#include <iostream>
#include <algorithm>
using namespace std;
const int N = 300010;

struct edge{
    int x;
    int y;
    int score;
    bool operator < (const edge &rhs)const {return score < rhs.score;}
};


int main()
{
    int n,m;
    cin >> n >> m;
//    int A[20];
//    for(int i=1;i<=n;i++)A[i] = i;
//    adjlistGraph<int,int> G(n,A);
    int nodeScorePrev[N]={0};
    int nodeScore[N]={0};
    int edgeLength[N]={0};
    int nodeLengthPrev[N]={0};
    int nodeLength[N]={0};

    int x,y,w;
    edge E[N];
    for(int i=0;i<m;i++){
        cin >> x >> y >> w;
        E[i].x = x;
        E[i].y = y;
        E[i].score = w;
    }
    sort(E,E+m);

    int ans=0;
    for(int i=0;i<m;i++){
        int from = E[i].x, to = E[i].y;
        int nowScore = E[i].score;
        if (nowScore > nodeScore[from])
        {
            if (nodeLength[from]+1 > nodeLength[to])
            {
                nodeScorePrev[to] = nodeScore[to];
                nodeLengthPrev[to] = nodeLength[to];

                nodeScore[to] = nowScore;
                nodeLength[to] = nodeLength[from] + 1;

            }

        }
        else if (nowScore == nodeScore[from]){
            if (nodeLengthPrev[from]+1 > nodeLength[to])
            {

                nodeScorePrev[to] = nodeScore[to];
                nodeLengthPrev[to] = nodeLength[to];

                nodeScore[to] = nowScore;
                nodeLength[to] = nodeLengthPrev[from] + 1;
            }
        }

//        cout << i << endl;
//        for(int j = 1;j<=n;j++) cout << "i:" << j << "\tNodeScore" << nodeScore[j] << "\tNodeLength" << nodeLength[j] << "\tNodeScorePrev" << nodeScorePrev[j]
//            << "\tNodeLengthPrev" << nodeLengthPrev[j] << endl;

    }

//    for (int i=0;i<m;i++){
//        cout << E[i].x << " " << E[i].y << " " << E[i].score << endl;
//    }

    for (int i=0;i<m;i++) if (nodeLength[i]>ans) ans = nodeLength[i];
    cout << ans << endl;
    return 0;
}
