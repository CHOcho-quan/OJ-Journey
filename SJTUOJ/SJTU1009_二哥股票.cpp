//
//  SJTU1009_二哥股票.cpp
//  
//
//  Created by 铨 on 2019/3/26.
//
//

#include <iostream>
#include <iomanip>

using namespace std;

double buyCost(int num,int price){
    int shareNum=num*100;
    
    double totalPrice=shareNum*price*1.0;
    double commission=max(shareNum*price*0.002,5.0);
    double transFee=shareNum/1000.0;
    double communicationFee=1.0;
    
    return totalPrice+commission+transFee+communicationFee;
}

double sellCost(int num,int price){
    int shareNum=num*100;
    
    double commission=max(shareNum*price*0.002,5.0);
    double transFee=shareNum/1000.0;
    double communicationFee=1.0;
    double tax=shareNum*price*0.001;
    
    return commission+transFee+communicationFee+tax;
}

double sellIncome(int num,int price){
    return num*price*100.0;
}

double trans(int num,int price, int opt){
    if(opt==1){
        return buyCost(num,price)*(-1.0);
    }
    //(opt==2)
    return sellIncome(num,price)-sellCost(num,price);
    
}

int main(){
    int m,n;

    cin>>m;
    int transRecord[m][3];
    for(int i=0;i<m;i++){
        cin>>transRecord[i][0];
        cin>>transRecord[i][1];
        cin>>transRecord[i][2];
        //cout<<"trans: "<<i<<endl;
    }

    cin>>n;
    int priceRecord[n][2];
    for(int i=0;i<n;i++){
        cin>>priceRecord[i][0];
        cin>>priceRecord[i][1];
        //cout<<"price: "<<i<<endl;
    }
    
    
    int pDate=1,pTrans=0;
    double income=0.0;
    
    int Tnum=0,Tprice=0,Topt=1;
    for(;pTrans<m;pTrans++){
        Tnum=transRecord[pTrans][1];
        Topt=transRecord[pTrans][2];
        for(;pDate<n;pDate++){
            if(priceRecord[pDate][0]>transRecord[pTrans][0]&& \
               priceRecord[pDate-1][0]<=transRecord[pTrans][0]){
                Tprice=priceRecord[pDate-1][1];
                break;
            }
            else{
                Tprice=priceRecord[pDate][1];
            }
        }
        income+=trans(Tnum,Tprice,Topt);
    }
    
    cout.setf(ios::fixed);
    cout << setprecision(2) << income;
    
    return 0;
}


