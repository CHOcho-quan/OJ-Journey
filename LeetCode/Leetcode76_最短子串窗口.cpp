class Solution {
public:
    string minWindow(string S, string t) {
        vector<int> chars(128, 0); vector<bool> flag(128, false);
        for(int i = 0; i < t.size(); ++i) {
            flag[t[i]] = true;
            ++chars[t[i]];
        }
        int cnt = 0, l = 0, min_l = 0, min_size = S.size() + 1;
        for (int r = 0; r < S.size(); ++r) {
            if (flag[S[r]]) {
                if (--chars[S[r]] >= 0) {
                    ++cnt;
                }
                while (cnt == t.size()) {
                    if (r - l + 1 < min_size) {
                        min_l = l;
                        min_size = r - l + 1;
                    }
                    if (flag[S[l]] && ++chars[S[l]] > 0) {
                        --cnt;
                    }
                    ++l;
                }
            }
        }
        return min_size > S.size()? "": S.substr(min_l, min_size);
    }
    
    string minWindow1(string s, string t) {
        std::map<char, int> check, ans;
        for (auto& c : t) {
            ++check[c];
            ans[c] = 0;
        }
        // for (auto& c : t) {
        //     std::cout << c << ' ' << check[c] << '\n';
        // }
        int st = 0, en = 0, rlen = 2147483647;
        if (check.count(s[st])) ans[s[st]]++;
        string result = "";
        while (en < s.length()) {
            // First Move st to a start place
            for (int i = st; i < s.length(); ++i) {
                auto c = s[i];
                if (!check.count(c)) continue;
                st = i;
                break;
            }
            if (en == s.length() - 1) {
                bool satisfy = true;
                for (auto iter = check.begin(); iter != check.end(); ++iter) {
                    if (iter->second > ans[iter->first]) {
                        satisfy = false;
                        break;
                    }
                }
                // Get Result
                if (satisfy) {
                    if (en - st + 1 < rlen) {
                        rlen = en - st + 1;
                        result = s.substr(st, rlen);
                    }
                    // std::cout << s.substr(st, en - st + 1);
                } else {
                    break;
                }
            }
            // if (st == s.length() - 1) break;
            // Start Moving en to satisfy
            for (int j = en+1; j < s.length(); ++j) {
                auto c = s[j];
                bool satisfy = true;
                for (auto iter = check.begin(); iter != check.end(); ++iter) {
                    if (iter->second > ans[iter->first]) {
                        satisfy = false;
                        break;
                    }
                }
                // Get Result
                if (satisfy) {
                    if (en - st + 1 < rlen) {
                        rlen = en - st + 1;
                        result = s.substr(st, rlen);
                    }
                    // std::cout << s.substr(st, en - st + 1);
                    break;
                }
                if (!check.count(c)) continue;
                en = j;
                ++ans[c];
            }
            bool satisfy = true;
            for (auto iter = check.begin(); iter != check.end(); ++iter) {
                if (iter->second > ans[iter->first]) {
                    satisfy = false;
                    break;
                }
            }
            // Get Result
            if (satisfy) {
                if (en - st + 1 < rlen) {
                    rlen = en - st + 1;
                    result = s.substr(st, rlen);
                }
                // std::cout << s.substr(st, en - st + 1);
            }
            // std::cout << st << ' ' << en << '\n';
            // for (auto& c : t) {
            //     std::cout << c << ' ' << ans[c] << '\n';
            // }
            // Move st
            --ans[s[st++]];
            if (st >= en) break;
        }
        
        return result;
    }
};
