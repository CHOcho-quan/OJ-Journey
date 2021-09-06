class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t re = 0, cnt = 31;
        while (n != 0) {
            re += n % 2 * pow(2, cnt--);
            n /= 2;
        }
        return re;
    }
};
