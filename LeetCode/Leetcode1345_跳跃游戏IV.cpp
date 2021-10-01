class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> rem;
        unordered_map<int, unordered_set<int>> rec;
        for (int i = 0; i < n; ++i) rec[arr[i]].insert(i);
        queue<int> q;
        q.push(n - 1);
        int cnt = 0;
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                auto cur = q.front(); q.pop();
                rem[cur] = cnt;
                if (cur == 0) return cnt;
                if (cur + 1 < n && !rem.count(cur + 1)) q.push(cur + 1);
                if (cur - 1 >= 0 && !rem.count(cur - 1)) q.push(cur - 1);
                for (auto& next : rec[arr[cur]]) {
                    if (!rem.count(next)) q.push(next);
                }
                rec[arr[cur]].clear();
            }
            ++cnt;
        }
        
        return -1;
    }
};
