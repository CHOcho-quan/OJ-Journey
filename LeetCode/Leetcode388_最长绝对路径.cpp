class Solution {
public:
    int lengthLongestPath(string input) {
        string result, tmp;
        vector<string> level;
        vector<int> where;
        int cnt = 0;
        input += '\n';
        for (int i = 0; i < input.length(); ++i) {
            if (input[i] == '\n') {
                cnt = 0;
                level.push_back(tmp);
                if (tmp.find('.') != tmp.npos) {
                    string ar = "";
                    for (auto& l : level) {
                        ar += l;
                        ar += '/';
                    }
                    ar.erase(ar.length() - 1);
                    result = result.length() > ar.length() ? result : ar;
                    // std::cout << "AAR: " << ar << ' ' << ar.length() << '\n';
                }
                tmp = "";
            } else if (input[i] == '\t') {
                ++cnt;
            } else {
                while (cnt < level.size()) {
                    level.pop_back();
                }
                tmp += input[i];
            }
        }
        
        return result.length();
    }
};
