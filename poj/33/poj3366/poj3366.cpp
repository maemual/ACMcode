#include <iostream>
#include <string>
using namespace std;
const int MAX_LEN = 105;
int m,n;
string s1[MAX_LEN],s2[MAX_LEN];
bool test1(string &s)
{
	for (int i=0;i<m;i++)
	{
		if (s == s1[i])
		{
			s = s2[i];
			return true;
		}
	}
	return false;
}
bool test2(string &s)
{
	int x = s.size()-2;
	if (s[s.size()-1] == 'y' && (s[x] != 'a' && s[x] != 'e' 
				&& s[x] != 'i' && s[x] != 'o' && s[x] !='u'))
	{
		s[s.size()-1] = 'i';
		s += "es";
		return true;
	}
	return false;
}
bool test3(string &s)
{
	int x = s.size()-1;
	if (s[x] == 'o' || s[x] == 's' || s[x] == 'x'
		|| (s[x] == 'h' && (s[x-1] == 'c' || s[x-1] == 's')))
	{
		s += "es";
		return true;
	}
	return false;
}
int main()
{
	cin >> m >> n;
	for (int i=0;i<m;i++)
	{
		cin >> s1[i] >> s2[i];
	}
	string st;
	for (int i=0;i<n;i++)
	{
		cin >> st;
		if (test1(st))
		{
			cout << st << endl;
		}else if (test2(st))
		{
			cout << st << endl;
		}else if (test3(st))
		{
			cout << st << endl;
		}else 
		{
			st += 's';
			cout << st << endl;
		}
	}
	return 0;
}
