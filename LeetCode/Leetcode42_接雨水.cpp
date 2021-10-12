class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        
        int res = 0;
        for (int i = 0; i < height.size(); ++i) {
            auto h = height[i];
            if (st.empty()) {
                if (h != 0) st.push(i);
                continue;
            }
            
            int cur = height[st.top()], ind = st.top();
            if (h < cur) st.push(i);
            else {
                int bar = cur;
                while (h >= cur) {
                    res += (cur - bar) * (i - ind - 1);
                    bar = cur;
                    st.pop();
                    if (!st.empty()) {
                        ind = st.top();
                        cur = height[ind];
                    } else break;
                }
                if (cur > h) res += (h - bar) * (i - ind - 1);
                st.push(i);
                // cout << res << '\n';
            }
        }
        
        return res;
    }
};
