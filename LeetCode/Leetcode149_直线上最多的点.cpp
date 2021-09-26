class Solution {
public:
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }
    
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() == 1) return 1;
        using PDD = pair<int, int>;
        
        int result = 2;
        for (int i = 0; i < points.size(); ++i) {
            map<PDD, int> rec;
            for (int j = i + 1; j < points.size(); ++j) {
                int x1 = points[i][0], y1 = points[i][1],
                x2 = points[j][0], y2 = points[j][1];
                int k, b;
                if (x1 == x2) {
                    k = INT_MAX;
                    b = x1;
                } else {
                    int gcd1 = gcd(y1 - y2, x1 - x2);
                    k = (y1 - y2) / gcd1;
                    b = (x1 - x2) / gcd1;
                    if (k < 0) {
                        k = -k;
                        b = -b;
                    }
                }
                PDD cur = {k, b};
                if (!rec.count(cur)) rec[cur] = 2;
                else ++rec[cur];
                result = max(result, rec[cur]);
            }
        }
        
        return result;
    }
};
