class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] + 1 < 10) {
                digits[i] += 1;
                return digits;
            } else {
                digits[i] = (digits[i] + 1) % 10;
            }
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
