#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> advantageCount(vector<int>& A, vector<int>& B) {
    sort(A.begin(), A.end());
    vector<int> result, used(A.size(), 0);

    for (int i = 0;i < B.size();i++) {
        int left = 0, right = A.size() - 1;
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(A[mid] > B[i])
                right = mid;
            else
                left = mid + 1;
        }
        if(A[left] > B[i])
        {
            result.push_back(A[left]);
            A.erase(A.begin() + left);
        }
        else
        {
            result.push_back(A[0]);
            A.erase(A.begin());
        }
    }

    return result;
}
