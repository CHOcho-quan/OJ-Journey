#include <string>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int> &A, int K)
    {
        A.insert(A.begin(), 0);

        vector<int> presum = vector<int>(A.size(), 0);
        deque<int> buff;
        int minvalue = INT32_MAX;

        for (int i = 0; i < presum.size(); i++) {
            if (i == 0) {
                presum[i] = A[i];
            } else {
                presum[i] = presum[i - 1] + A[i];
            }
            // cout << presum[i] << ' ';
        }

        for (int i = 0; i < presum.size(); i++) {
            
            while(!buff.empty() && presum[i]<presum[buff.front()]){
                buff.pop_front();
            }

            while(!buff.empty() && presum[i] - presum[buff.back()]>=K){
                minvalue = min(minvalue,i-buff.back());
                buff.pop_back();
            }

            buff.push_front(i);

        }

        return minvalue == INT32_MAX ? -1 : minvalue;
    }

};