class Solution {
public:
    bool checkBomb(vector<int> bomb1, vector<int> bomb2) {
        // Detonate Bomb1 will or will not influence bomb2
        return bomb1[2] - sqrt(pow((bomb2[0] - bomb1[0]), 2) + pow((bomb2[1] - bomb1[1]), 2)) >= 0;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        unordered_map<int, vector<int>> i2n;
        int n = bombs.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (checkBomb(bombs[i], bombs[j])) i2n[i].emplace_back(j);
                if (checkBomb(bombs[j], bombs[i])) i2n[j].emplace_back(i);
            }
        }

        int res = 0;
        for (int i = 0; i < n; ++i) {
            int bomb = 0;
            vector<bool> visited(n, false);
            visited[i] = true;
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                auto cur = q.front();
                q.pop();
                for (auto& influenced : i2n[cur]) {
                    if (visited[influenced]) continue;
                    q.push(influenced);
                    visited[influenced] = true;
                }
                ++bomb;
            }
            res = max(res, bomb);
        }

        return res;
    }
};