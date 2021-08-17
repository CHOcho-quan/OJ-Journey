class Solution {
public:
    bool checkRecord(string s) {
        int absent = 0, late = 0;
        for (auto& t : s) {
            if (t == 'A') {
                if(++absent >= 2) return false;
                late = 0;
            } else if (t == 'L') {
                if (++late >= 3) return false;
            } else {
                late = 0;
            }
        }
        return true;
    }
};
