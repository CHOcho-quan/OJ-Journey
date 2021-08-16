class Solution {
private:
    int count = 0;
    int result = 0;
public:
    int countA(const int t, const int n, vector<bool>& nl) {
        // t for t-level, n for total N, nl for left available numbers
        if (t == n) {
            auto iter = find(nl.begin(), nl.end(), true);
            if (iter != nl.end()) {
                int i = iter - nl.begin() + 1;
                if (!(t % i) || !(i % t)) return 1;
                else return 0;
            }
            else return 0;
        }
        int sub_res = 0;
        for (int i = 1; i < n+1; ++i) {
            if (nl[i-1] && (!(t % i) || !(i % t))) {
                nl[i-1] = false;
                // std::cout << "Level " << t << " Choosing " << i;
                sub_res += countA(t+1, n, nl);
                nl[i-1] = true;
            }
        }
        return sub_res;
    }
    int countArrangement(int n) {
        int result = 0, t = 1;
        auto nl = vector<bool>(n, true);
        result = countA(t, n, nl);
        return result;
    }
};
