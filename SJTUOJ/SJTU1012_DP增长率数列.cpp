//
//  SJTU1012_DP增长率数列.cpp
//  
//
//  Created by 铨 on 2019/1/18.
//
//

#include<iostream>
#include<string.h>
#include<cmath>
#include<algorithm>
#include<string>
#include<climits>
#include<vector>
#include<cstdio>
typedef long long ll;
using namespace std;
ll len[200020];
ll cnt[200020];
int gcd(int a, int b)
{
    while(b != 0)
    {
        int r = b;
        b = a % b;
        a = r;
    }
    return a;
}

int main(){
    int l,r;
    cin>>l>>r;
    for(int i = l;i<=r;i++){
        int share = i/gcd(100,i);
        int next = len[i] + 1;
        for(int cur = i + share;cur<=r;cur+=share){
            if(len[cur] < next){
                len[cur] = next;
                cnt[cur] = cnt[i]>0?cnt[i]:1;
            }
            else if (len[cur]==next){
                cnt[cur]+=(cnt[i]>0?cnt[i]:1);
            }
        }
    }
    ll m = 0;
    for(int i = l;i<=r;i++){
        m=m>len[i]?m:len[i];
    }
    ll ans = 0;
    for(int i = l;i<=r;i++){
        if(len[i]==m){
            ans+=(cnt[i]>0?cnt[i]:1); 
        }
    }
    cout<<m+1<<endl<<ans;
}
