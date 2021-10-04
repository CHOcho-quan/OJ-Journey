class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        for (int i = 0; i < s.length(); ++i) {
            switch (s[i]) {
                case 'I': {
                    if (i != s.length() - 1) {
                        if (s[i + 1] == 'V') {
                            res += 4; ++i;
                        } else if (s[i + 1] == 'X') {
                            res += 9; ++i;
                        } else res += 1;
                    } else res += 1;
                    break;
                }
                case 'V': {
                    res += 5;
                    break;
                }
                case 'X': {
                    if (i != s.length() - 1) {
                        if (s[i + 1] == 'L') {
                            res += 40; ++i;
                        } else if (s[i + 1] == 'C') {
                            res += 90; ++i;
                        } else res += 10;
                    } else res += 10;
                    break;
                }
                case 'L': {
                    res += 50;
                    break;
                }
                case 'C': {
                    if (i != s.length() - 1) {
                        if (s[i + 1] == 'D') {
                            res += 400;
                            ++i;
                        } else if (s[i + 1] == 'M') {
                            res += 900;
                            ++i;
                        } else {
                            res += 100;
                        }
                    } else res += 100;
                    break;
                }
                case 'D': {
                    res += 500;
                    break;
                }
                case 'M': {
                    res += 1000;
                    break;
                }
            }
        }
        
        return res;
    }
};
