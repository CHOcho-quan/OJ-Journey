class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        return __builtin_ffs(n) % 2 && __builtin_popcount(n) == 1;
    }
};
