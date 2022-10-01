class UnionFind {
public:
    UnionFind(int n) {
        data_ = vector<int>(n, -1);
    }
    
    void Union(int x, int y) {
        int px, py;
        while (data_[x] != -1) {
            x = data_[x];
        }
        px = x;
        while (data_[y] != -1) {
            y = data_[y];
        }
        py = y;
        if (px == py) return;
        data_[px] = py;
        // for (auto& di : data_) cout << di << ' ';
        // cout << '\n';
    }
    
    bool AllKnown() {
        int cnt = 0;
        for (auto& di : data_) {
            if (di == -1) ++cnt;
            if (cnt > 1) return false;
        }
        return cnt <= 1;
    }
    
private:
    vector<int> data_;
};

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        std::sort(logs.begin(), logs.end(), [](const vector<int>& l1, const vector<int>& l2) {return l1[0] < l2[0];});
        UnionFind uf(n);
        for (auto& log : logs) {
            uf.Union(log[1], log[2]);
            if (uf.AllKnown()) return log[0];
        }
        
        return -1;
    }
};