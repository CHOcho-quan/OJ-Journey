#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> allCellsDistOrderFast(int R, int C, int r0, int c0) {
    vector<vector<int>> ans;

    for (int i = 0;i < R;i++) for (int j = 0;j < C;j++) ans.push_back({i, j});
    sort(ans.begin(), ans.end(), [&r0, &c0] (vector<int> &a, vector<int> &b){return abs(a[0] - r0) + abs(a[1] - c0) < abs(b[0] - r0) + abs(b[1] - c0);});

    return ans;
}

vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
    vector<vector<int>> ans;
    vector<int> dist;
    for (int i = 0;i < R;i++)
    {
        for (int j = 0;j < C;j++)
        {
            int dis = abs(r0-i) + abs(c0-j);
            if (ans.size()==0)
            {
                dist.push_back(dis);
                ans.push_back({i, j});
                continue;
            }
            
            bool insert_flag = false;
            for (int k = 0;k < ans.size();k++)
            {
                if (dis >= dist[k]) continue;
                else {
                    dist.insert(dist.begin() + k, dis);
                    ans.insert(ans.begin() + k, {i, j});
                    insert_flag = true;
                    break;
                }
            }
            if (!insert_flag)
            {
                dist.insert(dist.begin() + dist.size(), dis);
                ans.insert(ans.begin() + ans.size(), {i, j});
            }
        }
    }

    return ans;
}

int main()
{
    vector<vector<int> > ans = allCellsDistOrder(2, 2, 0, 1);
    for (auto a:ans)
    {
        cout << '[';
        for (auto p:a)
        {
            cout << p << ' ';
        }
        cout << ']';
    }
}