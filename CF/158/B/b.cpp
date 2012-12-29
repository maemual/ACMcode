#include <iostream>
#include <string>
#include <cctype>
#include <map>
using namespace std;

map<string,int> m;
string s;
bool check(int pos)
{
	pos-=2;
	int dd,mm,yy;
	if (!isdigit(s[pos]) || !isdigit(s[pos+1])
		|| s[pos+2] != '-' 
		|| !isdigit(s[pos+3]) || !isdigit(s[pos+4])
		|| s[pos+5] != '-'
		|| !isdigit(s[pos+6]) || !isdigit(s[pos+7]) 
		|| !isdigit(s[pos+8]) || !isdigit(s[pos+9]))
	  return false;

	dd = (s[pos]-'0')*10+(s[pos+1]-'0');
	mm = (s[pos+3]-'0')*10+(s[pos+4]-'0');
	yy = (s[pos+6]-'0')*1000+(s[pos+7]-'0')*100+(s[pos+8]-'0')*10
			+(s[pos+9]-'0');

	if (!(yy >= 2013 && yy <= 2015))
	  return false;
	if (mm > 12 || mm == 0 || dd == 0)
	  return false;
	if (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8
		|| mm == 10 || mm == 12)
	{
		if (dd > 31)
		  return false;
	}
	if (mm == 4 || mm == 6 || mm == 9 || mm == 11)
	{
		if (dd > 30)
		  return false;
	}
	if (mm == 2 && dd > 28)
	  return false;
	return true;
}
int main()
{
	string st;
	map<string,int>::iterator it;
	cin >> s;
	for (int i = 2; i < s.size() - 7; i++)
	{
		if (s[i] == '-')
		{
			if (check(i))
			{
				st = s.substr(i-2,10);
				it = m.find(st);
				if (it == m.end())
				{
					m.insert(pair<string,int>(st,1));
				}
				else
				  m[st]++;
			}
		}
	}
	int max = -1;
	string ans;
	for (it = m.begin(); it != m.end(); it++)
	{
		if (it->second > max)
		{
			max = it->second;
			ans = it->first;
		}
	}
	cout << ans << endl;
	return 0;
}
