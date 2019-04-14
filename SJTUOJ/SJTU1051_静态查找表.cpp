//
//  SJTU1051_静态查找表.cpp
//  
//
//  Created by 铨 on 2019/4/13.
//
//

#include <iostream>
#include <iomanip>
#include <queue>
#include <stack>
#include <cmath>
#include <string>

using namespace std;

class Node
{
public:
    Node *next;
    int data;
    Node() {next = NULL;}
    Node(int d, Node *n = NULL) {data = d; next = n;}
};

class LinkList
{
public:
    LinkList()
    {
        root = new Node();
    }
    Node *root;
    void insert(int d)
    {
        Node *tmp = root;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = new Node(d);
    }
    
    int find(int d)
    {
        int sum = 0;
        Node *tmp = root, *tmp_last = root;
        if (root->data == d)
        {
            sum++;
            return sum;
        }
        while (tmp != NULL)
        {
            sum++;
            if (d == tmp->data)
            {
                tmp_last->next = tmp->next;
                tmp->next = root;
                root = tmp;
                break;
            }
            tmp_last = tmp;
            tmp = tmp->next;
        }
        
        return sum;
    }
    
    void traverse()
    {
        Node *tmp = root;
        while (tmp != NULL)
        {
            cout << tmp->data << ' ';
            tmp = tmp->next;
        }
    }
};

int main()
{
    LinkList ll;
    int n,m,tmp,sum = 0;
    cin >> n;
    for (int i = 0;i < n;i++)
    {
        cin >> tmp;
        if (i == 0) {
            ll.root->data = tmp;
            continue;
        }
        ll.insert(tmp);
    }
    //    ll.traverse();
    cin >> m;
    for (int i = 0;i < n;i++)
    {
        cin >> tmp;
        sum += ll.find(tmp);
        //        ll.traverse();
    }
    cout << sum;
}
