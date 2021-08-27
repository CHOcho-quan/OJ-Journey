class Solution {
public:
    void backtrack(vector<string>& result, string& tmp, int nl, int nr, int cur) {
        // nl for n left left, nr for n right left, cur for cur right - left
        if (nl == 0 && nr == 0) {
            result.push_back(tmp);
            return;
        }
        if (cur == 0) {
            if (nl == 0) return;
            tmp += '(';
            backtrack(result, tmp, nl - 1, nr, cur + 1);
            tmp.pop_back();
            return;
        }
        if (nl != 0) {
            tmp += '(';
            backtrack(result, tmp, nl - 1, nr, cur + 1);
            tmp.pop_back();
        }
        if (nr != 0) {
            tmp += ')';
            backtrack(result, tmp, nl, nr - 1, cur - 1);
            tmp.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> re;
        string tmp = "";
        backtrack(re, tmp, n, n, 0);
        return re;
    }
};
