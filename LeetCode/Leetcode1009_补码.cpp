class Solution {
public:
    int bitwiseComplement(int num) {
        if (num == 0) return 1;
        int re = 0, cnt = 0;
        while (num > 0) {
            auto cur = num & 1;
            re += !cur << cnt++;
            num >>= 1;
        }
        return re;
    }
};
