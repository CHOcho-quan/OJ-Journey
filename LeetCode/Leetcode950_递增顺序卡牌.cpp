#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>

using namespace std;

vector<int> deckRevealedIncreasing(vector<int>& deck) {
    sort(deck.begin(), deck.end());
    if (deck.size() <= 2) return deck;

    vector<int> result;
    result.push_back(deck[deck.size()-2]);
    result.push_back(deck[deck.size()-1]);

    for (int i = deck.size()-3;i >= 0;i--) {
        int tmp = result[result.size()-1];
        result.pop_back();
        result.insert(result.begin(), tmp);
        result.insert(result.begin(), deck[i]);
    }

    return result;
}