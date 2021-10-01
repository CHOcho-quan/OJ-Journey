class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        set<string> st;
        for (auto& p : paths) for (auto& pi : p) st.insert(pi);
        for (auto& p : paths) st.erase(p[0]);
        return *(st.begin());
    }
};
