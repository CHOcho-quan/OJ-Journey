class Solution {
public:
    vector<int> direction = {-1, 0, 1, 0, -1};
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<bool>> visited(mat.size(), vector<bool>(mat[0].size(), false));
        vector<vector<int>> result = mat;
        queue<pair<int, int>> q;
        for (int i = 0; i < mat.size(); ++i) {
            for (int j = 0; j < mat[i].size(); ++j) {
                if (!mat[i][j]) {
                    q.push(pair<int, int>(i, j));
                    visited[i][j] = true;
                }
            }
        }
        
        int cur = 0;
        while (!q.empty()) {
            int len = q.size();
            // std::cout << len << ' ' << cur << "===========\n";
            while (len--) {
                auto f = q.front();
                // std::cout << f.first << ' ' << f.second << '\n';
                q.pop();
                result[f.first][f.second] = cur;
                for (int i = 0; i < 4; ++i) {
                    int ind1 = f.first + direction[i], ind2 = f.second + direction[i + 1];
                    if (ind1 >= 0 && ind2 >= 0 &&
                        ind1 < mat.size() && ind2 < mat[0].size() &&
                        !visited[ind1][ind2]) {
                        visited[ind1][ind2] = true;
                        q.push(pair<int, int>(ind1, ind2));
                    }
                }
            }
            ++cur;
        }
        
        return result;
    }
};
