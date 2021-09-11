class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int len1 = matrix.size(), len2 = matrix[0].size();
        int m1 = len1 / 2, m2 = len2 / 2, col, row;
        if (matrix[m1][m2] == target) return true;
        bool flag = matrix[m1][m2] > target, f2 = flag;
        while (flag == f2) {
            // cout << m1 << ' ' << m2;
            if (flag) {
                m1--;m2--;
                if (m1 < 0 || m2 < 0) break;
                if (matrix[m1][m2] == target) return true;
                flag = matrix[m1][m2] > target;
            } else {
                m1++;m2++;
                if (m1 >= len1 || m2 >= len2) break;
                if (matrix[m1][m2] == target) return true;
                flag = matrix[m1][m2] > target;
            }
        }
        // cout << m1 << ' ' << m2;
        if (f2) {
            if (m1 < 0 && m2 < 0) return false;
            else if (m1 < 0 || m2 < 0) {
                ++m1;++m2;
            }
            col = m2, row = m1;
            for (int i = 0; i <= row; ++i) {
                for (int j = col; j < len2; ++j) {
                    if (matrix[i][j] == target) return true;
                }
            }
            for (int i = row; i < len1; ++i) {
                for (int j = 0; j <= col; ++j) {
                    if (matrix[i][j] == target) return true;
                }
            }
            return false;
        } else {
            if (m1 >= len1 && m2 >= len2) return false;
            else if (m1 >= len1 || m2 >= len2) {
                --m1;--m2;
            }
            col = m2, row = m1;
            for (int i = 0; i <= row; ++i) {
                for (int j = col; j < len2; ++j) {
                    if (matrix[i][j] == target) return true;
                }
            }
            for (int i = row; i < len1; ++i) {
                for (int j = 0; j <= col; ++j) {
                    if (matrix[i][j] == target) return true;
                }
            }
            return false;
        }
        return false;
    }
};
