class Solution {
public:
    bool isConcat(unordered_map<string, int> d, string& s, int l, int r) {
        int wlen = d.begin()->first.length();
        for (int i = l; i <= r; i += wlen) {
            auto str = s.substr(i, wlen);
            if (d.count(str) && --d[str] >= 0) {
                continue;
            } else return false;
        }
        return true;
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        int wlen = words[0].length(), wslen = words.size(), slen = s.length();
        int alen = wlen * wslen;
        unordered_map<string, int> check;
        for (auto& w : words) ++check[w];
        vector<int> result;
        
        for (int st = 0; st < s.length(); ++st) {
            if (st + alen - 1 >= s.length()) break;
            if (isConcat(check, s, st, st + alen - 1)) {
                result.push_back(st);
            }
        }
        
        return result;
    }
};
