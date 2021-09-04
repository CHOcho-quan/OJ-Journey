class Solution {
public:
    vector<string> result;
    
    void backtrack(string& s, string& tmp, int cur) {
        if (tmp.length() == s.length()) {
            result.push_back(tmp);
            return;
        }
        
        if (s[cur] >= 'a' && s[cur] <= 'z') {
            tmp += s[cur];
            backtrack(s, tmp, cur + 1);
            tmp.pop_back();
            tmp += s[cur] - 'a' + 'A';
            backtrack(s, tmp, cur + 1);
            tmp.pop_back();
        } else if (s[cur] >= 'A' && s[cur] <= 'Z') {
            tmp += s[cur];
            backtrack(s, tmp, cur + 1);
            tmp.pop_back();
            tmp += s[cur] - 'A' + 'a';
            backtrack(s, tmp, cur + 1);
            tmp.pop_back();
        } else {
            tmp += s[cur];
            backtrack(s, tmp, cur + 1);
            tmp.pop_back();
        }
    }
    
    vector<string> letterCasePermutation(string s) {
        string tmp = "";
        backtrack(s, tmp, 0);
        return result;
    }
};
