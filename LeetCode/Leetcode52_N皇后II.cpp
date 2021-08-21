class Solution {
public:
    int result = 0;
    
    void backtrace(vector<bool>& col,
                   vector<bool>& ldiag,
                   vector<bool>& rdiag,
                   int n, int level) {
        if (level == n) {
            ++result;
            return;
        }
        
        for (int i = 0; i < n; ++i) {
            if (col[i] || ldiag[i + level] || rdiag[level - i + n - 1]) continue;
            
            col[i] = ldiag[i + level] = rdiag[level - i + n -1] = true;
            backtrace(col, ldiag, rdiag, n, level + 1);
            col[i] = ldiag[i + level] = rdiag[level - i + n -1] = false;
        }
    }
    
    int totalNQueens(int n) {
        vector<bool> col(n, false), ldiag(2*n-1, false), rdiag(2*n-1, false);
        backtrace(col, ldiag, rdiag, n, 0);
        return result;
    }
};
