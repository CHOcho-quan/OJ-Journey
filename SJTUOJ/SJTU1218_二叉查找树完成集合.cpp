//
//  1218_二叉查找树完成集合.cpp
//  
//
//  Created by 铨 on 18/5/8.
//
//
#include <iostream>

using namespace std;

template <class T>
class BinarySearchTree {
private:
    struct Node {
        T data;
        Node *left;
        Node *right;
        Node(const T & datai,Node*lt,Node*rt):data(datai),left(lt),right(rt) {}
    };
    Node * root;
    void insert(const T&x,Node *&t) const;
    void remove(const T&x,Node *&t) const;
    bool find(const T&x,Node *t) const;
    void midOrder(Node *&t);
    
public:
    BinarySearchTree(Node *rt = NULL):root(rt) {}
    ~BinarySearchTree() {};
    void midOrder();
    bool find(const T &x) const;
    void insert(const T &x);
    void remove(const T &x);
};

template <class T>
void BinarySearchTree<T>::midOrder(Node *&t)
{
    if (t==NULL) return;
    midOrder(t->left);
    cout << t->data << ' ';
    midOrder(t->right);
}

template <class T>
void BinarySearchTree<T>::midOrder()
{
    midOrder(root);
}

template <class T>
void BinarySearchTree<T>::remove(const T &x, Node *&t) const
{
    if (t == NULL) return ;
    if (x > t->data)
    {
        remove(x,t->right);
        return ;
    }
    if (x < t->data)
    {
        remove(x,t->left);
        return ;
    }
    if (x == t->data)
    {
        if (t->left == NULL && t->right == NULL)
        {
            t = NULL;
            return ;
        }
        if (t->right != NULL && t->left == NULL)
        {
            t = t->right;
            return ;
        }
        if (t->left != NULL && t->right == NULL)
        {
            t  = t->left;
            return ;
        }
        if (t->left != NULL && t->right != NULL)
        {
            Node *tmp = t->left;
            while (tmp->right!=NULL) tmp = tmp->right;
            t->data = tmp->data;
            remove(t->data,t->left);
        }
    }
}

template <class T>
void BinarySearchTree<T>::remove(const T &x)
{
    remove(x,root);
}

template <class T>
bool BinarySearchTree<T>::find(const T &x, Node *t) const
{
    if (t == NULL) return false;
    if (x == t->data) return true;
    if (x > t->data) return find(x,t->right);
    if (x < t->data) return find(x,t->left);
}

template <class T>
bool BinarySearchTree<T>::find(const T &x) const
{
    return find(x,root);
}

template <class T>
void BinarySearchTree<T>::insert(const T &x, Node *&t) const
{
    if (t==NULL)
    {
        t = new Node(x,NULL,NULL);
        return ;
    }
    if (x > t->data)
    {
        insert(x,t->right);
        return ;
    }
    if (x < t->data)
    {
        insert(x,t->left);
        return ;
    }
}

template <class T>
void BinarySearchTree<T>::insert(const T &x)
{
    insert(x,root);
}

int main() {
    BinarySearchTree<int> test;
    int n,m,t;
    char a;
    cin >> n;
    
    for (int i = 0;i < n;i++)
    {
        cin >> a;
        switch (a)
        {
            case '+':{
                cin >> m;
                for (int j = 0;j < m;j++)
                {
                    cin >> t;
                    test.insert(t);
                }
                break;
            }
            case '-':{
                cin >> m;
                for (int j = 0;j < m;j++)
                {
                    cin >> t;
                    test.remove(t);
                }
                break;
            }
            case '*':{
                cin >> m;
                BinarySearchTree<int> tmp;
                for (int j = 0;j < m;j++)
                {
                    cin >> t;
                    if (test.find(t)) tmp.insert(t);
                }
                test = tmp;
                break;
            }
        }
        test.midOrder();
        cout << endl;
    }
    
    return 0;
}
