#include <iostream>
using namespace std;

template <class T>
class Queue
{
	private:
		T *data;
		int count;
		int maxsize;
		void doublespace();
	public:
		Queue(int initSize = 10);
		void push(const T &x);
		int size();
		T front() const;
		T back() const;
		T pop();
		bool isEmpty()const;
		void traverse() const;
		//~Queue() {delete []data;}
};

template <class T>
Queue<T>::Queue(int initSize)
{
	data = new T[initSize];
	count = -1;
	maxsize = 10;
}

template <class T>
T Queue<T>::front() const
{
	return data[0];
}

template <class T>
T Queue<T>::back() const
{
	return data[count];
}

template <class T>
bool Queue<T>::isEmpty()const
{
	return (count==-1);
} 
 
template <class T>
T Queue<T>::pop()
{
	T tmp = data[0];
	for (int i = 1;i < count+1;i++) data[i-1] = data[i];
	count--;
	return tmp;
}

template <class T>
void Queue<T>::push(const T &x)
{
	if (count>=maxsize-1) doublespace();
	data[++count] = x;
}

template <class T>
int Queue<T>::size()
{
	return (count+1);
}

template <class T>
void Queue<T>::traverse() const
{
	for (int i = 0;i < count+1;i++) cout << data[i] << ' ';
	cout << endl;
}

template <class T>
void Queue<T>::doublespace()
{
	T *tmp = data;
	data = new T[2*maxsize];
	for (int i = 0;i < count+1;i++) data[i] = tmp[i];
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
		~seqlist() {} 
		T *dataa;
		int Currentlength;
		int maxsize;
		void doubleSpace();
 }; 
 
template <class T>
void seqlist<T>::doubleSpace()
{
	T *tmp = dataa;
	dataa = new T[2*maxsize];
	if (!tmp) return;
	for (int i = 0;i < Currentlength;i++) dataa[i] = tmp[i];
	delete []tmp;
	maxsize = maxsize*2;
}
 
template <class T>
seqlist<T>::seqlist(int initSize)
{
 	dataa = new T[initSize];
 	if (!dataa) return;
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
		if (dataa[i] == x) return i;
	}
	return -1;
}

template <class T>
T seqlist<T>::visit(int i)
{
	if (i >= Currentlength || i < 0) cout << "Wrong input!" << endl;
	else return dataa[i];
}

template <class T>
void seqlist<T>::insert(int i, const T &x)
{
	if (i < 0 || i > Currentlength) return;
	if (Currentlength >= maxsize) doubleSpace();
	for (int j = Currentlength - 1;j >= i;j--) dataa[j+1] = dataa[j];
	dataa[i] = x;
	Currentlength++;
}

template <class T>
void seqlist<T>::remove(int i)
{
	if (i < 0 || i >= Currentlength) return;
	for (int j = i;j < Currentlength - 1;j++) dataa[j] = dataa[j+1];
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
	for (int i = 0;i < Currentlength;i++) cout << dataa[i] << ' ';
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
		void levelOrder(Node *t) const;
	public:
		BinaryTree():root(NULL){}
		BinaryTree(const T &value) {root = new Node(value);}
		BinaryTree(Node *p) {root = p;}
		//~BinaryTree() {clear();}
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
		void levelOrder() const {levelOrder(root);}
		void CreateTree(int n);
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
	if (t==NULL) return;
	else
	{
		cout << t->data << ' ';
		preOrder(t->left);
		preOrder(t->right);
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
	if (t==NULL) return;
	else
	{
		postOrder(t->left);
		postOrder(t->right);
		cout << t->data << ' ';
	}
}

template <class T>
void BinaryTree<T>::levelOrder(Node *t) const
{
	Queue<Node *> que;
	que.push(t);
	
	while (!que.isEmpty())
	{
		Node * tmp = que.pop();
		if (tmp->left!=NULL) que.push(tmp->left);
		if (tmp->right!=NULL) que.push(tmp->right);
		cout << tmp->data << ' ';
	}
}

template <class T>
void BinaryTree<T>::CreateTree(int n)
{
	seqlist<Node *> Tree(n);
	int ltree,rtree,d,total = n*(n+1)/2;
	Node *tmp;
	
	for (int i = 0;i < n;i++) Tree.dataa[i] = new Node();
	
	for (int i = 0;i < n;i++)
	{
		cin >> ltree >> rtree >> d;
		Tree.dataa[i]->data = d;
		if (ltree!=0) Tree.dataa[i]->left = Tree.dataa[ltree-1];
		if (rtree!=0) Tree.dataa[i]->right = Tree.dataa[rtree-1];
		total = total - ltree - rtree;
	}
	
	root = Tree.dataa[total-1];
}

int main()
{
	 BinaryTree<int> test;
	 int n;
	 cin >> n;
	 test.CreateTree(n);
	 test.levelOrder();
}
