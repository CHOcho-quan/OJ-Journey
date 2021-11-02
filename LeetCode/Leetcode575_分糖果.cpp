class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size(), upper = n / 2;
        int res = 0;
        unordered_set<int> candy;
        for (int i = 0; i < candyType.size(); ++i) {
            if (candy.count(candyType[i])) continue;
            candy.insert(candyType[i]);
            ++res;
        }
        return res > upper ? upper : res;
    }
};
