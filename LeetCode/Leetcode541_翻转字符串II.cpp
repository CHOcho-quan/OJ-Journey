class Solution {
public:
    string reverseStr(string s, int k) {
        bool reflag = true;
        int cnt = 0, len = s.length();
        for (int i = 0; i < len; i+=k) {
            if (reflag) {
                // reversing i to i + k - 1 or i to s.length() - 1
                int st = i, en =
                i + k - 1 > len - 1 ? len - 1 : i + k - 1;
                while (st <= en) {
                    swap(s[st++], s[en--]);
                }
            }
            reflag = !reflag;
        }
        return s;
    }
    
    string reverseStr1(string s, int k) {
        string result = "", tmp = "";
        int cnt = 0;
        bool reflag = true;
        
        for (auto & si : s) {
            ++cnt;
            if (reflag) {
                tmp = si + tmp;
            } else {
                tmp += si;
            }
            if (cnt == k) {
                reflag = !reflag;
                result += tmp;
                tmp = "";
                cnt = 0;
            }
        }
        result += tmp;
        return result;
    }
};
