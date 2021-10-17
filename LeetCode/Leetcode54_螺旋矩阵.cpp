class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0, bottom = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
        vector<int> res;
        int flag = 0;
        int stx = 0, sty = 0;
        for (int i = 0; i < matrix.size() * matrix[0].size(); ++i) {
            switch (flag) {
                case 0: {
                    res.push_back(matrix[stx][sty++]);
                    if (sty > right) {
                        sty = right;
                        ++stx;
                        flag = 1;
                        ++top;
                    }
                    break;
                }
                case 1: {
                    res.push_back(matrix[stx++][sty]);
                    if (stx > bottom) {
                        stx = bottom;
                        --sty;
                        flag = 2;
                        --right;
                    }
                    break;
                }
                case 2: {
                    res.push_back(matrix[stx][sty--]);
                    if (sty < left) {
                        sty = left;
                        --stx;
                        flag = 3;
                        --bottom;
                    }
                    break;
                }
                case 3: {
                    res.push_back(matrix[stx--][sty]);
                    if (stx < top) {
                        stx = top;
                        ++sty;
                        flag = 0;
                        ++left;
                    }
                    break;
                }
            }
        }
        
        return res;
    }
};
