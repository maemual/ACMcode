#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int check(const string &s)
{
	if (s[0] == '(')
		return 0;
	for (int i=1;i<s.size();i++)
	{
		if (s[i] == '(' && s[i-1] != '-')
		{
			return i;
		}
	}
	return -1;
}
int check2(const string &s)
{
	for (int i=0;i<s.size()-2;i++)
	{
		if (s[i] == '(' && s[i+2] == ')')
			return i;
	}
	return -1;
}
int main()
{
	int m;
	cin >> m;
	getchar();
	string st;
	while (m--)
	{
		getline(cin,st);
		string s="";
		for (int i=0;i<st.size();i++)
		{
			if (st[i] != ' ')
				s += st[i];
		}
		int pos;
		while ( (pos = check(s)) >= 0)
		{
			st = "";
			for (int i=0;i<pos;i++)
				st += s[i];
			int k;
			int cnt = 0;
			for (int i=pos;i<s.size();i++)
			{
				if (s[i] == '(')
					cnt++;
				else if (s[i] == ')'){
					cnt--;
					if (cnt == 0)
					{
						k=i;
						break;
					}
				}
			}
			
			for (int i=pos+1;i<k;i++)
				st += s[i];
		
			for (int i=k+1;i<s.size();i++)
				st += s[i];

			s = st;
		}

		while ( (pos = check2(s))>=0)
		{
			st = "";
			for (int i=0;i<pos;i++)
				st += s[i];
			
			st += s[pos+1];
			
			for (int i=pos+3;i<s.size();i++)
				st += s[i];
			
			s = st;
		}
		cout << s << endl;
	}
	return 0;
}
