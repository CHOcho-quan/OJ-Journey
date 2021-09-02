class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        bool negative = false;
        if (num < 0) {
            negative = true;
            num = -num;
        }
        int n = num;
        string result = "";
        while (n != 0) {
            auto cur = n % 7;
            n /= 7;
            result = to_string(cur) + result;
        }
        
        if (negative) {
            result = "-" + result;
        }
        
        return result;
    }
};
