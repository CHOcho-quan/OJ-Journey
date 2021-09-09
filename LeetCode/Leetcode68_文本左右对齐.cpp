class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        string w = "";
        vector<string> re;
        int t = 0;
        vector<int> cnt = {0};
        for (int i = 0; i < words.size(); ++i) {
            w += words[i];
            ++cnt[t];
            if (i == words.size() - 1) {
                re.push_back(w);
                break;
            }
            if (w.length() + 1 + words[i + 1].length() <= maxWidth) {
                w += ' ';
            } else {
                if (cnt[t] == 1 && w.length() != maxWidth) w += ' ';
                re.push_back(w);
                w = "";
                cnt.push_back(0);
                ++t;
            }
        }
        
        vector<string> result;
        for (int i = 0; i < re.size() - 1; ++i) {
            int kg = cnt[i] - 1;
            int adding = 1, ext = 0;
            if (kg == 0) {
                adding = maxWidth - re[i].length();
            }
            else {
                int each = (maxWidth - re[i].length()) / kg;
                ext = (maxWidth - re[i].length()) % kg;
                adding = each + (ext != 0);
            }
            string cur = "";
            for (auto& s : re[i]) {
                if (s != ' ') cur += s;
                else {
                    cur += s;
                    int cura = adding;
                    while (cura--) cur += s;
                    if (--ext == 0)
                        adding -= 1;
                }
            }
            result.push_back(cur);
        }
        
        while (re[re.size() - 1].length() != maxWidth) re[re.size() - 1] += ' ';
        result.push_back(re[re.size() - 1]);
        
        // for (auto& w : re) cout << w << 'w' << '\n';
        // for (auto& t : cnt) cout << t << ' ';
        return result;
    }
};
