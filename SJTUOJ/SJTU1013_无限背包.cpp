//
//  SJTU1013_无限背包.cpp
//  
//
//  Created by 铨 on 2019/1/17.
//
//

/***Knapsack Problem with All Kinds of Versions***/
#include<iostream>

using namespace std;

/*
 * Simple 0-1 Knapsack
 * Inputs : N, number of objects
 * W, total capacity of the knapsack
 * N pairs of (ci, wi), ci means the volume and wi means the value
 * Outputs : the max value
 * Simple Solution not Improving Space Complexity
 * */
int simpleKnapsack1()
{
    // Inputs
    int N, W, ci, wi, *value, *volume;
    cout << "Please input the number of objects and total capacity of knapsack :" << endl;
    cin >> N >> W;
    value = new int[N+1];
    volume = new int[N+1];
    cout << "Please input the value and volume of each objects, first volume : " << endl;
    for (int i = 1;i <= N;i++) {
        cin >> ci >> wi;
        value[i] = wi;
        volume[i] = ci;
    }
    
    // Initializing OPT array
    int **OPT;
    OPT = new int*[N+1];
    for (int i = 0;i < N+1;i++) {
        OPT[i] = new int[W+1];
    }
    for (int i = 0;i < W+1;i++) {
        OPT[0][i] = 0;
    }
    
    // DP Algorithm
    for (int i = 1;i < N+1;i++) {
        for (int j = 0;j < W+1;j++) {
            if (volume[i] > j) {
                OPT[i][j] = OPT[i-1][j];
                continue;
            }
            OPT[i][j] = max(OPT[i-1][j], OPT[i-1][j-volume[i]] + value[i]);
        }
    }
    
    return OPT[N][W];
}

/*
 * Simple 0-1 Knapsack
 * Inputs : N, number of objects
 * W, total capacity of the knapsack
 * N pairs of (ci, wi), ci means the volume and wi means the value
 * Outputs : the max value
 * A Better Solution Improving Space Complexity
 * */
int simpleKnapsack2()
{
    // Inputs
    int N, W, ci, wi, *value, *volume;
    cout << "Please input the number of objects and total capacity of knapsack :" << endl;
    cin >> N >> W;
    value = new int[N+1];
    volume = new int[N+1];
    cout << "Please input the value and volume of each objects, first volume : " << endl;
    for (int i = 1;i <= N;i++) {
        cin >> ci >> wi;
        value[i] = wi;
        volume[i] = ci;
    }
    
    // Initializing OPT array
    int *OPT;
    OPT = new int[W+1];
    for (int i = 0;i < W+1;i++) OPT[i] = 0;
    
    // DP Algorithm
    for (int i = 1;i < N+1;i++) {
        for (int j = W;j >=volume[i];j--) {
            OPT[j] = max(OPT[j], OPT[j - volume[i]] + value[i]);
        }
        
        for (int t = 0;t < W+1;t++) cout << OPT[t] << ' ';
        cout << endl;
    }
    
    return OPT[W];
}

/*
 * Complete 0-1 Knapsack : Infinite objects
 * Inputs : N, the number of types of objects
 * W, total capacity of the knapsack
 * N pairs of (ci, wi), ci means the volume and wi means the value
 * Outputs : the max value
 * Note : You can transform it into a simple 0-1 question by getting the number of objects by W / wi
 * */
int completeKnapsack()
{
    // Inputs
    int N, W, ci, wi, *value, *volume;
    // cout << "Please input the number of types of objects and total capacity of knapsack :" << endl;
    cin >> W >> N;
    value = new int[N+1];
    volume = new int[N+1];
    // cout << "Please input the value and volume of each objects, first volume : " << endl;
    for (int i = 1;i <= N;i++) {
        cin >> ci >> wi;
        value[i] = wi;
        volume[i] = ci;
    }
    
    // Initializing OPT array
    int *OPT;
    OPT = new int[W+1];
    for (int i = 0;i < W+1;i++) OPT[i] = 0;
    
    // DP Algorithm
    for (int i = 1;i < N+1;i++) {
        for (int j = volume[i];j < W+1;j++) {
            OPT[j] = max(OPT[j], OPT[j - volume[i]] + value[i]);
        }
    }
    
    return OPT[W];
}

int main()
{
    cout << completeKnapsack();
}
