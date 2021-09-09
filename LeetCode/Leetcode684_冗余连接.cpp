class DisjointSet {
public:
    DisjointSet(int n) : parent_(vector<int>(n, 0)) {
        for (int i = 0; i < n; ++i) parent_[i] = i;
    }
    
    void Union(int i, int j) {
        while (parent_[i] != i) i = parent_[i];
        while (parent_[j] != j) j = parent_[j];
        parent_[j] = i;
    }
    
    bool isConnected(int i, int j) {
        while (parent_[i] != i) i = parent_[i];
        while (parent_[j] != j) j = parent_[j];
        return i == j;
    }
    
private:
    vector<int> parent_;
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = 0;
        for (auto& e : edges) {
            n = max(n, e[0]);
            n = max(n, e[1]);
        }
        // cout << n << '\n';
        auto djs = DisjointSet(n);
        for (auto& e : edges) {
            if (djs.isConnected(e[0] - 1, e[1] - 1)) return e;
            else djs.Union(e[0] - 1, e[1] - 1);
        }
        return {};
    }
};
