class DisjointSet {
public:
    DisjointSet(int n) : parents(n, 0), sizes(n, 1) {
        iota(parents.begin(), parents.end(), 0);
    }
    
    int Find(int x) {
        while (parents[x] != x) {
            int p = parents[parents[x]];
            parents[x] = p;
            x = parents[x];
        }
        return x;
    }
    
    void Union(int x, int y) {
        int i = Find(x), j = Find(y);
        if (i == j) return;
        
        if (sizes[i] > sizes[j]) {
            parents[j] = i;
            sizes[i] += sizes[j];
        } else {
            parents[i] = j;
            sizes[j] += sizes[i];
        }
    }
    
    bool isConnected(int x, int y) {
        return Find(x) == Find(y);
    }
    
    bool AllConnected() {
        for (auto& s : sizes) {
            if (s == parents.size()) return true;
        }
        
        return false;
    }
    
    vector<int> parents;
    vector<int> sizes;
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        DisjointSet djs(n);
        for (auto& e : edges) {
            if (djs.isConnected(e[0], e[1])) return false;
            else djs.Union(e[0], e[1]);
        }
        return djs.AllConnected();
    }
};
