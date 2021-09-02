// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        // srand(time(nullptr));
        int f = rand7();
        while (f == 6 || f == 7) f = rand7();
        int t = rand7();
        while (t != 6 && t != 7) t = rand7();
        if (t == 6) return f;
        return f + 5;
    }
};
