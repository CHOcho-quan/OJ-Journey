class Solution {
public:
    bool canPermutePalindrome(string s) {
        int flag = 0;
        std::unordered_map<char, int> check;
        for (auto& si : s) {
            if (++check[si] % 2) ++flag;
            else --flag;
        }
        return flag < 2;
    }
};
