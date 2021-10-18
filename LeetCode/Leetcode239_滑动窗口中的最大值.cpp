class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        using PII = pair<int, int>;
        priority_queue<PII> pq;
        for (int i = 0; i < k; ++i) {
            pq.push({nums[i], i});
        }
        vector<int> res;
        res.push_back(pq.top().first);
        int cnt = 1;
        for (int i = k; i < nums.size(); ++i) {
            while (!pq.empty() && pq.top().second < cnt) {
                pq.pop();
            }
            pq.push({nums[i], i});
            res.push_back(pq.top().first);
            ++cnt;
        }
        return res;
    }
    
    vector<int> maxSlidingWindow1(vector<int>& nums, int k) {
        map<int, int, greater<int>> rec;
        for (int i = 0; i < k; ++i) {
            ++rec[nums[i]];
        }
        vector<int> res = {(rec.begin()->first)};
        int cur = 0;
        for (int i = k; i < nums.size(); ++i) {
            if (--rec[nums[cur]] == 0) rec.erase(nums[cur]);
            ++cur;
            ++rec[nums[i]];
            res.push_back(rec.begin()->first);
        }
        
        return res;
    }
};
