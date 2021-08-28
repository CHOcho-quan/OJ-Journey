class Solution {
public:
    void reverseString(string& s) {
        int l = 0, r = s.length() - 1;
        while (l < r) {
            swap(s[l++], s[r--]);
        }
    }
    
    string reverseWords(string s) {
        string result = "";
        int last = 0;
        string tmp;
        for (int i = 0; i < s.length() + 1; ++i) {
            if (i == s.length()) {
                tmp = s.substr(last, i - last + 1);
                reverseString(tmp);
                result += tmp;
                break;
            }
            if (s[i] == ' ') {
                tmp = s.substr(last, i - last);
                last = i + 1;
                reverseString(tmp);
                result += tmp;
                result += ' ';
            }
        }
        
        return result;
    }
};
