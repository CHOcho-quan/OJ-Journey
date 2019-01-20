//
//  1221_二叉查找树操作.cpp
//  
//
//  Created by 铨 on 18/5/8.
//
//

#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

template <class T>
class BinarySearchTree {
private:
    struct Node {
        T data;
        Node *left;
        Node *right;
        int num;
        Node(const T & datai,Node*lt,Node*rt):data(datai),left(lt),right(rt) {}
    };
    Node * root;
    int currentlength;
    void insert(const T&x,Node *&t) const;
    void remove(const T&x,Node *&t);
    bool find(const T&x,Node *t) const;
    void midOrder(Node *&t);
    void delete_less_than(const T&x,Node *&t);
    void delete_greater_than(const T&x,Node *&t);
    void delete_interval(const T&x,const T&y,Node *&t);
    T find_ith(const T&x,Node *t);
    
public:
    BinarySearchTree(Node *rt = NULL):root(rt) {currentlength = 0;}
    ~BinarySearchTree() {};
    T midOrder();
    bool find(const T &x) const;
    void insert(const T &x);
    void remove(const T &x);
    void delete_less_than(const T&x);
    void delete_greater_than(const T&x);
    void delete_interval(const T&x,const T&y);
    int height(Node *t);
    T find_ith(const T&x);
    void getSort(vector<T> &result,Node *t);
};

template <class T>
void BinarySearchTree<T>::getSort(vector<T> &result, BinarySearchTree<T>::Node *t)
{
    Node *temp = t;
    stack<Node*> st;
    while (!st.empty() || temp!=NULL)
    {
        if (temp==NULL) {
            Node *tmp = st.top();
            st.pop();
            result.push_back(tmp->data);
            temp = tmp->right;
        }
        else {
            st.push(temp);
            temp = temp->left;
        }
    }
}

template <class T>
int BinarySearchTree<T>::height(BinarySearchTree<T>::Node *t)
{
    if (t == NULL) return 0;
    return max(1+height(t->left),1+height(t->right));
}

template <class T>
T BinarySearchTree<T>::find_ith(const T &x, BinarySearchTree<T>::Node *t)
{
    vector<T> result;
    getSort(result,root);
    if (x < 1 || x > result.size()) cout << 'N' << endl;
    else cout << result[x - 1] << endl;
}

template <class T>
T BinarySearchTree<T>::find_ith(const T &x)
{
    return find_ith(x,root);
}

template <class T>
void BinarySearchTree<T>::delete_interval(const T &x,const T &y,Node *&t)
{
    if (t==NULL) return;
    if (t->data > x && t->data < y)
    {
        remove(t->data,t);
        delete_interval(x,y,root);
    }
    else if (t->data >= y) delete_interval(x,y,t->left);
    else if (t->data <= x) delete_interval(x,y,t->right);
}

template <class T>
void BinarySearchTree<T>::delete_interval(const T &x,const T &y)
{
    delete_interval(x,y,root);
}

template <class T>
void BinarySearchTree<T>::delete_less_than(const T &x,Node *&t)
{
    if (t==NULL) return;
    if (t->data < x)
    {
        Node *rt = t->right;
        Node *lt = t->left;
        remove(t->data,t);
        delete_less_than(x,root);
    }
    else delete_less_than(x,t->left);
}

template <class T>
void BinarySearchTree<T>::delete_less_than(const T &x)
{
    delete_less_than(x,root);
}

template <class T>
void BinarySearchTree<T>::delete_greater_than(const T &x,Node *&t)
{
    if (t==NULL) return;
    if (t->data > x)
    {
        remove(t->data,t);
        delete_greater_than(x,root);
    }
    else delete_greater_than(x,t->right);
}

template <class T>
void BinarySearchTree<T>::delete_greater_than(const T &x)
{
    delete_greater_than(x,root);
}

template <class T>
void BinarySearchTree<T>::midOrder(Node *&t)
{
    if (t==NULL)  return;
    midOrder(t->left);
    cout << t->data << ' ';
    midOrder(t->right);
    
}

template <class T>
T BinarySearchTree<T>::midOrder()
{
    midOrder(root);
}

template <class T>
void BinarySearchTree<T>::remove(const T &x, Node *&t)
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
            currentlength--;
            t = NULL;
            return ;
        }
        if (t->right != NULL && t->left == NULL)
        {
            currentlength--;
            t = t->right;
            return ;
        }
        if (t->left != NULL && t->right == NULL)
        {
            currentlength--;
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
    if (x >= t->data)
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
    currentlength++;
    insert(x,root);
}

int main() {
    BinarySearchTree<int> test;
    string in;
    int n,x,y;
    cin >> n;
    
    for (int i = 0;i < n;i++)
    {
        cin >> in;
        if (in == "insert")
        {
            cin >> x;
            test.insert(x);
        }
        if (in == "delete")
        {
            cin >> x;
            test.remove(x);
        }
        if (in == "delete_less_than")
        {
            cin >> x;
            test.delete_less_than(x);
        }
        if (in == "delete_greater_than")
        {
            cin >> x;
            test.delete_greater_than(x);
        }
        if (in == "delete_interval")
        {
            cin >> x >> y;
            test.delete_interval(x,y);
        }
        if (in == "find")
        {
            cin >> x;
            if (test.find(x)) cout << 'Y' << endl;
            else cout << 'N' << endl;
        }
        if (in == "find_ith")
        {
            cin >> x;
            test.find_ith(x);
        }
        //test.midOrder();
        //cout << endl;
    }
    
    //return 0;
}
