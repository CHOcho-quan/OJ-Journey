#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool isNStraightHand(vector<int>& hand, int W) {
    if (1 - hand.size() % W == 0) return 0;
    if (hand.size()==0) return false;
    
    priority_queue<int, vector<int>, greater<int>> q;
    for (auto p:hand) q.push(p);

    int cnt = W-1, last = q.top();
    //cout << last;
    q.pop();
    vector<int> waitingList;
    while (!q.empty())
    {
        if (cnt == 0)
        {
            for (auto p : waitingList)  q.push(p);
            waitingList.clear();
            last = q.top();
            q.pop();
            cnt = W-1;
        }
        else 
        {
            int now = q.top();
            if (now > last + 1) return false;
            else if (now == last + 1) {
                last = q.top();
                q.pop();
                cnt--;
            }
            else {
                waitingList.push_back(now);
                q.pop();
            }
        }
    }

    if (waitingList.size()==0) return true;
    else return false;
    
}

int main()
{
    vector<int> h = {1,2,3,6,2,3,4,7,8};
    cout << isNStraightHand(h, 3);
}