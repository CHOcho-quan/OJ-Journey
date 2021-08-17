class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;
        if (points.size() == 1) return 1;
        
        sort(points.begin(), points.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });
        // for (auto& p : points) {
        //     std::cout << p[0] << ' ' << p[1] << std::endl;
        // }
        auto last_p = points[0];
        int result = 1;
        for (int i = 1; i < points.size(); ++i) {
            auto p = points[i];
            if (p[0] <= last_p[1]) {
                // Overlapped
                last_p[0] = std::max(p[0], last_p[0]);
                last_p[1] = std::min(p[1], last_p[1]);
            } else {
                last_p = p;
                ++result;
            }
        }
        
        return result;
    }
};
