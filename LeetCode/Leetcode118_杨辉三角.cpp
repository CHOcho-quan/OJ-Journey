class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1) return {{1}};
        vector<vector<int>> tri = {{1}, {1, 1}};
        for (int i = 3; i <= numRows; ++i) {
            vector<int> tmp;
            tmp.push_back(1);
            for (int j = 1; j <= i - 2; ++j) {
                tmp.push_back(tri[i - 2][j - 1] + tri[i - 2][j]);
            }
            tmp.push_back(1);
            tri.push_back(tmp);
        }
        
        return tri;
    }
};
