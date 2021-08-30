class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(),
             [](const vector<int>& v1, const vector<int>& v2) {
                 return v1[1] < v2[1];
             });
        int high = pairs[0][1], result = 1;
        for (int i = 0; i < pairs.size(); ++i) {
            if (pairs[i][0] > high) {
                high = pairs[i][1];
                ++result;
            }
        }
        
        return result;
    }
};
