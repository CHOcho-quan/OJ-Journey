//
//  BinarySearchTree_nonrecur.cpp
//  
//
//  Created by 铨 on 2019/3/28.
//
//

#include <iostream>
#include <iomanip>
#include <queue>

using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node *left;
    Node *right;
    Node(T d, Node *l = NULL, Node *r = NULL)
    {
        data = d;
        left = l;
        right = r;
    }
    Node() {}
};

template <class T>
class BinarySearchTree
{
private:
    Node<T> *root;
    void traverse(Node<T> *r);
public:
    BinarySearchTree() {}
    BinarySearchTree(Node<T> * r);
    void insert(T d);
    void remove(T d);
    bool find(T d);
    void traverse();
};

template <class T>
void BinarySearchTree<T>::traverse(Node<T> *r)
{
    if (r->left!=NULL) traverse(r->left);
    cout << r->data << ' ';
    if (r->right!=NULL) traverse(r->right);
}

template <class T>
BinarySearchTree<T>::BinarySearchTree(Node<T> *r)
{
    root = r;
}

template <class T>
void BinarySearchTree<T>::insert(T d)
{
    Node<T> *tmp = root;
    while (true)
    {
        if (tmp->data > d)
        {
            if (tmp->left!=NULL) tmp = tmp->left;
            else {
                tmp->left = new Node<T>(d);
                break;
            }
        }
        else
        {
            if (tmp->right!=NULL) tmp = tmp->right;
            else {
                tmp->right = new Node<T>(d);
                break;
            }
        }
    }
}

template <class T>
void BinarySearchTree<T>::remove(T d)
{
    bool flag = true;
    Node<T> *tmp = root;
    Node<T> *tmp_l = tmp;
    if (!find(d)) {
        cout << "Data didn't exist!" << endl;
        return ;
    }
    else {
        while (true)
        {
            if (tmp->data > d) {
                tmp_l = tmp;
                tmp = tmp->left;
                flag = false;
                continue;
            }
            if (tmp->data < d) {
                tmp_l = tmp;
                tmp = tmp->right;
                flag = true;
                continue;
            }
            if (tmp->data == d) {
                if (tmp->right==NULL && tmp->left==NULL) {
                    if (flag) {
                        tmp_l->right = NULL;
                        delete tmp;
                    }
                    else {
                        tmp_l->left = NULL;
                        delete tmp;
                    }
                }
                else {
                    if (tmp->right!=NULL)
                    {
                        Node<T> *del = tmp->right;
                        while (del->left!=NULL) {del = del->left;}
                        tmp->data = del->data;
                        delete del;
                    }
                    else {
                        Node<T> *del = tmp->left;
                        while (del->right!=NULL) {del = del->right;}
                        tmp->data = del->data;
                        delete del;
                    }
                }
                break;
            }
        }
    }
}

template <class T>
bool BinarySearchTree<T>::find(T d)
{
    Node<T> *tmp = root;
    while (true)
    {
        if (tmp->data == d) return true;
        if (tmp->data > d)
        {
            if (tmp->left!=NULL) tmp = tmp->left;
            else return false;
        }
        else {
            if (tmp->right!=NULL) tmp = tmp->right;
            else return false;
        }
    }
}

template <class T>
void BinarySearchTree<T>::traverse() {traverse(root);}

int main()
{
    Node<int> *tmp = new Node<int>(1);
    BinarySearchTree<int> a(tmp);
    a.insert(2);
    a.insert(5);
    a.insert(4);
    a.insert(3);
    a.remove(3);
    cout << a.find(2) << endl;
    cout << a.find(3) << endl;
    a.traverse();
}
