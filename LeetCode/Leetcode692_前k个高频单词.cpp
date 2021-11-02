class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> cnt;
        int max_size = 0;
        for (auto& word : words) {
            ++cnt[word];
            max_size = max(max_size, cnt[word]);
        }
        vector<vector<string>> bucket(max_size + 1, vector<string>());
        for (auto iter : cnt) {
            bucket[iter.second].push_back(iter.first);
        }
        vector<string> result;
        for (int i = max_size; i >= 0; --i) {
            if (bucket[i].size()) {
                sort(bucket[i].begin(), bucket[i].end());
                for (auto& w : bucket[i]) {
                    result.push_back(w);
                    if (result.size() == k) break;
                }
            }
            if (result.size() == k) break;
        }
        
        return result;
    }
};
