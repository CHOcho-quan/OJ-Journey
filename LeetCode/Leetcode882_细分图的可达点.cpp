class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int, int>>> g(n);
        for(auto& r : edges){
            r[2] += 1;
            g[r[0]].push_back({r[1],r[2]});
            g[r[1]].push_back({r[0],r[2]});
        }
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>> q;
        
        dist[0] = 0;
        q.push({0,0});
        
        while(!q.empty()){
            auto [d,v] = q.top(); q.pop();
            d = -d;
            if(dist[v] < d) continue;
            for(auto [nv,nd] : g[v]){
                if(d + nd < dist[nv]){
                    dist[nv] = d + nd;
                    q.push({-dist[nv],nv});
                }
            }
        }
        
        // for (auto& d : dist) cout << d << ' ';
        // cout << '\n';
        
        int result = 1; // for 0
        unordered_set<int> check = {0};
        for (auto& e : edges) {
            // cout << result << ' ';
            if (e[0] == 0) {
                if (e[2] <= maxMoves) {
                    result += e[2];
                    if (check.count(e[1])) --result;
                    else check.insert(e[1]);
                } else {
                    result += maxMoves;
                    if (dist[e[1]] > maxMoves) continue;
                    else if (dist[e[1]] == maxMoves) ++result;
                    else {
                        ++result;
                        result += min((e[2] - 1 - maxMoves), (maxMoves - dist[e[1]]));
                    }
                    if (check.count(e[1])) --result;
                    else check.insert(e[1]);
                }
            } else if (e[1] == 0) {
                if (e[2] <= maxMoves) {
                    result += e[2];
                    if (check.count(e[0])) --result;
                    else check.insert(e[0]);
                } else {
                    result += maxMoves;
                    if (dist[e[0]] > maxMoves) continue;
                    else if (dist[e[0]] == maxMoves) ++result;
                    else {
                        ++result;
                        result += min((e[2] - 1 - maxMoves), (maxMoves - dist[e[0]]));
                    }
                    if (check.count(e[0])) --result;
                    else check.insert(e[0]);
                }
            } else {
                int min_path = min(dist[e[0]], dist[e[1]]),
                max_path = max(dist[e[0]], dist[e[1]]);
                if (min_path == 2147483647) continue;
                if (min_path > maxMoves) {
                    continue;
                } else {
                    result += min(maxMoves - min_path, e[2] - 1);
                    if (max_path < maxMoves) {
                        result += min(e[2] - 1 - min(maxMoves - min_path, e[2] - 1), maxMoves - max_path);
                    }
                    if (max_path <= maxMoves) {
                        if (!check.count(e[0])) {
                            ++result;
                            check.insert(e[0]);
                        }
                        if (!check.count(e[1])) {
                            ++result;
                            check.insert(e[1]);
                        }
                    } else {
                        if (min_path == dist[e[0]] && !check.count(e[0])) {
                            ++result;
                            check.insert(e[0]);
                        }
                        if (min_path == dist[e[1]] && !check.count(e[1])) {
                            ++result;
                            check.insert(e[1]);
                        }
                    }
                }
            }
        }
        return result;
    }
};
