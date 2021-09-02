class Solution {
public:
    unordered_map<int,vector<int> > mp;
    vector<int> beautifulArray(int N) {
        return f(N);
    }
    vector<int> f(int N) {
        vector<int> ans(N, 0);
        int t = 0;
        if (mp.find(N) != mp.end()) {
            return mp[N];
        }
        if (N != 1) {
            for (auto x : f((N+1)/2)){
                ans[t++]= 2 * x - 1;
            }
            for (auto x : f(N/2)){
                ans[t++] =  2 * x;
            }
        }else {
            ans[0] = 1;
        }
        mp[N] = ans;
        return ans;
    }
};
