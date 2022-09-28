class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int changeCnt = 0;
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        bool never1 = false, never2 = false, never3 = false;
        for (auto& num : nums) {
            if (num > max1) {
                changeCnt++;
                max3 = max2;
                max2 = max1;
                max1 = num;
            } else if (num > max2) {
                if (num == max1) {
                    if (!never1 && num == INT_MIN) {
                        changeCnt++;
                        never1 = true;
                    }
                    continue;
                }
                changeCnt++;
                max3 = max2;
                max2 = num;
            } else if (num > max3) {
                if (num == max2) {
                    if (!never2 && num == INT_MIN) {
                        changeCnt++;
                        never2 = true;
                    }
                    continue;
                }
                changeCnt++;
                max3 = num;
            } else if (num == max3) {
                if (!never3 && num == INT_MIN) {
                    never3 = true;
                    changeCnt++;
                }
            }
        }

        return changeCnt >= 3 ? max3 : max1;
    }
};