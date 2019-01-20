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

void ferry(int n)
{
	Linkqueue<int> hc,kc;
	int c,t,num = 0,hcw = 0,kcw = 0,bc = 0;
	for (int i = 0;i < n;i++)
	{
		cin >> c >> t;
		if (c==0) kc.push(t);
		else hc.push(t);
	}
	
	int hcl = hc.size(),kcl = kc.size();
	
	while (1)
	{
		if (!(num%4) && num!=0)
		{
			if (!hc.isEmpty())
			{
				if (hc.front() <= bc*10)
				{
					hcw+=bc*10 - hc.front();
					hc.pop();
					num++;
				}
			}
		}
		while (1)
		{
			if (kc.isEmpty() || kc.front() > bc*10)
			{
				if (!hc.isEmpty())
				{
					if (hc.front() <= bc*10)
					{
						hcw+=bc*10 - hc.front();
						hc.pop();
						num++;
						if (num==10)
						{
							num = 0;
							bc++;
							break;
						}
					}
					else
					{
						bc++;
						num = 0;
						break;
					}
				}
				else
				{
					if (kc.isEmpty()) break;
					else
					{
						if (kc.front() > bc*10)
						{
							bc++;
							num = 0;
							break; 
						}
					}
				}
			}
			else break;
		}
		if (!kc.isEmpty())
		{
			if (kc.front() <= bc*10)
			{
				kcw+=bc*10 - kc.front();
				kc.pop();
				num++;
				if (num==10)
				{
					num = 0;
					bc++;
				}
			}
		}
		if (kc.isEmpty() && hc.isEmpty()) break;
	}
	cout << fixed << setprecision(3) << double(kcw)/kcl << ' ' << fixed << setprecision(3) << double(hcw)/hcl;
}

int main()
{
	int n;
	cin >> n;
	ferry(n);
}








