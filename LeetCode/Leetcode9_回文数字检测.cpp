class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        
        vector<int> st;
        while (x != 0) {
            st.push_back(x % 10);
            x /= 10;
        }
        
        int l = 0, r = st.size() - 1;
        while (l < r) {
            if (st[l++] != st[r--]) return false;
        }
        return true;
    }
};
