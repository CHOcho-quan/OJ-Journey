class Solution {
public:
    int calculate(string s) {
        vector<int> res;
        int op = 1, num = 0;
        char preSign = '+';
        s += '+';
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                string tmp = "";
                while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
                    tmp += s[i++];
                }
                --i;
                num = stoi(tmp);
                // cout << num << "NUM\n";
            } else if (s[i] == ' ') continue;
            else {
                switch (preSign) {
                    case '+': {
                        res.push_back(num);
                        break;
                    }
                    case '-': {
                        res.push_back(-num);
                        break;
                    }
                    case '*': {
                        auto cur = res.back() * num;
                        // cout << res.back() << ' ' << num << '\n';
                        res.pop_back();
                        res.push_back(cur);
                        break;
                    }
                    case '/': {
                        auto cur = res.back() / num;
                        res.pop_back();
                        res.push_back(cur);
                        break;
                    }
                }
                preSign = s[i];
            }
        }
        
        return accumulate(res.begin(), res.end(), 0);
    }
};
