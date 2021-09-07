class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l1 = 0, r1 = matrix.size() - 1, mid1, len1 = r1 + 1, len2 = matrix[0].size();
        
        while (l1 <= r1) {
            mid1 = l1 + (r1 - l1) / 2;
            if (matrix[mid1][0] <= target && target <= matrix[mid1][len2 - 1]) {
                int l2 = 0, r2 = len2 - 1, mid2;
                while (l2 <= r2) {
                    mid2 = l2 + (r2 - l2) / 2;
                    if (matrix[mid1][mid2] == target) return true;
                    else if (matrix[mid1][mid2] > target) {
                        r2 = mid2 - 1;
                    } else {
                        l2 = mid2 + 1;
                    }
                }
                return false;
            } else if (target < matrix[mid1][0]) {
                r1 = mid1 - 1;
            } else {
                l1 = mid1 + 1;
            }
        }
        
        return false;
    }
};
