class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int result = 0;
        for (int i = 31; i >= 0; --i) {
            if ((left & (1 << i)) && (right & (1 << i))) {
                result += (1 << i);
            } else if ((left & (1 << i)) == (right & (1 << i))) continue;
            else break;
        }
        return result;
    }
};
