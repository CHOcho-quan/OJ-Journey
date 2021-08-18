class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        unordered_map<string, int> check;
        // for (auto& word : dictionary) {
        //     check[word] = 0;
        // }
        // for (auto& word : dictionary) {
        //     std::cout << word << ' ' << check[word] << '\n';
        // }
        
        string best = "";
        for (auto& word : dictionary) {
            auto l = word.length();
            for (auto& al : s) {
                if (check[word] < l && word[check[word]] == al) ++check[word];
            }
            auto lb = best.length();
            if (check[word] == l) {
                if (lb < l) best = word;
                else if (lb == l) {
                    best = best < word ? best : word;
                }
            }
        }
        
        // for (auto& word : dictionary) {
        //     std::cout << word << ' ' << check[word] << '\n';
        // }
        
        return best;
    }
};
