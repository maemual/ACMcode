#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;
int map[]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9};
int a[9999999]={0};
string converToString(int x)
{
	ostringstream ss;
	if (ss << x)
	  return ss.str();
}
int converFromString(string &s)
{
	istringstream i(s);
	int x;
	if (i >> x)
	  return x;
	return 0;
}
int main()
{
	int n;
	string s;
	cin >> n;
	for (int i=0;i<n;i++)
	{
		cin >> s;
		string st="";
		for (int j=0;j<s.length();j++)
		{
			if (s[j]>='0' && s[j]<='9' || s[j]>='A' && s[j]<='Z')
			{
				if (s[j]>='A' && s[j]<='Z')
					st+= map[s[j]-'A']+'0';
				else st+=s[j];
			}
		}
		//cout << st << endl;
		int x = converFromString(st);
		a[x]++;
		//cout << x << endl;
	}
	bool flag = true;
	for (int i=0;i<=9999999;i++)
	{
		if (a[i]>1 && i >=1000000)
		{
			string st = converToString(i);
			//cout << a[i] << endl;
			//cout << st << endl;
			for (int j=0;j<3;j++)
			  cout << st[j];
			cout << '-';
			for (int j=3;j<7;j++)
			  cout << st[j];
			cout <<" "<< a[i] << endl;
			flag = false;
		}else if (a[i]>1 && i<1000000)
	}
	if (flag)
	  cout << "No duplicates." << endl;
	return 0;
}
