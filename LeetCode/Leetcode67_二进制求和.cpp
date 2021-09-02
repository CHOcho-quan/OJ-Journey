class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int cnt = 0, add = 0, len1 = a.length(), len2 = b.length();
        string result = "";
        while (cnt < min(len1, len2)) {
            int s1 = a[cnt] - '0', s2 = b[cnt] - '0';
            result += static_cast<char>((s1 + s2 + add) % 2) + '0';
            add = (s1 + s2 + add) / 2;
            ++cnt;
        }
        
        if (len1 == len2) {
            if (add) result += '1';
        } else if (len1 > len2) {
            while (cnt < len1) {
                int s1 = a[cnt] - '0';
                result += static_cast<char>((s1 + add) % 2) + '0';
                add = (s1 + add) / 2;
                ++cnt;
            }
            if (add) result += '1';
        } else {
            while (cnt < len2) {
                int s1 = b[cnt] - '0';
                result += static_cast<char>((s1 + add) % 2) + '0';
                add = (s1 + add) / 2;
                ++cnt;
            }
            if (add) result += '1';
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
