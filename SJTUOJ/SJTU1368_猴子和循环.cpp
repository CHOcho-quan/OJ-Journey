#include <iostream>
using namespace std;

template <class T>
class Linklist 
{
	struct Node
	{
		Node *next;
		T data;
		Node(T x,Node *p = NULL) {data = x;next = p;}
		Node():next(NULL){}
		~Node() {}
	};
	public:
		Node *head;
		Linklist();
		Linklist(T x);
		~Linklist() {}
		void insert(int i,const T &x);
		void remove(int i);
		void add(T x);
};

template <class T>
Linklist<T>::Linklist()
{
	head = new Node();
}

template <class T>
Linklist<T>::Linklist(T x)
{
	head = new Node(x);
	head->next = head;
}
 
template <class T>
void Linklist<T>::insert(int i,const T &x)
{
	Node *p = head;
	while (1)
	{
		if (i==1)
		{
			if (p->next!=head)
			{
				Node *q;
				q = new Node(x);
				q->next = p->next;
				p->next = q;
				head = q;
				return;
			}
			else
			{
				Node *q;
				q = new Node(x); 
				p->next = q;
				q->next = head;
				head = q;
				return;
			}	
		}
		i--;
		if (p->next!=head) p = p->next;
	}
}

template <class T>
void Linklist<T>::remove(int i)
{
	Node *p = head;
	if (i==1)
	{
		while (p->next!=head)
		{
			p = p->next;
		}
		Node *q = head;
		p->next = q->next;
		head = q->next;
		delete q;
	}
	else
	{
		while (p->next!=head)
		{
			i--;
			if (i==1)
			{
				Node *q = p->next;
				p->next = q->next;
				head = p->next;
				delete q;
				break; 
			}
			p = p->next;
		}
	}
}

template <class T>
void Linklist<T>::add(T x)
{
	Node *q,*p = head;
	q = new Node(x);
	while (p->next!=head)
	{
		p = p->next;
	}
	p->next = q;
	q->next = head;
}

int Monkey(int num,int order)
{
	Linklist<int> monkeys(1);
	for (int i = 2;i <= num;i++) monkeys.add(i);//³õÊ¼»¯ºï×Ó
	int count_order = 0;
	
	while (count_order != order)
	{
		count_order++;
		int z;
		cin >> z;
		switch(z)
		{
			case 0:{
				int n;
				cin >> n;
				monkeys.remove(n);
				num--;
				break;
			}
			case 1:{
				int m,n;
				cin >> n >> m;
				monkeys.insert(n,m);
				num++;
				break;
			}
		}
	}
	int sum = 0;
	for (int i = 0;i < num;i++)
	{
		sum+=monkeys.head->data;
		if (monkeys.head->next!=NULL) monkeys.head = monkeys.head->next;
	}
	cout << sum;
} 

int main()
{
	int num,order;
	cin >> num >> order;
	Monkey(num,order);
}
