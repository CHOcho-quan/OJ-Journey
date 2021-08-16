
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(),
                  [&](const vector<int>& a, const vector<int>& b) {
                      return a[0] < b[0];
                  });
        
        size_t i = 0, size_i = intervals.size();
        int result = 0;
        auto last_interval = intervals.begin();
        for (;i < size_i - 1; ++i) {
            if (intervals[i+1][0] < (*last_interval)[1]) {
                // Overlapped
                ++result;
                last_interval =
                (*last_interval)[1] > intervals[i+1][1] ? intervals.begin() + i + 1 : last_interval;
                // std::cout << (*last_interval)[0] << ' ' << (*last_interval)[1] << '\n';
            } else {
                // Not Overlapped
                last_interval = intervals.begin() + i + 1;
                // std::cout << (*last_interval)[0] << ' ' << (*last_interval)[1] << '\n';
            }
        }
        return result;
    }
    
};
