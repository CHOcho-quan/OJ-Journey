#include <iostream>
#include <vector>

using namespace std;

int strToInt(string str) 
{
    int result = 0, refer = 1, start = 0;
    bool first_flag = true, cont_flag = true;

    str.erase(0,str.find_first_not_of(" "));
    cout << str << endl;
    if (str[0] == '+') {
        refer = 1;
        start = 1;
    }
    else if (str[0] == '-') {
        refer = -1;
        start = 1;
    }
    cout << refer << endl;

    for (int i = start;i < str.length();i++)
    {
        if (first_flag && (str[i] - '0' > 0 && str[i] - '0' < 10)) first_flag = false;
        if (first_flag && (str[i] - '0' >= 10 || str[i] - '0' < 0)) return 0;
        
        if (str[i] == '.') 
        {
            return result * refer;
        }
        else 
        {
            int tmp = str[i] - '0';
            cout << tmp << endl;
            if (tmp < 0 || tmp >= 10) return refer * result;
            else 
            {
                if (result > 2147483647 / 10) return refer > 0 ? 2147483647:-2147483648;
                result *= 10;
                if (result > 2147483647 - tmp) return refer > 0 ? 2147483647:-2147483648;
                result += tmp;
            }
        }
    }

    return result * refer;
}

int main()
{
    string str = "  -0012a42"
;
    cout << strToInt(str);
}