class Solution {
public:
    string decodeString(string s) {
        string cur_num = "";
        string res = "";
        
        stack<string> st;
        for (int i = 0; i < s.length(); ++i) {
            string si = "";
            si += s[i];
            if (si >= "0" && si <= "9") {
                cur_num += si;
            } else if (si == "[") {
                st.push(cur_num);
                st.push(si);
                cur_num = "";
            } else if (si == "]") {
                string tmp = "", nrec = "";
                while (!st.empty()) {
                    auto cur = st.top();st.pop();
                    if (cur != "[") {
                        tmp = cur + tmp;
                    } else {
                        cur = st.top();st.pop();
                        for (int i = 0; i < stoi(cur); ++i) nrec += tmp;
                        break;
                    }
                }
                if (!st.empty()) st.push(nrec);
                else res += nrec;
            } else {
                if (st.empty()) res += si;
                else {
                    st.push(si);
                }
            }
        }
        return res;
    }
};
