//
//  SJTU3021_逆序数对.cpp
//  
//
//  Created by 铨 on 2019/4/14.
//
//

#include <iostream>
using namespace std;
long long n,count = 0;
long long arr[100000],a[100000],b[100000];
void mergesort(int , int);
void merge(int, int, int);
int main(){
    int n;
    
    cin>>n;
    for (int i = 0; i < n;++i) cin>>arr[i];
    mergesort(0,n-1);
    cout<<count;
    
    return 0;
}
void merge(int l,int m,int r){
    if (l==r) return;
    int len1 = m - l + 1,p = 0,q = 0;
    int len2 = r - m;
    for (int i = 0;i < len1;++i) a[i] = arr[i+l];
    for (int i = 0;i < len2;++i) b[i] = arr[m+i+1];
    //    a[len1] = 1000000000000000000;
    //    b[len2] = 1000000000000000000;
    for (int i = l;i <= r;++i){
        if (a[p] <= b[q]) arr[i] = a[p++];
        else{
            count += m - p -l + 1;
            arr[i] = b[q++];
        }
    }
}
void mergesort(int l,int r){
    if (l>=r) return;
    int m = (l+r)/2;
    mergesort(l,m);
    mergesort(m+1,r);
    merge(l,m,r);
}
