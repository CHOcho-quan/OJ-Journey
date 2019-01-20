#include <iostream>
using namespace std;

template <class T>
class Stack
{
private:
    int topa;
    int maxsize;
    T *data;
    void doubleSpace();
public:
    Stack(int initSize=10);
    bool isEmpty() const;
    void push(const T &x);
    T pop();
    T top() const;
    ~Stack() {delete []data;}
};

template <class T>
Stack<T>::Stack(int initSize)
{
    topa = -1;
    maxsize = initSize;
    data = new T[maxsize];
}

template <class T>
bool Stack<T>::isEmpty() const
{
    return (topa==-1);
}

template <class T>
void Stack<T>::push(const T &x)
{
    if (topa==maxsize-1) doubleSpace();
    data[++topa] = x;
}

template <class T>
T Stack<T>::pop()
{
    return data[topa--];
}

template <class T>
T Stack<T>::top() const
{
    return data[topa];
}

template <class T>
void Stack<T>::doubleSpace()
{
    T *tmp = data;
    data = new T[2*maxsize];
    maxsize = 2*maxsize;
    for (int i = 0;i < maxsize;++i)
    {
        data[i] = tmp[i];
    }
    delete tmp;
}

template <class T>
class seqlist
{
public:
    seqlist(int initSize = 10);
    int length() const;
    int search(const T &x) const;
    T visit(int i);
    void insert(int i, const T &x);
    void remove(int i);
    void clear();
    void traverse() const;
    T &operator[] (int index);
    ~seqlist() {}
private:
    T *data;
    int Currentlength;
    int maxsize;
    void doubleSpace();
};

template <class T>
void seqlist<T>::doubleSpace()
{
    T *tmp = data;
    data = new T[2*maxsize];
    if (!tmp) return;
    for (int i = 0;i < Currentlength;i++) data[i] = tmp[i];
    delete []tmp;
    maxsize = maxsize*2;
}

template <class T>
seqlist<T>::seqlist(int initSize)
{
    data = new T[initSize];
    if (!data) return;
    maxsize = initSize;
    Currentlength = 0;
}

template <class T>
int seqlist<T>::length() const
{
    return Currentlength;
}

template <class T>
int seqlist<T>::search(const T &x) const
{
    for (int i = 0;i < Currentlength;i++)
    {
        if (data[i] == x) return i;
    }
    return -1;
}

template <class T>
T seqlist<T>::visit(int i)
{
    if (i >= Currentlength || i < 0) cout << "Wrong input!" << endl;
    else return data[i];
}

template <class T>
void seqlist<T>::insert(int i, const T &x)
{
    if (i < 0 || i > Currentlength) return;
    if (Currentlength >= maxsize) doubleSpace();
    for (int j = Currentlength - 1;j >= i;j--) data[j+1] = data[j];
    data[i] = x;
    Currentlength++;
}

template <class T>
void seqlist<T>::remove(int i)
{
    if (i < 0 || i >= Currentlength) return;
    for (int j = i;j < Currentlength - 1;j++) data[j] = data[j+1];
    Currentlength--;
}

template <class T>
void seqlist<T>::clear()
{
    Currentlength = 0;
}

template <class T>
void seqlist<T>::traverse() const
{
    for (int i = 0;i < Currentlength;i++) cout << data[i] << ' ';
}

template <class T>
T &seqlist<T>::operator[] (int index)
{
    if (index < maxsize) return data[index];
    else cout << "Wrong input!";
}

template <class T>
class Linkqueue
{
    struct Node
    {
        T data;
        Node *next;
        Node():next(NULL){}
        Node(T x,Node *p = NULL)
        {
            data = x;
            next = p;
        }
        Node(const Node &t)
        {
            data = t.data;
            next = t.next;
        }
        ~Node(){}
    };
private:
    Node *head;
public:
    Linkqueue()
    {
        head = new Node();
    }
    bool isEmpty() const;
    T front() const;
    T pop();
    int size() const;
    void push(const T &x);
    T bottom() const;
    ~Linkqueue()
    {
        Node *tmp = head;
        while (head->next!=NULL)
        {
            head = head->next;
            delete tmp;
            tmp = head;
        }
    }
};

template <class T>
bool Linkqueue<T>::isEmpty() const
{
    return (head->next==NULL);
}

template <class T>
T Linkqueue<T>::front() const
{
    return (head->next->data);
}

template <class T>
int Linkqueue<T>::size() const
{
    int size = 0;
    Node *temp = head->next;
    while (temp!=NULL)
    {
        size++;
        temp = temp->next;
    }
    return size;
}

template <class T>
T Linkqueue<T>::pop()
{
    Node *temp = head->next;
    head->next = temp->next;
    return temp->data;
}

template <class T>
T Linkqueue<T>::bottom() const
{
    Node *temp = head;
    while (temp->next!=NULL)
    {
        temp = temp->next;
    }
    return temp->data;
}

