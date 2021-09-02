class Solution {
public:
    string convertToTitle(int columnNumber) {
        int t;
        string result = "";
        while (columnNumber > 0) {
            t = columnNumber % 26;
            if (t == 0) t = 26;
            result = static_cast<char>('A' + t - 1) + result;
            
            if (t == 26) columnNumber = columnNumber / 26 - 1;
            else columnNumber /= 26;
        }
        
        return result;
    }
};
