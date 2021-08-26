class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int rot = k % nums.size();
        // std::cout<< rot << '\n';
        if (!rot) return;
        vector<int> rem(rot, 0);
        for (int i = nums.size() - rot; i < nums.size(); ++i) {
            // std::cout << nums[i] << ' ';
            rem[i - nums.size() + rot] = nums[i];
        }
        // std::cout << '\n';
        // for (auto& r : rem) std::cout << r << ' ';
        int t = 0;
        for (int i = 0; i < nums.size(); ++i) {
            rem.push_back(nums[i]);
            nums[i] = rem[t];
            ++t;
        }
    }
};
