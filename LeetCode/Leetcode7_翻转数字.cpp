class Solution {
public:
    int reverse(int x) {
        bool neg = false;
        if (x < 0) {
            neg = true;
            if (x == -2147483648) return 0;
            x = -x;
        }
        if (x == 0) return 0;
        string result = "";
        while (x != 0) {
            result += x % 10 + '0';
            x /= 10;
        }
        if (result.length() < 10) {
            int re = stoi(result);
            if (neg) return -re;
            else return re;
        } else if (result.length() > 10) return 0;
        
        if (!neg) {
            if (result > "2147483647") return 0;
            return stoi(result);
        }
        if (result == "2147483648") return 0;
        if (result > "2147483648") return 0;
        return -stoi(result);
    }
};
