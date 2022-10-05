class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        vector<int> available;
        int res = 0;
        for (int i = k; i >= 1; --i) {
            res += cardPoints[cardPoints.size() - i];
            available.push_back(cardPoints[cardPoints.size() - i]);
        }
        cout << res;
        for (int i = 0; i < k; ++i) {
            available.push_back(cardPoints[i]);
        }

        int cur = res;
        for (auto a : available) cout << a << ' ';
        for (int i = k; i < available.size(); ++i) {
            // cout << available[i] << ' ';
            cur -= available[i - k];
            cur += available[i];
            res = max(res, cur);
        }

        return res;
    }
};