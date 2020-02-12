class Solution {
public:
    vector<int> trib = {0, 1, 1};
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 1;
        if (n >= trib.size()) {
            int new_num = tribonacci(n-3) + tribonacci(n-2) + tribonacci(n-1);
            trib.push_back(new_num);
            return trib[n];
        }
        else return trib[n];
    }
};
