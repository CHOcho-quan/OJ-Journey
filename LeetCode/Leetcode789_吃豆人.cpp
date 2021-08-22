class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int dis = abs(target[0]) + abs(target[1]), gdis = 2147483647;
        for (auto& ghost : ghosts) {
            gdis = min(abs(ghost[0] - target[0]) + abs(ghost[1] - target[1]), gdis);
            if (gdis <= dis) return false;
        }
        return true;
    }
};
