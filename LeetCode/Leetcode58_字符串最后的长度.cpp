class Solution {
public:
    int lengthOfLastWord(string s) {
        string w = "";
        bool flag = true;
        for (auto& si : s) {
            if (si != ' ') {
                if (flag) w += si;
                else {
                    flag = true;
                    w = "";
                    w += si;
                }
            } else flag = false;
        }
        return w.length();
    }
};
