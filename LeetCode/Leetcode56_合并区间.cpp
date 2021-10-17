class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& v1, const vector<int>& v2) {
            return v1[0] < v2[0];
        });
        
        int curst = -1, curen = -1;
        for (auto& interval : intervals) {
            if (curst == -1 && curen == -1) {
                curst = interval[0], curen = interval[1];
                continue;
            }
            if (interval[0] <= curen) {
                curen = max(interval[1], curen);
            } else {
                res.push_back({curst, curen});
                curst = interval[0];
                curen = interval[1];
            }
        }
        res.push_back({curst, curen});
        return res;
    }
};
