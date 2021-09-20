class Solution {
public:
    int findComplement(int num) {
        int re = 0, cnt = 0;
        while (num > 0) {
            auto cur = num & 1;
            re += !cur << cnt++;
            num >>= 1;
        }
        return re;
    }
};
