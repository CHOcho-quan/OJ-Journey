class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        int* masks = new int[n];
        memset(masks, 0, sizeof(int)*n);
        int* lens = new int[n];
        for (int i = 0; i < n; ++i) {
            for (char c : words[i]) {
                masks[i] |= 1 << (c - 'a');
            }
            lens[i] = words[i].size();
        }
        
        int res = 0;
        int curr = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                curr = lens[i]*lens[j];
                if (curr > res) {
                    // cout << curr << " " << i << "," << j << " " << (masks[i] & masks[j]) << endl;
                    if ((masks[i] & masks[j]) == 0) {
                        res = curr;
                    }
                }
            }
        }
        return res;
    }
};
