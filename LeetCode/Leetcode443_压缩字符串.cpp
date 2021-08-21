class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.size() == 0) return 0;
        if (chars.size() == 1) return 1;
        
        char last = chars[0];
        int cur = 1, cnt = 1;
        while (cur < chars.size()) {
            if (last == chars[cur]) {
                ++cnt;
                chars.erase(chars.begin() + cur);
            } else {
                last = chars[cur];
                if (cnt == 1) {
                    ++cur;
                    continue;
                }
                else {
                    string num = std::to_string(cnt);
                    for (auto& n : num) {
                        chars.insert(chars.begin() + cur, n);
                        ++cur;
                    }
                }
                ++cur;
                cnt = 1;
            }
        }
        if (cnt != 1) {
            string num = std::to_string(cnt);
            for (auto& n : num) {
                chars.push_back(n);
            }
        }
        return chars.size();
    }
};
