class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int len1 = matrix.size(), len2 = matrix[0].size();
        // std::cout << "len1: " << len1 << ", len2: " << len2 << '\n';
        for (int i = 0; i < len1 + len2 - 2; ++i) {
            int y = i + 1 - len1 >= 0 ? i + 1 - len1 : 0, x = len1 - 1 - i >= 0 ? len1 - 1 - i : 0;
            // std::cout << x << ' ' << y << '\n';
            int now = matrix[x][y];
            for (int j = 0; j < min(len1, len2); ++j) {
                if (x + j < len1 && y + j < len2 && matrix[x + j][y + j] != now) return false;
            }
        }
        
        return true;
    }
};
