class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if (finalSum % 2) return vector<long long>();
        vector<long long> res = {2};
        finalSum -= 2;
        bool flag = false;
        long long cur = 2;
        while (finalSum) {
            cur += 2;
            if (finalSum - cur < 0) break;
            else finalSum -= cur;
            res.push_back(cur);
        }
        if (finalSum > 0) res[res.size() - 1] += finalSum;
        return res;
    }
};