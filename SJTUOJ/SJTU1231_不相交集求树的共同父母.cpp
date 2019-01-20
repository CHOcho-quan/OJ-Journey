//
//  1231_不相交集求树的共同父母.cpp
//  
//
//  Created by 铨 on 2018/5/18.
//
//

class node {
public:
    int data;
    node *next;
    node(int a){data = a;next = NULL;}
};

void compare(node *t1, node *t2)
{
    node *s2 = t2->next;
    t1 = t1->next;
    bool flag = false;
    //cout << t1->data << ' ' << s2->data;
    while (t1 != NULL)
    {
        while (s2 != NULL)
        {
            if (t1 == s2 && t1->data != 0)
            {
                cout << t1->data;
                flag = true;
                break;
            }
            s2 = s2->next;
        }
        if (flag) break;
        t1 = t1->next;
        s2 = t2;
    }
}

int main() {
    vector<node*> a;
    int n,aa,bb,x,y;
    cin >> n;
    for (int i = 0;i < n;i++)
    {
        node *t;
        t = new node(i+1);
        a.push_back(t);
    }
    cin >> aa >> bb;
    
    for (int i = 0;i < n;i++)
    {
        cin >> x >> y;
        node *tmp;
        node *temp;
        if (x != 0)
        {
            node *c = a[x-1];
            c->next = a[i];
        }
        if (y != 0)
        {
            node *c = a[y-1];
            c->next = a[i];
        }
    }
    
    compare(a[aa-1],a[bb-1]);
}
