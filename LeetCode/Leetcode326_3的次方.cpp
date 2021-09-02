class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 1) return true;
        int i = 3;
        while (i <= n) {
            if (n % 3) return false;
            n /= 3;
        }
        return 1==n;
    }
};
