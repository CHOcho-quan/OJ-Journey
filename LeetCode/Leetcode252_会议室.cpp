class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        int cur = 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& v1, const vector<int>& v2) {
            return v1[0] < v2[0];
        });
        
        for (auto& interval : intervals) {
            int st = interval[0], en = interval[1];
            if (cur > st) return false;
            cur = en;
        }
        
        return true;
    }
};
