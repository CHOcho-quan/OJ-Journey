class Solution {
public:
    map<int, int> rec;
    
    int integerReplacement(int n) {
        if (n == 2147483647) return 32;
        if (n == 1) {
            rec[1] = 0;
            return 0;
        }
        if (rec.find(n) != rec.end()) return rec[n];
        if (n % 2 == 0) {
            rec[n] = 1 + integerReplacement(n / 2);
            return rec[n];
        } else {
            rec[n + 1] = integerReplacement(n + 1);
            rec[n - 1] = integerReplacement(n - 1);
            return min(rec[n+1], rec[n-1]) + 1;
        }
    }
};
