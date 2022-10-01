class Solution {
public:
    int shortestWay(string source, string target) {
        unordered_map<char, set<int>> char2ind;
        for (int i = 0; i < source.length(); ++i) char2ind[source[i]].insert(i);
        
        int res = 0, record = -1, cnt = 0;
        for (int i = 0; i < target.length(); ++i) {
            auto iter = char2ind[target[i]].upper_bound(record);
            if (iter == char2ind[target[i]].end() && record == -1) return -1;
            else if (iter == char2ind[target[i]].end() && record != -1) {
                record = -1;
                ++res;
                iter = char2ind[target[i]].upper_bound(record);
                if (iter == char2ind[target[i]].end()) return -1;
            }
            
            record = *iter;
        }
        
        return ++res;
    }
};