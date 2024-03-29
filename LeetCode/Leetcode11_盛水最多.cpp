class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0, l = 0, r = height.size() - 1;
        while (l < r) {
            result = max(result, (r - l) * min(height[r], height[l]));
            if (height[l] < height[r]) ++l;
            else --r;
        }
        
        return result;
    }
};
