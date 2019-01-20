//
//  SJTU1024_快排.cpp
//  
//
//  Created by 铨 on 2019/1/17.
//
//

#include <iostream>

using namespace std;

int divide(int *n,int low,int high) {
    int k = n[low];
    
    while (low != high) {
        while (low < high && n[high] >= k) --high;
        if (low < high) {n[low] = n[high];++low;}
        while (low < high && n[low] <= k) ++low;
        if (low < high) {n[high] = n[low];--high;}
    }
    
    n[low] = k;
    return low;
}

void QuickSort(int *n,int low,int high) {
    int mid;
    if (low >= high) return;
    
    mid = divide(n,low,high);
    QuickSort(n,low,mid-1);
    QuickSort(n,mid+1,high);
}

int main()
{
    int n,x;
    cin >> n;
    int *a;
    a = new int[n];
    for (int i = 0;i < n;i++)
    {
        cin >> x;
        a[i] = x;
    }
    QuickSort(a,0,n-1);
    for (int i = 0;i < n;i++)
    {
        cout << a[i] << ' ';
    }
}

