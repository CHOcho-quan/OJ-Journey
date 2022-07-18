class Solution {
public:
    string reverseWords(string s) {
        string res = "", cur = "";
        int cur_ind = 0;
        while (cur_ind < s.length()) {
            if (s[cur_ind] != ' ') {
                cur = cur + s[cur_ind++];
            } else {
                ++cur_ind;
                if (cur == "") continue;
                else {
                    res = ' ' + cur + res;
                    cur = "";
                }
            }
        }
        
        if (cur != "") res = cur + res;
        if (res.length() > 0 && res[0] == ' ') res = res.substr(1, res.length());
        
        return res;
    }
};
