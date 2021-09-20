class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> re;
        for (int i = 0; i <= n; ++i) {
            re.push_back(__builtin_popcount(i));
        }
        return re;
    }
};
