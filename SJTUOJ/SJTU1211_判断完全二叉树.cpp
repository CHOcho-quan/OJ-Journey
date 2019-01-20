#include <iostream>
#include <iomanip>
using namespace std;

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
		void isComplete();
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
	Linkqueue<Node *> que;
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
	int ltree,rtree,total = n*(n+1)/2;
	Node *tmp;
	
	for (int i = 0;i < n;i++) Tree.dataa[i] = new Node();
	
	for (int i = 0;i < n;i++)
	{
		cin >> ltree >> rtree;
		if (ltree!=0) Tree.dataa[i]->left = Tree.dataa[ltree-1];
		if (rtree!=0) Tree.dataa[i]->right = Tree.dataa[rtree-1];
		total = total - ltree - rtree;
	}
	
	root = Tree.dataa[total-1];
}

template <class T>
void BinaryTree<T>::isComplete()
{
	Linkqueue<Node *> que;
	que.push(root);
	Node *tmp;
	bool flag = true;
	
	while (!que.isEmpty())
	{
		tmp = que.pop();
		if (tmp->left!=NULL)
		{
			if (!flag)
			{
				cout << 'N';
				return ;
			}
			if (tmp->right!=NULL)
			{
				que.push(tmp->left);
				que.push(tmp->right);
			}
			else flag = false;
		}
		else
		{
			if (tmp->right!=NULL)
			{
				cout << 'N';
				return ;
			}
			else flag = false;
		}
	}
	cout << 'Y';
}

int main()
{
	BinaryTree<int> test;
	int n;
	cin >> n;
	test.CreateTree(n);
	test.isComplete();
	return 1;
}
