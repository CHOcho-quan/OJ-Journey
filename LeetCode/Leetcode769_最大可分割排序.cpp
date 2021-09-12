class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = 0, result = 0, cur = 0;
        while (n < arr.size()) {
            // cout << "Finding " << n << ' ' << arr[n] << ' ' << result << '\n';
            if (n == arr[n] && cur == n) {
                ++result;
                ++n;
                ++cur;
            } else {
                int to = arr[n];
                bool flag = true;
                if (to > n) {
                    for (int i = cur; i <= to; ++i) {
                        if (arr[i] < cur || arr[i] > to) flag = false;
                    }
                } else {
                    // cout << to << ' ' << n;
                    for (int i = cur; i <= n; ++i) {
                        // cout << ' ' << arr[i];
                        if (arr[i] < cur || arr[i] > n) flag = false;
                        // cout << ' ' << flag << '\n';
                    }
                }
                if (flag) {
                    ++result;
                    cur = max(to, n) + 1;
                }
                if (to > n) n = to + 1;
                else ++n;
            }
        }
        return max(result, 1);
    }
};
