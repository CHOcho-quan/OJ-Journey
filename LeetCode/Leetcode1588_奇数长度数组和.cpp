class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int len = arr.size(), result = 0, st = 1;
        
        while (st <= len) {
            int l = 0, r = st - 1;
            while (r < len) {
                result += accumulate(arr.begin() + l, arr.begin() + r + 1, 0);
                ++l;
                ++r;
            }
            // cout << result << '\n';
            st += 2;
        }
        return result;
    }
};
