#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

string intToRoman(int num) {
    string result = "";
    int qian = num / 1000;
    int bai = (num % 1000) / 100;
    int shi = (num % 100) / 10;
    int yi = (num % 10);
    
    cout << qian << ' ' << bai << ' ' << shi << ' ' << yi << endl;
    
    for (int i = 0;i < qian;i++) result += "M";
    
    if (bai == 4) result = result + "CD";
    if (bai == 9) result = result + "CM";
    if (bai >= 0 && bai < 4)
    {
        for (int i = 0;i < bai;i++) result = result + "C";
    }
    if (bai >= 5 && bai < 9)
    {
        result = result + "D";
        for (int i = 5;i < bai;i++) result = result + "C";
    }
    
    if (shi == 4) result = result + "XL";
    if (shi == 9) result = result + "XC";
    if (shi >= 0 && shi < 4)
    {
        for (int i = 0;i < shi;i++) result = result + "X";
    }
    if (shi >= 5 && shi < 9)
    {
        result = result + "L";
        for (int i = 5;i < shi;i++) result = result + "X";
    }
    
    if (yi == 4) result = result + "IV";
    if (yi == 9) result = result + "IX";
    if (yi >= 0 && yi < 4)
    {
        for (int i = 0;i < yi;i++) result = result + "I";
    }
    if (yi >= 5 && yi < 9)
    {
        result = result + "V";
        for (int i = 5;i < yi;i++) result = result + "I";
    }
    
    return result;
}

int main() {
    int n = 58;
    cout << intToRoman(n);
}
