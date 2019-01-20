#include <iostream>

using namespace std;

int how_many_run(int t)
{
	int num_run = 0;
	for (int i = 1850;i < t;i++)
	{
		if (!(i%400) || (i%4==0 && i%100!=0)) num_run++;
		else continue;
	}
	return num_run;
}

void out(int a)
{
	if (a >= 10) cout << a;
	else cout << '0' << a;
}

void xingqi_date(int a,int b,int c,int first_day,bool flag,int y)
{
	//cout << first_day;
	int month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int rmonth[] = {31,29,31,30,31,30,31,31,30,31,30,31};
	if (flag)
	{
		int day = 0;
		for (int i = 0;i < a-1;i++) day+=month[i];
		int f_xq = ((day)%7 + first_day)%7; //本月第一天是星期几
		if (f_xq == 0) f_xq = 7;
		int f_xq_day = 8 - f_xq;//本月第一个星期有几天
		if (b <= 4 && b >= 2)
		{
			cout << y << '/';
			out(a);
			cout << '/';
			out(f_xq_day + 7*(b-2)+c);
			cout << endl;
		}
		if (b == 1)
		{
			if (c < f_xq) cout << "none" << endl;
			else
			{
				cout << y << '/';
				out(a);
				cout << '/';
				out((c-f_xq)+1);
				cout << endl;
			}
		}
		if (b == 5)
		{
			if (21+(7-f_xq%7) >= month[a-1])
			{
				cout << "none" << endl;
				return;
			}
			int last_xq = (month[a-1] % 7 + f_xq - 1)%7;
			if (last_xq==0) last_xq = 7;
			cout << y << '/';
			out(a);
			cout << '/';
			out(28 - f_xq+1+c);
			cout << endl;
		}
	}
	else
	{
		int day = 0;
		for (int i = 0;i < a-1;i++) day+=rmonth[i];
		int f_xq = ((day)%7 + first_day)%7; //本月第一天是星期几
		//cout << f_xq;
		if (f_xq == 0) f_xq = 7;
		int f_xq_day = 8 - f_xq;//本月第一个星期有几天
		if (b <= 4 && b >= 2)
		{
			cout << y << '/';
			out(a);
			cout << '/';
			out(f_xq_day + 7*(b-2)+c);
			cout << endl;
		}
		if (b == 1)
		{
			if (c < f_xq) cout << "none" << endl;
			else
			{
				cout << y << '/';
				out(a);
				cout << '/';
				out((c-f_xq)+1);
				cout << endl;
			}
		}
		if (b == 5)
		{
			if (21+(7-f_xq%7) >= rmonth[a-1])
			{
				cout << "none" << endl;
				return;
			}
			int last_xq = (rmonth[a-1] % 7 + f_xq - 1)%7;
			if (last_xq==0) last_xq = 7;
			cout << y << '/';
			out(a);
			cout << '/';
			out(28 - f_xq+1+c);
			cout << endl;
		}
	}
}

void Festival(int a,int b,int c,int y1,int y2)
{
	bool flag = true;
	for (int i = y1;i < y2+1;i++)
	{
		int first_day = ((i - 1850)*365 + (how_many_run(i))) % 7 + 2;//本年第一天是星期几
		if (first_day > 7) first_day = first_day % 7;
		if (!(i%400) || (i%4==0 && i%100!=0)) flag = false;
		//cout << first_day;
		xingqi_date(a,b,c,first_day,flag,i);
		flag = true;
	}
}

int main() 
{
	Festival(12,3,2,1851,2045);
}
