#include <iostream>

using namespace std;

template <class T>
class seqlist
{
	public:
		seqlist(int initSize = 10);
		void insert(int i, const T &x);
		void remove(int i);
		T &operator[](int x);
		~seqlist() {} 
		T *data;
		int star;
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
 	for (int i = 0;i < initSize;i++) data[i] = 0;
 	if (!data) return;
 	maxsize = initSize;
 	Currentlength = 0;
 	star = 0;
}

template <class T>
void seqlist<T>::insert(int i, const T &x)
{
	if (Currentlength >= maxsize) doubleSpace();
	for (int j = Currentlength - 1;j >= i;j--) data[j+1] = data[j];
	data[i] = x;
	if (i < Currentlength) star = i;
	else star = i%Currentlength;
	Currentlength++;
}

template <class T>
void seqlist<T>::remove(int i)
{
	for (int j = i;j < Currentlength-1;j++) 
	{
		data[j] = data[j+1];
	}
	if (i < Currentlength) star = i;
	else star = i % Currentlength;
	Currentlength--;
}

template <class T>
T &seqlist<T>::operator[](int x)
{
	return data[x];
}

int Monkey(int m,int n)
{
	int z;
	seqlist<int> d(20000);
	for (int i = 0;i < m;i++) d.data[i] = i+1;//³õÊ¼»¯ºï×Ó
	d.Currentlength = m;
	
	//for (int i = 0;i < m;i++) cout << d.data[i];
	
	for (int i = 0;i < n;i++)
	{
		cin >> z;
		switch(z)
		{
			case 0:{
				int t;
				cin >> t;
				d.remove(d.star+t-1 >= d.Currentlength ? (d.star+t-1)%d.Currentlength:d.star+t-1);
				break;
			}
			case 1:{
				int u,b;
				cin >> u >> b; 
				d.insert(d.star+u >= d.Currentlength ? (d.star+u)%d.Currentlength:d.star+u,b);
				break;
			}
	 	} 
	}
	int sum = 0;
	for (int i = 0;i < d.Currentlength;i++)
	{
		sum+=d.data[i];
		//sum+=d.data[i];
	}
	cout << sum;
}

int main()
{
	int m,n;
	cin >> m >> n;
	Monkey(m,n);
}


