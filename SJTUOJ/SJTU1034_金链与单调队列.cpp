//
//  SJTU1034_金链与单调队列.cpp
//  
//
//  Created by 铨 on 2019/3/24.
//
//

#include <iostream>

using namespace std;

class monotoneQue
{
    int *data;
    int front;
    int rear;
    int maxsize;
public:
    monotoneQue(int initsize=10):front(0),rear(0),maxsize(initsize)
    {
        data=new int[maxsize];
    }
    ~monotoneQue(){delete [] data;}
    void enqueue(int x)
    {
        while(rear!=front&&data[(rear-1)%maxsize]<x)
        {
            rear=(rear-1)%maxsize;
        }
        data[rear]=x;
        rear=(rear+1)%maxsize;
    }
    void dequeue(int x)
    {
        if(data[front]==x)
        {
            front=(front+1)%maxsize;
        }
    }
    bool isempty(){return front==rear;}
    int head(){return data[front];}
};

monotoneQue que(200000);

int main()
{
    int n,k;
    cin>>n>>k;
    int rp[n];
    for(int i=0;i<n;++i)
    {
        cin >> rp[i];
    }
    
    int min_temp;
    for(int i=0;i<k;++i)
    {
        que.enqueue(rp[i]);
    }
    min_temp=que.head();
    if(n==k)
    {
        cout<<min_temp<<endl;
        return 0;
    }
    int p=k;
    while(p!=k-1)
    {
        que.dequeue((p-k<0)?(rp[p-k+n]):(rp[p-k]));
        que.enqueue(rp[p]);
        if(min_temp>que.head())
        {
            min_temp=que.head();
        }
        //cout<<min_temp<<" "<<que.head()<<" "<<p<<endl;
        p=((p+1==n)?(0):(p+1));
    }
    
    cout<<min_temp<<endl;
    
    return 0;
}
