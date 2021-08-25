class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        for (string& e : emails) {
            vector<int> recd;
            int at = 0, plus = -1;
            bool flag = true;
            for (int i = 0; i < e.length(); ++i) {
                auto s = e[i];
                if (s == '@') {
                    at = i;
                    break;
                }
                if (s == '+' && flag) {
                    plus = i;
                    flag = false;
                }
                if (s == '.' && flag) recd.push_back(i);
            }
            if (plus != -1)
                e.erase(e.begin() + plus, e.begin() + at);
            for (int i = recd.size() - 1; i >= 0; --i) {
                e.erase(recd[i], 1);
            }
            // std::cout << e << '\n';
        }
        
        set<string> em(emails.begin(), emails.end());
        
        return em.size();
    }
};
