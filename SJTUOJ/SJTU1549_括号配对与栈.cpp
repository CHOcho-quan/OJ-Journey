#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int Match()
{
	char *data;
	data = new char[100];
	int a[100] = {0};
	cin.getline(data,101);
	cout << data << endl;
	stack<int> st;
	int label = -1;
	
	for (int i = 0;i < strlen(data);i++)
	{
		if (data[i]=='(')
		{
			label = i;
			break;
		}
		if (data[i]==')') cout << '?';
		else cout << ' ';
	}

	if (label==-1) return 1;
	else
	{
		bool flag = false;
		for (int i = label;i < strlen(data);i++)
		{
			if (flag)
			{
				if (data[i]==')')
				{
					st.pop();
				}
				else if (data[i]=='(') 
					{
						st.push(i);
					}
			}
			else
			{
				if (data[i]=='(') 
				{
					st.push(i);
				}
				else {
					if (data[i]==')')
					{
						a[i] = 1;
					}
				}
			}
			if (st.empty()) flag = false;
			else flag = true;
		}
		while (!st.empty())
		{
			int temp = st.top();
			st.pop();
			a[temp] = -1;
		}
	}
	for (int i = label;i < strlen(data);i++)
	{
		if (a[i]==0) cout << ' ';
		if (a[i]==-1) cout << '$';
		if (a[i]==1) cout << '?';
	}
}

int main()
{
	Match();
}
