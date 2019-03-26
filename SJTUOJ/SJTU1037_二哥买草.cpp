//
//  SJTU1037_二哥买草.cpp
//  
//
//  Created by 铨 on 2019/3/26.
//
//

#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n,m;
    int a[10001],b[10001];
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    int sum=0;
    sort(a,a+n);
    sort(b,b+m);
    int t=0;
    for(int i=0;i<n;i++){
        for(int j=t;j<m;j++){
            if(a[i]>b[j]){
                t=j+1;
                sum++;
                break;
            }
        }
    }
    cout<<sum+n;
    return 0;
}
