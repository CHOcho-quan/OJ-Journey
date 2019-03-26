//
//  LinkList.cpp
//  
//
//  Created by 铨 on 2019/3/26.
//
//

#include <iostream>

using namespace std;

template <class T>
class Linklist
{
private:
    class Node
    {
    public:
        Node *next;
        T data;
        Node(T d, Node *n = NULL)
        {
            data = d;
            next = n;
        }
    };
    Node *root;
public:
    Linklist(T d);
    Linklist(Node *n);
    void insert(int index, T d);
    void remove(int index);
    T visit(int index);
    void traverse();
    void add(T d);
    ~Linklist();
};

template <class T>
Linklist<T>::Linklist(T d)
{
    root = new Node(d);
}

template <class T>
Linklist<T>::Linklist(Linklist<T>::Node *n)
{
    root = n;
}

template <class T>
void Linklist<T>::insert(int index, T d)
{
    if (index == 0) {
        root = new Node(d, root);
        return ;
    }
    
    Node *tmp = root, *temp = root;
    for (int i = 0;i < index;i++)
    {
        if (tmp!=NULL) {
            temp = tmp;
            tmp = tmp->next;
        }
        else {
            cout << "Wrong Index!" << endl;
            return ;
        }
    }
    
    
    temp->next = new Node(d, tmp);
}

template <class T>
void Linklist<T>::remove(int index)
{
    Node *tmp = root, *temp = root;
    if (index==0) {
        root = root->next;
        delete tmp;
        return ;
    }
    
    for (int i = 0;i < index;i++)
    {
        if (tmp != NULL) {
            temp = tmp;
            tmp = tmp->next;
        }
        else {
            cout << "Wrong Index!"<<endl;
            return ;
        }
    }
    
    Node *goodbye = temp->next;
    temp->next = tmp->next;
    delete goodbye;
}

template <class T>
T Linklist<T>::visit(int index)
{
    Node *tmp = root;
    for (int i = 0;i < index;i++)
    {
        if (tmp != NULL)tmp = tmp->next;
    }
    
    if (tmp == NULL) cout << "Wrong Index!" <<endl;
    else {
        return tmp->data;
    }
}

template <class T>
void Linklist<T>::traverse()
{
    Node *tmp = root;
    while (tmp!=NULL)
    {
        cout << tmp->data << ' ';
        tmp = tmp->next;
    }
    cout << endl;
}

template <class T>
void Linklist<T>::add(T d)
{
    Node *tmp = root;
    while (tmp->next!=NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = new Node(d);
}

template <class T>
Linklist<T>::~Linklist()
{
    Node *tmp = root;
    while (tmp!=NULL)
    {
        tmp = tmp->next;
        delete root;
        root = tmp;
    }
}

int main()
{
    Linklist<int> a(3);
    a.insert(1,4);
    a.add(5);
    a.traverse();
    a.insert(1,7);
    a.traverse();
    a.remove(3);
    a.remove(1);
    a.traverse();
    cout << a.visit(1);
}
