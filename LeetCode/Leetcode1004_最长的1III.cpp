class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        deque<int> rec;
        int result = 0, cur = 0, fin = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                ++result;
                ++cur;
            } else {
                if (k != 0) {
                    if (cur) rec.push_back(cur + 1);
                    else rec.push_back(1);
                    --k; ++result;
                    cur = 0;
                } else {
                    if (rec.empty()) {
                        result = 0;
                        continue;
                    }
                    result -= rec.front();
                    rec.pop_front();
                    ++result;
                    if (cur) rec.push_back(cur + 1);
                    else rec.push_back(1);
                    cur = 0;
                }
            }
            fin = max(result, fin);
        }
        
        return fin;
    }
};
