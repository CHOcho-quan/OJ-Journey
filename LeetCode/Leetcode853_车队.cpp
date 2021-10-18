class Solution {
public:
    void quickSort(vector<int>& p, vector<int>& s, int l, int r) {
        if (l >= r) return;
        
        int st = l, en = r, pivot1 = p[l], pivot2 = s[l];
        while (st < en) {
            while (st < en && p[en] >= pivot1) --en;
            p[st] = p[en];
            s[st] = s[en];
            while (st < en && p[st] <= pivot1) ++st;
            p[en] = p[st];
            s[en] = s[st];
        }
        p[st] = pivot1;
        s[st] = pivot2;
        
        quickSort(p, s, l, st);
        quickSort(p, s, st + 1, r);
    }
    
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        
        quickSort(position, speed, 0, n - 1);
        // for (auto& p : position) cout << p << ' ';
        int res = 0;
        for (int i = 0; i < n; ++i) {
            bool bump = false;
            for (int j = i + 1; j < n; ++j) {
                double met = static_cast<double>(position[i] - position[j]) / (speed[j] - speed[i]);
                // cout << i << ' ' << j << " Meet at " << position[i] + speed[i] * met << '\n';
                if (met >= 0 && position[i] + speed[i] * met <= target) {
                    // cout << i << " and " << j << " becomes fleet\n";
                    bump = true;
                    break;
                }
            }
            if (!bump) ++res;
        }
        return res;
    }
};
