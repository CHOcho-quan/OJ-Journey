class Solution {
public:
    vector<int> direction = {-1, 0, 1, 0, -1};
    
    vector<vector<int>> memo;
    
    int dfs(vector<vector<int>>& matrix, int i, int j) {
        if (memo[i][j]) return memo[i][j];
        
        bool flag = false;
        int round = 1;
        for (int k = 0; k < 4; ++k) {
            int ni = i + direction[k], nj = j + direction[k + 1];
            if (ni < 0 || nj < 0 || ni >= matrix.size() || nj >= matrix[0].size()) continue;
            if (matrix[ni][nj] > matrix[i][j]) {
                if (memo[ni][nj]) round = max(round, memo[ni][nj] + 1);
                else round = max(dfs(matrix, ni, nj) + 1, round);
            }
        }
        
        memo[i][j] = round;
        return round;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        memo = vector<vector<int>>(m, vector<int>(n, 0));
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res = max(dfs(matrix, i, j), res);
            }
        }
        
        return res;
    }
};
