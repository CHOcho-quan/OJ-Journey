class Solution {
public:
    void dfs(vector<vector<int>>& h,
             vector<vector<bool>>& p,
             vector<vector<bool>>& a,
             vector<vector<bool>>& v,
             int i,
             int j) {
        if (i < 0 || j < 0 || i >= h.size() || j >= h[0].size()) return;
        
        // parcific
        if (i == 0 || j == 0) {
            p[i][j] = true;
        }
        // atlantic
        if (i == h.size() - 1 || j == h[0].size() - 1) {
            a[i][j] = true;
        }
        
        v[i][j] = true;
        // Parcific
        if (i - 1 >= 0 && h[i][j] >= h[i-1][j]) {
            if (!v[i-1][j]) { dfs(h, p, a, v, i - 1, j); }
            p[i][j] = p[i-1][j] || p[i][j];
            a[i][j] = a[i-1][j] || a[i][j];
            if (h[i-1][j] == h[i][j]) {
                p[i-1][j] = p[i-1][j] || p[i][j];
                a[i-1][j] = a[i-1][j] || a[i][j];
            }
        }
        if (j - 1 >= 0 && h[i][j] >= h[i][j-1]) {
            if (!v[i][j-1]) { dfs(h, p, a, v, i, j - 1); }
            p[i][j] = p[i][j-1] || p[i][j];
            a[i][j] = a[i][j-1] || a[i][j];
            if (h[i][j] == h[i][j-1]) {
                p[i][j-1] = p[i][j-1] || p[i][j];
                a[i][j-1] = a[i][j-1] || a[i][j];
            }
        }
        // Atlantic
        if (i + 1 < h.size() && h[i][j] >= h[i+1][j]) {
            if (!v[i+1][j]) { dfs(h, p, a, v, i + 1, j); }
            p[i][j] = p[i+1][j] || p[i][j];
            a[i][j] = a[i+1][j] || a[i][j];
            if (h[i][j] == h[i+1][j]) {
                p[i+1][j] = p[i+1][j] || p[i][j];
                a[i+1][j] = a[i+1][j] || a[i][j];
            }
        }
        if (j + 1 < h[0].size() && h[i][j] >= h[i][j+1]) {
            if (!v[i][j+1]) { dfs(h, p, a, v, i, j + 1); }
            p[i][j] = p[i][j+1] || p[i][j];
            a[i][j] = a[i][j+1] || a[i][j];
            if (h[i][j] == h[i][j+1]) {
                p[i][j+1] = p[i][j+1] || p[i][j];
                a[i][j+1] = a[i][j+1] || a[i][j];
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.size() == 0) return heights;
        
        int l1 = heights.size(), l2 = heights[0].size();
        vector<vector<bool>> p(l1, vector<bool>(l2, false));
        vector<vector<bool>> a(l1, vector<bool>(l2, false));
        vector<vector<bool>> v(l1, vector<bool>(l2, false));
        vector<vector<int>> result;
        for (int i = 0; i < l1; ++i) {
            for (int j = 0; j < l2; ++j) {
                vector<int> tmp = {i, j};
                // std::cout << i << ' ' << j << "==============\n";
                if (p[i][j] && a[i][j]) {
                    result.push_back(tmp);
                    continue;
                }
                dfs(heights, p, a, v, i, j);
                if (p[i][j] && a[i][j]) {
                    result.push_back(tmp);
                }
            }
        }
        
        return result;
    }
};
