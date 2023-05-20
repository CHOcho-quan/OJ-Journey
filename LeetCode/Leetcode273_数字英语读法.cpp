class Solution {
public:
    string num2word(char c) {
        switch(c) {
            case '0': return "Zero";
            case '1': return "One";
            case '2': return "Two";
            case '3': return "Three";
            case '4': return "Four";
            case '5': return "Five";
            case '6': return "Six";
            case '7': return "Seven";
            case '8': return "Eight";
            case '9': return "Nine";
        }
        return "";
    }

    string num2Ten(char c) {
        switch(c) {
            case '0': return "Zero";
            case '1': return "Ten";
            case '2': return "Twenty";
            case '3': return "Thirty";
            case '4': return "Forty";
            case '5': return "Fifty";
            case '6': return "Sixty";
            case '7': return "Seventy";
            case '8': return "Eighty";
            case '9': return "Ninety";
        }
        return "";
    }

    string num2tenone(char c) {
        switch(c) {
            case '0': return "Ten";
            case '1': return "Eleven";
            case '2': return "Twelve";
            case '3': return "Thirteen";
            case '4': return "Fourteen";
            case '5': return "Fifteen";
            case '6': return "Sixteen";
            case '7': return "Seventeen";
            case '8': return "Eighteen";
            case '9': return "Nineteen";
        }
        return "";
    }

    string getNumber(string str_num) {
        string res = "";
        int cur = 0;
        // hundred part
        auto hund = num2word(str_num[0]);
        if (hund != "Zero") {
            res += (hund + " Hundred");
        }
        // ten / one part
        string ten = num2Ten(str_num[1]), one = num2word(str_num[2]);
        if (ten == "Zero") {
            if (res.length() != 0 && one != "Zero") res += " ";
            if (one != "Zero") res += one;
        } else if (ten != "Ten") {
            if (res.length() != 0) res += " ";
            res += ten;
            if (one != "Zero") res += " " + one;
        } else {
            if (res.length() != 0) res += " ";
            res += num2tenone(str_num[2]);
        }
        return res;
    }

    string numberToWords(int num) {
        string str_num = to_string(num), res = "";
        // 2147483647
        int l = str_num.length(), cur = 0;

        while (l >= 3) {
            auto tmp = getNumber(str_num.substr(l - 3, 3));
            switch (cur) {
                case 0: {
                    if (tmp == "") break;
                    res = tmp + res;
                    break;
                }
                case 1: {
                    if (tmp == "") break;
                    if (res.length() != 0) res = tmp + " Thousand " + res;
                    else res = tmp + " Thousand";
                    break;
                }
                case 2: {
                    if (tmp == "") break;
                    if (res.length() != 0) res = tmp + " Million " + res;
                    else res = tmp + " Million";
                    break;
                }
                case 3: {
                    if (tmp == "") break;
                    if (res.length() != 0) res = tmp + " Billion " + res;
                    else res = tmp + " Billion";
                    break;
                }
            }
            ++cur;
            str_num = str_num.substr(0, l - 3);
            l -= 3;
            cout << res << '\n';
        }

        switch (cur) {
            case 0: {
                if (l == 1) {
                    res = num2word(str_num[0]);
                } else if (l == 2) {
                    res = getNumber("0" + str_num);
                }
                break;
            }
            case 1: {
                if (l == 1) {
                    if (res.length() == 0) res = num2word(str_num[0]) + " Thousand";
                    else res = num2word(str_num[0]) + " Thousand " + res;
                } else if (l == 2) {
                    if (res.length() == 0) res = getNumber("0" + str_num) + " Thousand";
                    else res = getNumber("0" + str_num) + " Thousand " + res;
                }
                break;
            }
            case 2: {
                if (l == 1) {
                    if (res.length() == 0) res = num2word(str_num[0]) + " Million";
                    else res = num2word(str_num[0]) + " Million " + res;
                } else if (l == 2) {
                    if (res.length() == 0) res = getNumber("0" + str_num) + " Million";
                    else res = getNumber("0" + str_num) + " Million " + res;
                }
                break;
            }
            case 3: {
                if (l == 1) {
                    if (res.length() == 0) res = num2word(str_num[0]) + " Billion";
                    else res = num2word(str_num[0]) + " Billion " + res;
                } else if (l == 2) {
                    if (res.length() == 0) res = getNumber("0" + str_num) + " Billion";
                    else res = getNumber("0" + str_num) + " Billion " + res;
                }
                break;
            }
        }

        return res;
    }
};