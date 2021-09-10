class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> result;
        int l1 = 0, l2 = 0;
        while (l1 != firstList.size() && l2 != secondList.size()) {
            auto f1 = firstList[l1];
            auto f2 = secondList[l2];
            if (f1[0] > f2[1]) {
                ++l2;
            } else if (f1[1] < f2[0]) {
                ++l1;
            } else {
                result.push_back({max(f1[0], f2[0]), min(f1[1], f2[1])});
                if (f1[1] < f2[1]) ++l1;
                else ++l2;
            }
        }
        
        return result;
    }
};
