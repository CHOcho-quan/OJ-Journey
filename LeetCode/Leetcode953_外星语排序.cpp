#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool comp(string last, string now, string order)
{
    bool result = (last.length() <= now.length());

    for (int i = 0;i < min(last.length(), now.length());i++)
    {
        int last_order = order.find(last[i]);
        int now_order = order.find(now[i]);
        if (last_order < now_order) return true;
        else return false;
    }

    return result;
}

bool isAlienSorted(vector<string>& words, string order) 
{
    if (words.size() == 1) return 1;
    string l = words[0];
    for (int i = 1;i < words.size();i++)
    {
        if (comp(l, words[i], order)) {
            l = words[i];
            continue;
        }
        else return false;
    }

    return true;
}

int main()
{
    vector<string> words = {"apple","app"};
    string order = "abcdefghijklmnopqrstuvwxyz";
    cout << isAlienSorted(words, order);
}