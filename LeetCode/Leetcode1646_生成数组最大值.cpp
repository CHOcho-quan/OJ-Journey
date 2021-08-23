class Solution {
public:
    int getMaximumGenerated(int n) {
        std::vector<int> generated(n+1, 0);
        if (n == 0) return 0;
        
        generated[1] = 1;
        int result = 1;
        for (int i = 1; i <= n / 2; ++i) {
            generated[2 * i] = generated[i];
            if (2 * i + 1 < n + 1) {
                generated[2 * i + 1] = generated[i] + generated[i + 1];
                result = max(generated[2 * i + 1], result);
            }
        }
        
        return result;
    }
};
