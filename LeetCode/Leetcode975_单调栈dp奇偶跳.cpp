#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>

using namespace std;

int oddEvenJumps_monostack(vector<int>& A)
{
    if (A.size()==0) return 0;
    if (A.size()==1) return 1;

    vector<int> odd_next(A.size(), -1);
    vector<int> even_next(A.size(), -1);
    vector<int> index(A.size(), 1);
    for (int i = 0;i < A.size();i++) index[i] = i;

    sort(index.begin(), index.end(), [&A](int &a, int &b) {
            if (A[a] == A[b])
                return a < b;
            return A[a] < A[b];
    });

    // for (int i = 0;i < index.size();i++) cout << index[i] << ' ';

    stack<int> mono_stack;
    for (int i = 0;i < A.size();i++)
    {
        while (!mono_stack.empty() && index[i] > mono_stack.top())
        {
            odd_next[mono_stack.top()] = index[i];
            mono_stack.pop();
        }
        mono_stack.push(index[i]);
    }

    sort(index.begin(), index.end(), [&A](int &a, int &b) {
            if (A[a] == A[b])
                return a < b;
            return A[a] > A[b];
    });

    stack<int> mono_stack2;
    for (int i = 0;i < A.size();i++)
    {
        while (!mono_stack2.empty() && index[i] > mono_stack2.top())
        {
            even_next[mono_stack2.top()] = index[i];
            mono_stack2.pop();
        }
        mono_stack2.push(index[i]);
    }    

    // for (int i = 0;i < A.size();i++) cout << even_next[i] << ' ' << odd_next[i] << endl;

    // index 0 for even 1 for odd
    vector<vector<int>> dp(2, vector<int>(A.size(), 0));
    dp[0][A.size()-1] = 1;
    dp[1][A.size()-1] = 1;

    int result = 1;
    for (int i = A.size()-2;i >= 0;i--)
    {
        // dp[0][i]
        if (even_next[i] == -1) dp[0][i] = 0;
        else dp[0][i] = dp[1][even_next[i]]; 

        // dp[1][i]
        if (odd_next[i] == -1) dp[1][i] = 0;
        else dp[1][i] = dp[0][odd_next[i]];

        if (dp[1][i]) result++;
    }

    // for (int i = 0;i < A.size();i++) cout << dp[0][i] << ' ' << dp[1][i] << endl;

    return result;
}

int oddEvenJumps(vector<int>& A) 
{
    // TLE
    if (A.size()==0) return 0;
    if (A.size()==1) return 1;

    // index 0 for even 1 for odd
    vector<vector<int>> dp(2, vector<int>(A.size(), 2));
    dp[0][A.size()-1] = 1;
    dp[1][A.size()-1] = 1;

    vector<vector<int>> mapping(2, vector<int>(A.size(), -1));
    int result = 1;
    for (int i = A.size()-2;i >= 0;i--)
    {
        int maxi = 2147483647, max_ind = -1, mini = -2147483647, min_ind = -1;
        for (int j = i+1;j < A.size();j++)
        {
            if (A[j] >= A[i] && A[j] < maxi) {
                maxi = A[j];
                max_ind = j;
            }
            if (A[j] <= A[i] && A[j] > mini) {
                mini = A[j];
                min_ind = j;
            }
        }

        if (min_ind != -1) mapping[0][i] = min_ind;
        else mapping[0][i] = -1;
        if (max_ind != -1) mapping[1][i] = max_ind;
        else mapping[1][i] = -1;

        // dp[0][i]
        if (mapping[0][i] == -1) dp[0][i] = 0;
        else dp[0][i] = dp[1][mapping[0][i]]; 

        // dp[1][i]
        if (mapping[1][i] == -1) dp[1][i] = 0;
        else dp[1][i] = dp[0][mapping[1][i]];

        if (dp[1][i]) result++;
    }

    for (int i = 0;i < A.size();i++) cout << mapping[0][i] << ' ' << mapping[1][i] << endl;

    return result;
}

int main()
{
    vector<int> A = {5, 1, 3, 4, 2};    
    cout << oddEvenJumps(A) << endl;
    cout << "---------------------------------" << endl;
    cout << oddEvenJumps_monostack(A);
}