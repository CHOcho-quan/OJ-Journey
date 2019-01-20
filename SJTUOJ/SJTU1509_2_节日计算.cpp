#include <iostream>
using namespace std;

void output(int y,int m,int d)
{
	cout << y << '/';
	if (m >=10) cout << m << '/';
	else cout << 0 << m << '/';
	if (d >=10) cout << d << endl;
	else cout << 0 << d << endl;
}

int first_day(int i)
{
	int days = 0;
	
	for (int j = 1850;j < i;j++)
	{
		days+=365 + ((j%400==0) || (j%4==0 && j%100!=0));
	}
	
	if (days%7+2 > 7) return 1;
	else return (days%7+2);
}

void when(int a,int b,int c,int first,int y)
{
	int month[]= {31,28,31,30,31,30,31,31,30,31,30,31};
	int monthr[] = {31,29,31,30,31,30,31,31,30,31,30,31};
	int days = 0;
	
	if ((y%400==0) || (y%4==0 && y%100!=0)) //run year
	{
		int days = 0,first_im;
		for (int i = 0;i < a-1;i++) days+=monthr[i];
		if (days%7+first > 7) first_im = (days%7 + first)%7==0 ? 7:(days%7 + first)%7;
		else first_im = days%7+first;
		//first day of the month
		
		int first_xq_days = 8 - first_im;
		switch(b)
		{
			case 1:{
				if (c < first_im) cout << "none" << endl;
				else output(y,a,c-first_im+1);
				break;
			}
			case 2:{
				int sum_days = first_xq_days + c;
				output(y,a,sum_days);
				break;
			}
			case 3:{
				int sum_days = first_xq_days + 7 + c;
				output(y,a,sum_days);
				break;
			}
			case 4:{
				int sum_days = first_xq_days + 14 + c;
				output(y,a,sum_days);
				break;
			}
			case 5:{
				int sum_days = first_xq_days + 21 + c;
				if (sum_days > monthr[a-1]) cout << "none" << endl;
				else output(y,a,sum_days);
				break;
			}
		}
	}
	else
	{
		int days = 0,first_im;
		for (int i = 0;i < a-1;i++) days+=month[i];
		if (days%7+first > 7) first_im = (days%7 + first)%7;
		else first_im = days%7+first;
		//first day of the month
		
		int first_xq_days = 8 - first_im;
		switch(b)
		{
			case 1:{
				if (c < first_im) cout << "none" << endl;
				else output(y,a,c-first_im+1);
				break;
			}
			case 2:{
				int sum_days = first_xq_days + c;
				output(y,a,sum_days);
				break;
			}
			case 3:{
				int sum_days = first_xq_days + 7 + c;
				output(y,a,sum_days);
				break;
			}
			case 4:{
				int sum_days = first_xq_days + 14 + c;
				output(y,a,sum_days);
				break;
			}
			case 5:{
				int sum_days = first_xq_days + 21 + c;
				if (sum_days > month[a-1]) cout << "none" << endl;
				else output(y,a,sum_days);
				break;
			}
		}
	}
}

void date(int a,int b,int c,int y1,int y2)
{
	for (int i = y1;i <= y2;i++)
	{
		int first = first_day(i);//The first day of the year.
		when(a,b,c,first,i);
		
	}
}

int main()
{
	int a,b,c,y1,y2;
	cin >> a >> b >> c >> y1 >> y2;
	date(a,b,c,y1,y2);
}
