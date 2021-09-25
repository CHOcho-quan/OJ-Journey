class Solution {
public:
    // int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    
    // }
    
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), result = 1000001;
        for (int i = 0; i < n; ++i) {
            int st = gas[i], fi = i - 1 >= 0 ? i - 1 : n - 1, cur = i;
            bool flag = true;
            while (cur != fi) {
                st -= cost[cur];
                if (st < 0) {
                    flag = false;
                    break;
                }
                cur = cur + 1 >= n ? 0 : cur + 1;
                st += gas[cur];
            }
            st -= cost[cur];
            if (st < 0) flag = false;
            if (flag) {
                result = min(result, i);
                break;
            }
        }
        
        return result == 1000001 ? -1 : result;
    }
};
