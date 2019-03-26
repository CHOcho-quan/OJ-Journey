//
//  SJTU1011_复数类狗.cpp
//  
//
//  Created by 铨 on 2019/3/26.
//
//

#include<iostream>
using namespace std;

int main(){
    double a,b,c,d,m,n;
    cin>>a>>b>>c>>d;
    printf("%.2lf %.2lf\n",a+c,b+d);
    printf("%.2lf %.2lf\n",a-c,b-d);
    printf("%.2lf %.2lf\n",a*c-b*d,a*d+b*c);
    printf("%.2lf %.2lf\n",(a*c+b*d)/(c*c+d*d),(b*c-a*d)/(c*c+d*d));
    printf("%.2lf %.2lf\n",a+c,b+d);
    a+=c;
    b+=d;
    printf("%.2lf %.2lf\n",a-c,b-d);
    a-=c;
    b-=d;
    printf("%.2lf %.2lf\n",a*c-b*d,a*d+b*c);
    m=a*c-b*d;
    n=a*d+b*c;
    printf("%.2lf %.2lf",(m*c+n*d)/(c*c+d*d),(n*c-m*d)/(c*c+d*d));
    return 0;
}
