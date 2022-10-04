class Solution {
public:
    int FindPower(int i1, unordered_map<int, int>& v2power) {
        int k1 = -1;
        if (v2power.find(i1) != v2power.end()) k1 = v2power[i1];
        else {
            vector<int> midv = {i1};
            int cnt = 0;
            while (i1 != 1) {
                if (v2power.find(i1) != v2power.end()) {
                    cnt += v2power[i1];
                    break;
                }
                if (i1 % 2) {
                    i1 = 3 * i1 + 1;
                    midv.emplace_back(i1);
                } else {
                    i1 /= 2;
                    midv.emplace_back(i1);
                }
                ++cnt;
            }
            k1 = cnt;
            for (int i = 0; i < midv.size(); ++i) v2power[midv[i]] = cnt--;
        }
        return k1;
    }

    int getKth(int lo, int hi, int k) {
        unordered_map<int, int> v2power;
        vector<int> store;
        for (int i = lo; i <= hi; ++i) store.push_back(i);

        sort(store.begin(), store.end(), [&](const int& c1, const int& c2) {
            int i1 = c1, i2 = c2;
            int k1 = FindPower(i1, v2power), k2 = FindPower(i2, v2power);

            if (k1 == k2) return c1 < c2;
            return k1 < k2;
        });
        for (auto s : store) cout << s << ' ' << v2power[s] << '\n';
        cout << '\n';
        // for (auto iter : v2power) cout << iter.first << '&' << iter.second << '\n';
        return store[k - 1];
    }
};