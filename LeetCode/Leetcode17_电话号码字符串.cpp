class Solution {
public:
    void backtrack(string& tmp, vector<string>& result,
                   unordered_map<char, vector<char>> check, string digits, int first) {
        if (first == digits.size()) {
            result.push_back(tmp);
            return;
        }
        
        for (auto& c : check[digits[first]]) {
            tmp += c;
            backtrack(tmp, result, check, digits, first + 1);
            tmp.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) return {};
        unordered_map<char, vector<char>>
        check = {{'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}}, {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}}, {'6', {'m', 'n', 'o'}}, {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}}};
        vector<string> result;
        string tmp;
        backtrack(tmp, result, check, digits, 0);
        return result;
    }
};
