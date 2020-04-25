#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    map<int,int> m;
    for (auto bar : barcodes) {
        if (m.count(bar)) m[bar] += 1;
        else m[bar] = 1;
    }

    sort(barcodes.begin(), barcodes.end(), [&m](int& a, int& b) {if (m[a] == m[b]) return a > b; 
    return m[a] > m[b];} );

    vector<int> result(barcodes.size(), 0);
    for (int i = 0;i < result.size();i+=2) result[i] = barcodes[i / 2];
    for (int i = 1;i < result.size();i+=2) result[i] = barcodes[result.size() / 2 + i / 2 + result.size() % 2];

    for (int i = 0;i < result.size();i++) cout << barcodes[i] << ' '; //<< result[i] << endl;

    return result;
}