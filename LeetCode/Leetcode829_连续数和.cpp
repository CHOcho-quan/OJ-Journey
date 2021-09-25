class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int result = 0;
        for (int i = 1; i <= n; ++i) {
            if (i % 2) {
                if (n % i == 0) {
                    if (n / i > (i - 1) / 2) {
                        // cout << i << " =====ji\n";
                        ++result;
                    } else break;
                }
            } else {
                double check = static_cast<double>(n) / i;
                if (check - n / i == 0.5) {
                    if (check > 0.5 + (i / 2 - 1)) {
                        // cout << i << ' ' << check << " ======ou\n";
                        ++result;
                    }
                }
            }
        }
        
        return result;
    }
    
    int consecutiveNumbersSumDoublePointer(int n) {
        int l = 1, r = 1, sum = 1, result = 0;
        while (r <= n) {
            while (sum < n) {++r; sum += r;}
            if (sum == n) {++result; ++r; sum += r;}
            while (sum > n) {++l; sum -= (l - 1);}
            if (sum == n) {++result; ++l; sum -= (l - 1);}
        }
        
        return result;
    }
    
    int consecutiveNumbersSumTLE(int n) {
        vector<long long> count(n + 1, 0), pre_sum(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            pre_sum[i] = pre_sum[i - 1] + i;
        }
        long long fn = n;
        for (int i = 0; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                long long sum = pre_sum[j] - pre_sum[i];
                if (sum > fn) break;
                else {
                    // cout << i << ' ' << j << ' ' << sum << '\n';
                    ++count[sum];
                }
            }
        }
        return count[n];
    }
};
