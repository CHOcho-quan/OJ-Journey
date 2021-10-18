class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> res;
        for (int i = 0; i < nums1.size(); ++i) pq.push({nums1[i] + nums2[0], {i, 0}});
        
        while (k-- && !pq.empty()) {
            auto cur = pq.top(); pq.pop();
            res.push_back({nums1[cur.second.first], nums2[cur.second.second]});
            if (cur.second.second + 1 < nums2.size())
                pq.push({nums1[cur.second.first] + nums2[cur.second.second + 1], {cur.second.first, cur.second.second + 1}});
        }
        
        return res;
    }
    
    vector<vector<int>> kSmallestPairs1(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>,
        greater<pair<int, vector<int>>>> pq;
        for (int i = 0; i < min(k, static_cast<int>(nums1.size())); ++i) {
            int n1 = nums1[i];
            for (int j = 0; j < min(k, static_cast<int>(nums2.size())); ++j) {
                int n2 = nums2[j];
                pq.push({n1 + n2, {n1, n2}});
            }
        }
        
        while (k--) {
            if (pq.empty()) break;
            res.push_back(pq.top().second); pq.pop();
        }
        
        return res;
    }
};
