class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        struct point {
            int x, y, val;
            point(int xx, int yy, int bval) {
                x = xx;
                y = yy;
                val = bval;
            }
            bool operator>(const point& p2) const {
                return val > p2.val;
            }
        };
        priority_queue<point, vector<point>, greater<point>> pq;
        for (int i = 0; i < matrix.size(); ++i) pq.push(point(i, 0, matrix[i][0]));
        for (int i = 0; i < k - 1; ++i) {
            auto cur = pq.top(); pq.pop();
            if (cur.y + 1 < matrix[0].size())
                pq.push(point(cur.x, cur.y + 1, matrix[cur.x][cur.y + 1]));
        }
        
        return pq.top().val;
    }
    
    int kthSmallest1(vector<vector<int>>& matrix, int k) {
        vector<int> res;
        for (auto& m : matrix) {
            for (auto& mi : m) {
                res.push_back(mi);
            }
        }
        sort(res.begin(), res.end());
        return res[k - 1];
    }
};
