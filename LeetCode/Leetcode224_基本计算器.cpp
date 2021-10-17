class Solution {
public:
    int calculate(string s) {
        stack<string> st;
        // cout << "=============" << s << "=============\n";
        for (int i = 0; i < s.length(); ++i) {
            auto si = s[i];
            // if (!st.empty()) cout << st.top() << ' ' << si << '\n';
            if (si == ' ') continue;
            if (si >= '0' && si <= '9') {
                if (st.empty()) {
                    string tmp = ""; tmp += si;
                    st.push(tmp);
                    continue;
                }
                auto cur = st.top();
                if (cur.length() == 1 && (cur[0] > '9' || cur[0] < '0')) {
                    // DO Calculation and push back
                    string tmp = ""; tmp += si;
                    if (cur[0] == '(') st.push(tmp);
                    else {
                        st.pop();
                        // Get the second operand
                        ++i;
                        while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
                            tmp += s[i++];
                            // cout << "======" << tmp << '\n';
                        }
                        --i;
                        string op1 = st.top(); st.pop();
                        if (cur[0] == '-') {
                            // cout << op1 << ' ' << tmp << "CHECK\n";
                            int num = stoi(op1) - stoi(tmp);
                            st.push(to_string(num));
                            // cout << st.top() << "CALRE\n";
                        } else if (cur[0] == '+') {
                            // cout << op1 << ' ' << tmp << "CHECK\n";
                            st.push(to_string(stoi(op1) + stoi(tmp)));
                            // cout << st.top() << "CALRE\n";
                        }
                    }
                } else {
                    st.pop();
                    cur += si;
                    st.push(cur);
                }
            }
            if (si == '+' || si == '-') {
                string tmp = ""; tmp += si;
                if (!st.empty() && st.top().length() == 1 && (st.top() < "0" || st.top() > "9") && si == '-') {
                    auto cur = st.top(); st.pop();
                    // cout << cur << ' ' << st.top() << '\n';
                    if (cur == "-") {
                        st.push("+");
                    } else if (cur == "+") {
                        st.push("-");
                    } else if (cur == "(") {
                        st.push("(");
                        st.push("0");
                        st.push("-");
                    }
                    continue;
                }
                if (st.empty()) {
                    st.push("0");
                    st.push(tmp);
                    continue;
                }
                st.push(tmp);
            }
            if (si == '(') {
                string tmp = ""; tmp += si;
                st.push(tmp);
            }
            if (si == ')') {
                string cur = "";
                while (st.top() != "(") {
                    cur = st.top() + cur; st.pop();
                    // cout << cur << "CHEKJ\n";
                }
                st.pop();
                // cout << cur << '\n';
                auto op2 = to_string(calculate(cur));
                if (st.empty() || st.top() == "(") {
                    st.push(op2);
                    continue;
                }
                cur = op2;
                while (!st.empty() && st.top() != "(") {
                    cur = st.top() + cur; st.pop();
                }
                st.push(to_string(calculate(cur)));
                // cout << "NEXT2: " << op2 << '\n';
            }
        }
        if (st.size() > 1) {
            string cur = "";
            while (!st.empty()) {
                cur = st.top() + cur; st.pop();
            }
            // cout << "NEXT: " << cur << '\n';
            return calculate(cur);
        }
        return stoi(st.top());
    }
};