template <class T>
void Linkqueue<T>::push(const T &x)
{
    Node *New;
    New = new Node(x);
    Node *temp = head;
    while (temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = New;
}

int max(int a,int b)
{
    if (a >= b) return a;
    else return b;
}

template <class T>
class BinaryTree
{
private:
    struct Node {
        Node *left;
        Node *right;
        T data;
        Node():left(NULL),right(NULL){}
        Node(T datai,Node *lefti = NULL,Node *righti=NULL)
        {
            data = datai;
            left = lefti;
            right = righti;
        }
        ~Node(){}
    };
    Node *root;
    void clear(Node *t);
    int height(Node *t) const;
    int size(Node *t) const;
    void preOrder(Node *t) const;
    void postOrder(Node *t) const;
    void midOrder(Node *t) const;
public:
    BinaryTree():root(NULL){}
    BinaryTree(const T &value) {root = new Node(value);}
    BinaryTree(Node *p) {root = p;}
    ~BinaryTree() {clear();}
    T getRoot() const { return root->data;}
    T getLeft() const { return root->left->data;}
    T getRight() const { return root->right->data;}
    void makeTree(const T &x,BinaryTree &lt,BinaryTree &rt) {root = new Node(x,lt.root,rt.root);}
    void delLeft()
    {
        BinaryTree tmp = root->left;
        root->left = NULL;
        delete tmp;
    }
    void delRight()
    {
        BinaryTree tmp = root->right;
        root->right = NULL;
        delete tmp;
    }
    bool isEmpty() {return (root==NULL);}
    void clear()
    {
        if (root==NULL) return;
        else clear(root);
    }
    int size() const {return size(root);}
    int height() const {return height(root);}
    void preOrder() const {preOrder(root);}
    void midOrder() const {midOrder(root);}
    void postOrder() const {postOrder(root);}
    void levelOrder() const;
    void CreateTree(T flag);
    void createTree(int n);
};

template <class T>
void BinaryTree<T>::clear(Node *t)
{
    if (t==NULL) return;
    else
    {
        clear(t->left);
        clear(t->right);
        delete t;
    }
}

template <class T>
int BinaryTree<T>::height(Node *t) const
{
    if (t==NULL) return 0;
    else return max(height(t->left),height(t->right))+1;
}

template <class T>
int BinaryTree<T>::size(Node *t) const
{
    if (t==NULL) return 0;
    else return size(t->left) + size(t->right) + 1;
}

template <class T>
void BinaryTree<T>::preOrder(Node *t) const
{
    Stack<Node*> st(100000);
    st.push(root);

    while (!st.isEmpty())
    {
        Node *tmp = st.pop();
        cout << tmp->data << ' ';
        if (tmp->right!=NULL) st.push(tmp->right);
        if (tmp->left!=NULL) st.push(tmp->left);
    }
}

template <class T>
void BinaryTree<T>::midOrder(Node *t) const
{
    if (t==NULL) return;
    else
    {
        midOrder(t->left);
        cout << t->data << ' ';
        midOrder(t->right);
    }
}

template <class T>
void BinaryTree<T>::postOrder(Node *t) const
{
    if (t->left!=NULL) postOrder(t->left);
    cout << t->data << ' ';
    if (t->right!=NULL) postOrder(t->right);
}

template <class T>
void BinaryTree<T>::levelOrder() const
{
    Linkqueue<Node*> que;
    que.push(root);

    while (!que.isEmpty())
    {
        Node* tmp = que.front();
        while (tmp!=NULL)
        {
            if (tmp->left!=NULL) que.push(tmp->left);
            cout << tmp->data << ' ';
            tmp = tmp->right;
        }
        que.pop();
    }
}

template <class T>
void BinaryTree<T>::CreateTree(T flag)
{
    Linkqueue<Node*> que;
    Node *tmp;
    T ldata,rdata,x;
    cin >> x;
    root = new Node(x);
    que.push(root);

    while (!que.isEmpty())
    {
        tmp = que.pop();
        if (tmp!=NULL)
        {
            cin >> ldata >> rdata;
            if (ldata!=flag)
            {
                tmp->left = new Node(ldata);
                que.push(tmp->left);
            }
            if (rdata!=flag)
            {
                tmp->right = new Node(rdata);
                que.push(tmp->right);
            }
        }
    }
}

template <class T>
void BinaryTree<T>::createTree(int n)
{
    seqlist<Node *> Tree(n);
    int ltree, rtree, d,total = n*(n+1)/2;
    for (int i = 0;i < n;i++) Tree[i] = new Node();
    for (int i = 0;i < n;i++)
    {
        cin >> ltree >> rtree >> d;
        Tree[i]->data = d;
        if (ltree!=0)
        {
            Tree[i]->left = Tree[ltree-1];
            total-=ltree;
        }
        if (rtree!=0)
        {
            Tree[i]->right = Tree[rtree-1];
            total-=rtree;
        }
    }
    root = Tree[total-1];
}

int main() {
    int n;
    BinaryTree<int> test;
    cin >> n;

    test.createTree(n);
    test.preOrder();
    cout << endl;
    test.postOrder();
    cout << endl;
    test.levelOrder();
    return 0;
}