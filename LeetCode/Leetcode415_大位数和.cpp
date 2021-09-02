class Solution {
public:
    string addStrings(string num1, string num2) {
        int cur = 1, len1 = num1.length(), len2 = num2.length(), add = 0;
        string result;
        
        for (; cur <= min(len1, len2); ++cur) {
            int n1 = num1[len1 - cur] - '0', n2 = num2[len2 - cur] - '0';
            result = static_cast<char>((n1 + n2 + add) % 10 + '0') + result;
            add = (n1 + n2 + add) / 10;
        }
        
        if (len1 == len2) {
            if (add) result = static_cast<char>(add + '0') + result;
        } else if (len1 > len2) {
            while (cur <= len1) {
                int n1 = num1[len1 - cur++] - '0';
                result = static_cast<char>((n1 + add) % 10 + '0') + result;
                add = (n1 + add) / 10;
            }
            if (add) result = static_cast<char>(add + '0') + result;
        } else if (len2 > len1) {
            while (cur <= len2) {
                int n1 = num2[len2 - cur++] - '0';
                result = static_cast<char>((n1 + add) % 10 + '0') + result;
                add = (n1 + add) / 10;
            }
            if (add) result = static_cast<char>(add + '0') + result;
        }
        
        return result;
    }
};
