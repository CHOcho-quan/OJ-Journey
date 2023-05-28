class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int res = 0;
        unordered_map<int, int> ans;

        for (auto& answer : answers) {
            if (!ans.count(answer)) {
                ans[answer] = answer;
                res += answer + 1;
                continue;
            }
            if (ans[answer] == 0) {
                res += answer + 1;
                ans[answer] = answer;
                continue;
            }
            --ans[answer];
        }

        return res;
    }
};