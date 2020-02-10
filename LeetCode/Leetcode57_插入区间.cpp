#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
{
    vector<vector<int>> result;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    for (auto p:intervals) pq.push(p);

    vector<int> cur;
    bool flag = false;
    while (!pq.empty())
    {
        cur = pq.top();
        pq.pop();

        if (newInterval[1] < cur[0])
        {
            result.push_back(newInterval);
            result.push_back(cur);
            flag = true;
            break;
        }

        if (newInterval[0] > cur[1])
        {
            result.push_back(cur);
            continue;
        }

        newInterval[0] = min(newInterval[0], cur[0]);
        newInterval[1] = max(newInterval[1], cur[1]);
    }

    if (!flag) result.push_back(newInterval);

    while (flag && !pq.empty())
    {
        cur = pq.top();
        pq.pop();
        result.push_back(cur);
    }

    for (auto p:result)
    {
        for (auto pp:p)
        {
            cout << pp << ' ';
        }
        cout << endl;
    }

    return result;
}

int main()
{
    vector<vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> newInterval = {4, 8};
    insert(intervals, newInterval);
}