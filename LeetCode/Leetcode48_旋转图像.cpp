class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < n - i * 2 - 1; ++j) {
                int ndot = n - 1;
                int tind = j + i;
                int tmp = matrix[i][tind];
                matrix[i][tind] = matrix[ndot - tind][i];
                matrix[ndot - tind][i] = matrix[ndot - i][ndot - tind];
                matrix[ndot - i][ndot - tind] = matrix[tind][ndot - i];
                matrix[tind][ndot - i] = tmp;
            }
        }
    }
};
