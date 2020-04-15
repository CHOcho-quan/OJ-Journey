#include <iostream>
#include <vector>

using namespace std;

bool find132pattern(vector<int>& nums) {
    if (nums.size()==0) return false;
    vector<int> st = {};
    vector<int> mini = vector<int>(nums.size(), 0);
    mini[0] = nums[0];
    for (int i = 1;i < nums.size();i++) mini[i] = min(mini[i-1], nums[i]);

    for (int i = nums.size()-1;i >= 0;i--) {
        if (nums[i] <= mini[i]) continue;
        else {
            if (st.size() == 0) {
                st.push_back(nums[i]);
                continue;
            }

            while (st.size() != 0 && nums[i] > st[st.size()-1]) {
                if (st[st.size()-1] > mini[i]) return true;
                else {
                    st.pop_back();
                }
            }
            st.push_back(nums[i]);
        }
    }
    return false;
}
        // DP - TLE
        // vector<vector<int>> dp = vector<vector<int>>(nums.size(), vector<int>(nums.size(), -1));
        // vector<vector<int>> dpl = vector<vector<int>>(nums.size(), vector<int>(nums.size(), -1));
        // vector<vector<int>> dpi = vector<vector<int>>(nums.size(), vector<int>(nums.size(), -1));

        // for (int i = 0;i < nums.size();i++) {
        //     dpl[i][i] = nums[i];
        //     if (i < nums.size()-1) dpl[i][i+1] = nums[i] <= nums[i+1] ? nums[i] : nums[i+1];
        //     dp[i][i] = nums[i];
        //     if (i < nums.size()-1) dp[i][i+1] = nums[i] >= nums[i+1] ? nums[i] : nums[i+1];
        //     dpi[i][i] = i;
        //     if (i < nums.size()-1) dpi[i][i+1] = nums[i] >= nums[i+1] ? i : i+1;
        // }

        // for (int i = 0;i < nums.size();i++) {
        //     for (int j = 2;j < nums.size() - i;j++) // 
        //     {
        //         dpl[i][i+j] = dpl[i][i+j-1] <= nums[i+j] ? dpl[i][i+j-1] : nums[i+j];
        //         dp[i][i + j] = dp[i][i + j - 1] > nums[i + j] ? dp[i][i+j-1] : nums[i+j];
        //         dpi[i][i+j] = dp[i][i+j-1] >= nums[i+j] ? dpi[i][i+j-1] : i+j;
        //         if ((dpi[i][i+j] >= 1) && (dp[i][i+j] > nums[i+j]) && (dpl[0][dpi[i][i+j]] < nums[i+j])) return true;
        //     }
        // }

        // return false;