class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int res = 0;
        for (auto& ai : arr1) {
            auto i1 = std::lower_bound(arr2.begin(), arr2.end(), ai - d);
            auto i2 = std::upper_bound(arr2.begin(), arr2.end(), ai + d);
            res += (i1 == i2);
        }
        
        return res;
    }
};
