class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        if (temperatures.size() == 0) return temperatures;
        if (temperatures.size() == 1) {
            vector<int> result = {0};
            return result;
        }
        // tmp is a non-increasing array in temperatures
        vector<int> result, tmp, ind;
        for (int i = 1; i < temperatures.size(); ++i) {
            if (temperatures[i] > temperatures[i - 1]) {
                result.push_back(1);
                for (int j = tmp.size() - 1; j >= 0; --j) {
                    if (temperatures[i] > tmp[j]) {
                        result[ind[j]] = i - ind[j];
                        ind.pop_back();
                        tmp.pop_back();
                    } else break;
                }
            } else {
                tmp.push_back(temperatures[i - 1]);
                ind.push_back(i - 1);
                result.push_back(0);
            }
        }
        
        result.push_back(0);
        
        return result;
    }
};
