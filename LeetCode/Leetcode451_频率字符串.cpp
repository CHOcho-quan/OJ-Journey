class Solution {
public:
    string frequencySort(string s) {
        std::unordered_map<char, int> check;
        
        int max_count = 0;
        for (auto& si : s) {
            ++check[si];
            if (check[si] > max_count) max_count = check[si];
        }
        vector<vector<string>> bucket(max_count + 1, vector<string>());
        
        for (auto& c : check) {
            string tmp(c.second, c.first);
            bucket[c.second].push_back(tmp);
        }
        
        // for (auto& a : bucket) {
        //     std::cout << a.size() << ' ';
        //     for (auto& b : a) {
        //         std::cout << b << ' ';
        //     }
        //     std::cout << '\n';
        // }
        
        string result = "";
        for (int i = bucket.size() - 1; i >= 0; --i) {
            for (int j = 0; j < bucket[i].size(); ++j) {
                result += bucket[i][j];
            }
        }
        
        return result;
    }
};
