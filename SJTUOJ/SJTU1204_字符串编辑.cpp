#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void insert(string &t,int c,string in)
{
	string result;
	for (int i = 0;i < c-1;i++) result+=t[i];
	for (int i = 0;i < in.length();i++) result+=in[i];
	for (int i = c-1;i < t.length();i++) result+=t[i];
	t = result;
}

void Delete(string &t,int c,int n)
{
	string result;
	for (int i = 0;i < c-1;i++) result+=t[i];
	for (int i = c + n-1;i < t.length();i++) result+=t[i];
	t = result;
}

class menu
{
	private:
		string *ED;
		int column;
	public:
		menu(string *Ep,int columnp)
		{
			column = columnp;
			ED = new string[100];
			for (int i = 0;i < column;i++) ED[i] = Ep[i];
		}
		void menuing();
};

void menu::menuing()
{
	string a;
	cin >> a;
	while (a!="quit")
	{
		if (a == "list")
		{
			int colum1,colum2;
			cin>>colum1;
			cin>>colum2;
			if (colum1 <= 0 || colum1 >= column+1 || colum2 <= 0 || colum2 >= column+1 || colum1 > colum2)
			{
				cout << "Error!"<<'\n';
				cin >> a;
				continue;
			}
			else for (int i = colum1-1;i < colum2;i++) cout << ED[i] << '\n';
		}
		else
		{
			if (a == "ins")
			{
				int co,ro;
				string t;
				cin >> co >> ro;
				getline(cin,t);
				Delete(t,1,1); 
				if (co <= 0 || co > column || ro <= 0)
				{
					cout << "Error!"<<'\n';
					cin >> a;
					continue;
				}
				else
				{
					if (ro > ED[co-1].length()+1)
					{
						cout << "Error!"<<'\n';
						cin >> a;
						continue;
					}
					else insert(ED[co-1],ro,t);
				}
			}
			else
			{
				if (a == "del")
				{
					int co,ro,num;
					cin >> co >> ro >> num;
					if (co <= 0 || co > column||ro <= 0)
					{
						cout << "Error!"<<'\n';
						cin >> a;
						continue;
					}
					else
					{
						if (ro > ED[co-1].length() || num > ED[co-1].length() - ro + 1)
						{
							cout << "Error!"<<'\n';
							cin >> a;
							continue;
						}
						else
						{
							Delete(ED[co-1],ro,num);
						}
					}
				}
			}
		}
		cin >> a;
	}
	for (int i = 0;i < column;i++) cout << ED[i] << '\n';
}

int main()
{
	string *Edit;
	Edit = new string[100];
	int i = 0;
	getline(cin,Edit[i]);
	if (Edit[0]!="******")
	{
		while (Edit[i]!="******")
		{
			i++;
			getline(cin,Edit[i]);
		}
	}
	//得到一个string组Edit，存放了输入的文章，i为列数，len（Edit【i】）为行数
	cout << i;
	menu result(Edit,i);
	result.menuing();
}
