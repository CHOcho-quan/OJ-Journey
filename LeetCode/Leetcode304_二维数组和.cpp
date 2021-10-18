// class NumMatrix {
// public:
//     NumMatrix(vector<vector<int>>& matrix)
//         : row_prefix_(matrix.size(), vector<int>(matrix[0].size() + 2, 0)) {
//         for (int i = 0; i < matrix.size(); ++i) row_prefix_[i][1] = matrix[i][0];
//         for (int i = 0; i < matrix.size(); ++i) {
//             for (int j = 1; j < matrix[i].size(); ++j) {
//                 row_prefix_[i][j + 1] = row_prefix_[i][j] + matrix[i][j];
//             }
//         }
//         for (int i = 0; i < matrix.size(); ++i)
//             row_prefix_[i][matrix[0].size() + 1] = row_prefix_[i][matrix[0].size()];
//     }

//     int sumRegion(int row1, int col1, int row2, int col2) {
//         int res = 0;
//         for (int i = row1; i <= row2; ++i) {
//             res += row_prefix_[i][col2 + 1] - row_prefix_[i][col1];
//         }

//         return res;
//     }
// private:
//     vector<vector<int>> row_prefix_;
// };

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix)
    : prefix_(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0)) {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                prefix_[i + 1][j + 1] = prefix_[i + 1][j] + prefix_[i][j + 1] - prefix_[i][j] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefix_[row2 + 1][col2 + 1] - prefix_[row2 + 1][col1] - prefix_[row1][col2 + 1] + prefix_[row1][col1];
    }
private:
    vector<vector<int>> prefix_;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
