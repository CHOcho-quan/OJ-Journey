//
//  sjtu1018_背包问题with背包九讲.cpp
//  
//
//  Created by 铨 on 2018/10/25.
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
 * Note : A Better Solution Improving Space Complexity, actually using from W to 0 is to ensure that every object is putted once
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
    cout << "Please input the number of types of objects and total capacity of knapsack :" << endl;
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
        for (int j = volume[i];j < W+1;j++) {
            OPT[j] = max(OPT[j], OPT[j - volume[i]] + value[i]);
        }
    }
    
    return OPT[W];
}

/*
 * Multi 0-1 Knapsack : Finite objects
 * Inputs : N, the number of types of objects
 * W, total capacity of the knapsack
 * N pairs of (pi, ci, wi), pi means the number of this kind of object, ci means the volume and wi means the value
 * Outputs : the max value
 * Note : You can transform it into a simple 0-1 question by getting the number of objects into the array
 * A better simplifier is using 1, 2, 4, 8 to tear apart the n
 * */
int multiKnapsack()
{
    // Inputs
    int N, W, pi, ci, wi, *value, *volume, *p;
    cout << "Please input the number of types of objects and total capacity of knapsack :" << endl;
    cin >> N >> W;
    value = new int[N+1];
    volume = new int[N+1];
    p = new int[N+1];
    cout << "Please input the number, volume and value of each objects : " << endl;
    for (int i = 1;i <= N;i++) {
        cin >> pi >> ci >> wi;
        p[i] = pi;
        value[i] = wi;
        volume[i] = ci;
    }
    
    // Initializing OPT array
    int **OPT;
    OPT = new int*[N+1];
    for (int i = 0;i < N+1;i++) OPT[i] = new int[W+1];
    for (int i = 0;i < W+1;i++) OPT[0][i] = 0;
    
    // DP Algorithm
    for (int i = 1;i < N+1;i++) {
        for (int j = 0;j < W+1;j++) {
            int temp = -2147483647;
            
            for (int k = 1;k <= p[i];k++) {
                if (volume[i]*k > j) continue;
                temp = max(temp, OPT[i-1][j-volume[i]*k] + k*value[i]);
            }
            OPT[i][j] = max(temp, OPT[i-1][j]);
        }
    }
    
    return OPT[N][W];
}

/*
 * 2-dimension Knapsack : 2 kinds of capacity
 * Inputs : N, the number of types of objects
 * W, total capacity of the knapsack
 * N pairs of (pi, ci, wi), pi means the number of this kind of object, ci means the volume and wi means the value
 * Outputs : the max value
 * */
int twoDimensionKnapsack()
{
    // Inputs
    int N, W1, W2, ci1, ci2, wi, *value, *volume1, *volume2;
    cout << "Please input the number of types of objects and total capacity of knapsack :" << endl;
    cin >> N >> W1 >> W2;
    value = new int[N+1];
    volume1 = new int[N+1];
    volume2 = new int[N+1];
    cout << "Please input the number, volume and value of each objects : " << endl;
    for (int i = 1;i <= N;i++) {
        cin >> ci1 >> ci2 >> wi;
        value[i] = wi;
        volume1[i] = ci1;
        volume2[i] = ci2;
    }
    
    // Initializing OPT array
    int **OPT;
    OPT = new int*[W1+1];
    for (int i = 0;i < W1+1;i++) OPT[i] = new int[W2+1];
    for (int i = 0;i < W1+1;i++) {
        for (int j = 0;j < W2+1;j++) {
            OPT[i][j] = 0;
        }
    }
    
    // DP Algorithm
    for (int i = 1;i < N+1;i++) {
        for (int c1 = W1;c1 >= volume1[i];c1--) {
            for (int c2 = W2;c2 >= volume2[i];c2--) {
                OPT[c1][c2] = max(OPT[c1][c2], OPT[c1-volume1[i]][c2-volume2[i]] + value[i]);
            }
        }
    }
    
    return OPT[W1][W2];
}

/*
 * Grouping Knapsack
 * Inputs : N, the number of types of objects
 * W, total capacity of the knapsack
 * N pairs of (gi, ci, wi), gi means group, ci means the volume and wi means value
 * Output : the max one
 * */
int groupKnapsack()
{
    // Inputs
    int N, W, gi, ci, wi, *C, *V, *G, gsum = 0, total = 0, cnt = 1, now = -2147483647;
    cout << "Please input the number of types of objects and total capacity of knapsack :" << endl;
    cin >> N >> W;
    C = new int[N+1];
    V = new int[N+1];
    G = new int[N+1];
    cout << "Please input the group, volume and value of each objects : " << endl;
    for (int i = 1;i < N+1;i++) {
        cin >> gi >> ci >> wi;
        if (now == gi) gsum+=1;
        else {
            if (now == -2147483647) {
                now = gi;
                gsum = 1;
                total += 1;
            }
            else {
                now = gi;
                G[cnt++] = gsum;
                gsum = 1;
                total += 1;
            }
        }
        C[i] = ci;
        V[i] = wi;
    }
    G[cnt] = gsum;
    
    // Initializing OPT array
    int *OPT;
    OPT = new int [W+1];
    
    // DP Algorithm
    for (int i = 1;i < total+1;i++) {
        for (int j = W;j > 0;j--) {
            int temp = -2147483647;
            for (int k = 0;k < G[i];k++) {
                if (j > C[i]) temp = max(temp, OPT[j-C[i]] + V[i]);
                else continue;
            }
            OPT[j] = max(temp, OPT[j]);
        }
    }
    
    return OPT[W];
}

int main()
{
    cout << groupKnapsack();
}
