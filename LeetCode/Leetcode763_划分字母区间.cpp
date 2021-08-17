class Solution {
public:
    vector<int> partitionLabels(string s) {
        std::vector<std::vector<int>> check;
        std::map<char, int> late;
        for (int i = 0; i < s.length(); ++i) {
            if (!late.count(s[i])) {
                vector<int> c = {i, i};
                check.push_back(c);
                late[s[i]] = check.size() - 1;
            } else {
                check[late[s[i]]][1] = i;
            }
        }
        
        auto last_interval = check[0];
        vector<int> result;
        for (int i = 1; i < check.size() ; ++i) {
            if (check[i][0] < last_interval[1]) {
                last_interval[1] = std::max(check[i][1], last_interval[1]);
            } else {
                result.push_back(last_interval[1] - last_interval[0] + 1);
                last_interval = check[i];
            }
        }
        result.push_back(last_interval[1] - last_interval[0] + 1);
        
        return result;
    }
};
