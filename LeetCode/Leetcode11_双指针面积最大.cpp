#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

int maxArea(vector<int>& height) {
    int max = -1, area;
    
    for (int i = 0;i < height.size();i++)
    {
        for (int j = 0;j < i;j++)
        {
            if (i == j) continue;
            area = (i - j) * min(height[i], height[j]);
            if (area > max) max = area;
        }
    }
    
    return max;
}

int maxArea2(vector<int>& height) {
    int area, maxi = -1, low = 0, high = height.size() - 1;
    area = (high - low) * min(height[low], height[high]);
    maxi = max(maxi, area);
    
    while (low != high)
    {
        if (height[low] < height[high]) low++;
        else high--;
        
        area = (high - low) * min(height[low], height[high]);
        maxi = max(maxi, area);
    }
    
    return maxi;
}

int main() {
    vector<int> h = {1,8,6,2,5,4,8,3,7};
    cout << maxArea2(h);
}
