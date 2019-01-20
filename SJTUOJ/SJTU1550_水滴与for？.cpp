#include <iostream>
#include <stack>
using namespace std;

 int min(int a,int b)
{
	return (a>=b ? b:a);
}

void water(int total,int data[])
{
	if (total==1)
	{
		cout << 0;
		return;
	}
	
	int start;
	for (int i = 0;i < total;i++)
	{
		if (data[i] == 0) continue;
		else
		{
			start = i;
			break;
		}
	}
	
	int num = data[start],sum = 0,max = data[start];
	int i = start;
	for (int i = start+1;i < total;i++)
	{
		 if (data[i] >= max)
		 {
		 	max = data[i];
		 	continue;
		 }
		 else
		 {
		 	int s_max = data[i];
		 	for (int j = i;j < total;j++)
		 	{
		 		if (data[j] > s_max) s_max = data[j];
			}
			sum+=min(s_max,max) - data[i];
			//cout << sum << endl;
		 }
	}
	cout << sum;
}

int main()
{
	int total;
	cin >> total;
	int *data;
	data = new int[total];
	int in;
	//a = cin.get(); 
	//cout << a << endl;
	cin.get();
	for (int i = 0;i < total;i++)
	{
		cin.get();
		cin >> in;
		data[i] = in;
		cout << data[i] << ' '; 
	}
	cout << endl;
	
	water(total,data);
}
