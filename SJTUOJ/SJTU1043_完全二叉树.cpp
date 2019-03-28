//
//  SJTU1043_完全二叉树.cpp
//  
//
//  Created by 铨 on 2019/3/27.
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
    Node *left;
    Node *right;
    T data;
    Node() {}
    Node(T d, Node *l = NULL, Node *r = NULL) {
        data = d;
        left = l;
        right = r;
    }
};

template <class T>
class BinaryTree
{
private:
    Node<T> *root;
    void postOrder(Node<T> *r)
    {
        if (r->right!=NULL) postOrder(r->right);
        cout << r->data << ' ';
        if (r->left!=NULL) postOrder(r->left);
    }
    void preOrder(Node<T> *r)
    {
        if (r->left!=NULL) preOrder(r->left);
        cout << r->data << ' ';
        if (r->right!=NULL) preOrder(r->right);
    }
    void midOrder(Node<T> *r)
    {
        cout << r->data << ' ';
        if (r->left!=NULL) midOrder(r->left);
        if (r->right!=NULL) midOrder(r->right);
    }
    int height(Node<T> *r)
    {
        if (r->left!=NULL && r->right==NULL) return 1+height(r->left);
        if (r->left==NULL && r->right!=NULL) return 1+height(r->right);
        if (r->left==NULL && r->right==NULL) return 0;
        if (r->left!=NULL && r->right!=NULL) return max(1+height(r->right), 1+height(r->left));
    }
    int size(Node<T> *r)
    {
        if (r==NULL) return 0;
        return size(r->left) + size(r->right) + 1;
    }
public:
    BinaryTree(Node<T> *r);
    //    BinaryTree() {}
    void postOrder();
    void preOrder();
    void midOrder();
    void stageOrder();
    int height();
    int size();
    bool isComplete(int n);
};

template <class T>
BinaryTree<T>::BinaryTree(Node<T> *r) {root = r;}

template <class T>
void BinaryTree<T>::postOrder()
{
    postOrder(root);
}

template <class T>
void BinaryTree<T>::preOrder()
{
    preOrder(root);
}

template <class T>
void BinaryTree<T>::midOrder()
{
    preOrder(root);
}

template <class T>
void BinaryTree<T>::stageOrder()
{
    queue<Node<T>*> q;
    q.push(root);
    while (!q.empty())
    {
        Node<T> *tmp = q.front();
        q.pop();
        cout << tmp->data << ' ';
        if (tmp->left != NULL) q.push(tmp->left);
        if (tmp->right != NULL) q.push(tmp->right);
    }
}

template <class T>
int BinaryTree<T>::height()
{
    return height(root);
}

template <class T>
int BinaryTree<T>::size()
{
    return size(root);
}

template <class T>
bool BinaryTree<T>::isComplete(int n)
{
    queue<Node<T>*> q;
    q.push(root);
    n--;
    
    while (!q.empty())
    {
        Node<T> *tmp = q.front();
        q.pop();
        if (tmp->left != NULL) {
            q.push(tmp->left);
            n--;
        }
        else {
            return n==0;
        }
        if (tmp->right != NULL) {
            q.push(tmp->right);
            n--;
        }
        else {
            return n==0;
        }
    }
}

int main()
{
    int n, tmp;
    cin >> n;
    Node<int> **t;
    t = new Node<int>*[n];
    for (int i = 0;i < n;i++) t[i] = new Node<int>(i);
    for (int i = 1;i < n;i++)
    {
        cin >>tmp;
        if (t[tmp]->left==NULL) t[tmp]->left = t[i];
        else t[tmp]->right = t[i];
    }
    BinaryTree<int> bt(t[0]);
    if (bt.isComplete(n))
    {
        cout << "true";
    }
    else cout << "false";
}
