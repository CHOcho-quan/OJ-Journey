class Solution {
public:
    int hammingWeight(uint32_t n) {
        int re = 0;
        while (n != 0) {
            re += n % 2;
            n /= 2;
        }
        return re;
    }
};
