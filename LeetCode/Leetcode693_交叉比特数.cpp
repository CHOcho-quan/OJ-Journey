class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool flag = false, f2 = !(n & 1);
        while (n > 0) {
            flag = n & 1;
            n >>= 1;
            if (f2 == flag) return false;
            f2 = flag;
        }
        return true;
    }
};
