class Solution {
public:
    int strStr(string haystack, string needle) {
        int l = needle.length(), n = haystack.length();
        if (!l) return 0;
        
        for (int i = 0; i < n - l + 1; ++i) {
            if (haystack.substr(i, l) == needle) return i;
        }
        
        return -1;
    }
};
