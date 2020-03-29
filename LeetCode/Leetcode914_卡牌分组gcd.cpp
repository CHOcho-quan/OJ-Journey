//
//  Leetcode914_卡牌分组gcd.cpp
//  
//
//  Created by 铨 on 2020/3/27.
//

#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>

using namespace std;

bool hasGroupsSizeX(vector<int>& deck) {
    sort(deck.begin(), deck.end());
    vector<int> possible;
    int deckSize = deck.size();
    for (int i = 2;i < deckSize+1;i++) possible.push_back(0);
    
    for (int i = 2;i < deckSize + 1;i++) {
        if (deckSize % i) continue;
        
        int last;
        bool flag = false;
        for (int j = 0;j < deckSize;j++) {
            if (j == 0 || j % i == 0) last = deck[j];
            else {
                if (deck[j] != last) {
                    flag = true;
                    break;
                }
            }
        }
        
        if (!flag) return true;
    }
    
    return false;
}

int gcd(int a, int b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

bool hasGroupsSizeX_2(vector<int>& deck) {
    if (deck.size() <= 1) return false;
    map<int, int> m;
    for (int i = 0;i < deck.size();i++) {
        if (m.count(deck[i]) == 0) m[deck[i]] = 1;
        else m[deck[i]] += 1;
    }
    
    int last;
    for (auto i = m.begin();i != m.end();i++) {
        if (i == m.begin()) {
            last = i->second;
            continue;
        }
        last = gcd(last, i->second);
        if (last == 1) return false;
    }
    
    return true;
}

int main() {
    vector<int> deck = {1,1,2,2,2,2};
    cout << hasGroupsSizeX_2(deck) << endl;
}
