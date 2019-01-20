#include <iostream>
#include <stack>
using namespace std;

class Run
{
	public:
		int distance;
		int velocity;
		Run(int a,int b)
		{
			distance = a;
			velocity = b;
		}
		void next_minute()
		{
			distance+=velocity;
		}
};

int min(int a,int b)
{
	if (a >= b) return b;
	else return a;
}

void team(int n)
{	
	int p,v,last_p,last_v;
	stack<int> st;
	cin >> p >> v;
	last_p = p;
	st.push(v);
	
	for (int i = 1;i < n;i++)
	{
		cin >> p >> v;
		if (p==last_p)
		{
			int tmp = min(st.top(),v);
			st.pop();
			st.push(tmp);
		}
		else
		{
			if (v >= st.top()) st.push(v);
			else
			{
				int tmp = min(st.top(),v);
				st.pop();
				st.push(tmp);
			}
		}
		last_p = p;
	}
	
	int sum = 0;
	int then = -1;
	while (!st.empty())
	{
		int now = st.top();
		sum++;
		cout << now << endl; 
		st.pop();
		if (now > then && then!=-1) sum--;
		if (then!=-1) then = min(now,then);
		else then = now;
	}
	cout << sum;
	
}

int main()
{
	int n;
	cin >> n;
	team(n);
} 
