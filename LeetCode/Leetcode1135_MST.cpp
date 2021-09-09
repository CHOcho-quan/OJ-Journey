class DisjointSet {
public:
    DisjointSet(int n) : parent_(n, 0), size_(n, 1) {
        iota(parent_.begin(), parent_.end(), 0);
    }
    
    int find(int i) {
        while (parent_[i] != i) {
            parent_[i] = parent_[parent_[i]];
            i = parent_[i];
        }
        return i;
    }
    
    void unionSets(int i, int j) {
        int ii = find(i), jj = find(j);
        if (ii != jj) {
            if (size_[ii] > size_[jj]) {
                parent_[jj] = ii;
                size_[ii] += size_[jj];
                max_size = max(max_size, size_[ii]);
            } else {
                parent_[ii] = jj;
                size_[jj] += size_[ii];
                max_size = max(max_size, size_[jj]);
            }
        }
    }
    
    bool isConnected(int i, int j) {
        return find(i) == find(j);
    }
    
    int max_size = 1;
    
private:
    vector<int> parent_, size_;
};

class Solution {
public:
    struct cmp {
        bool operator()(const vector<int>& v1, const vector<int>& v2) {
            return v1[2] > v2[2];
        }
    };
    
    int minimumCost(int n, vector<vector<int>>& connections) {
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
        auto djs = DisjointSet(n);
        for (auto& con : connections) {
            pq.push(con);
        }
        int result = 0;
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            if (djs.isConnected(cur[0] - 1, cur[1] - 1)) continue;
            else {
                djs.unionSets(cur[0] - 1, cur[1] - 1);
                result += cur[2];
            }
        }
        if (djs.max_size != n) return -1;
        return result;
    }
    
    int minimumCost1(int n, vector<vector<int>>& connections) {
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
        int re = 0;
        vector<vector<vector<int>>> adjGraph(n + 1, vector<vector<int>>());
        for (auto& con : connections) {
            adjGraph[con[0]].push_back({con[1], con[2]});
            adjGraph[con[1]].push_back({con[0], con[2]});
            if (con[0] == 1) pq.push({con[1], con[2]});
            if (con[1] == 1) pq.push({con[0], con[2]});
        }
        vector<bool> visited(n + 1, false);
        visited[1] = true;
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            if (visited[cur[0]]) continue;
            visited[cur[0]] = true;
            re += cur[1];
            for (auto& e : adjGraph[cur[0]]) pq.push(e);
        }
        
        if (accumulate(visited.begin(), visited.end(), 0) == n) return re;
        return -1;
    }
};
