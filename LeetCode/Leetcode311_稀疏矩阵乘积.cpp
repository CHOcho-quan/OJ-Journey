class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int m = mat1.size(), k = mat2.size(), n = mat2[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // r(ij) = \sum_{t = 1}^{k}a(it) * b(tj)
                for (int t = 0; t < k; ++t) {
                    res[i][j] += mat1[i][t] * mat2[t][j];
                }
            }
        }
        
        return res;
    }
};
