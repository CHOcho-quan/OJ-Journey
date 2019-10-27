#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

bool lemonadeChange(vector<int>& bills) {
    if (bills[0] != 5) return false;
    
    vector<int> bs = {0, 0, 0};
    for (int i = 0;i < bills.size();i++)
    {
        if (bills[i] == 5) bs[0]++;
        
        if (bills[i] == 10)
        {
            if (bs[0] > 0) {
                bs[0]--;
                bs[1]++;
            }
            else return false;
        }
        
        if (bills[i] == 20)
        {
            if (bs[1] > 0) {
                bs[1]--;
                if (bs[0] > 0) {
                    bs[0]--;
                    bs[2]++;
                }
                else return false;
            }
            else {
                if (bs[0] >= 3) {
                    bs[0] -= 3;
                    bs[2]++;
                }
                else return false;
            }
        }
    }
    
    return true;
}

int main() {
    vector<int> bs = {5, 5, 5, 10, 20};
    cout << lemonadeChange(bs);
}
