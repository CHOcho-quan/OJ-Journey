class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<vector<int>> helper(intervals.size(), vector<int>());
        for (int i = 0; i < intervals.size(); ++i) {
            helper[i].push_back(intervals[i][0]);
            helper[i].push_back(intervals[i][1]);
            helper[i].push_back(i);
        }
        sort(helper.begin(), helper.end());
        vector<int> result(helper.size(), 0);
        for (int i = 0; i < helper.size(); ++i) {
            int en = helper[i][1], ind = helper[i][2];
            
            int l = i, r = helper.size() - 1, res = -1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (helper[mid][0] < en) {
                    l = mid + 1;
                } else {
                    res = mid;
                    r = mid - 1;
                }
            }
            // if (res != -1) cout << ind << ' ' << res << ' ' << helper[res][2] << '\n';
            if (res != -1) result[ind] = helper[res][2];
            else result[ind] = -1;
            // cout << ind << ' ' << result[ind] << '\n';
        }
        // for (auto& r : result) cout << r << ' ';
        
        return result;
    }
};
