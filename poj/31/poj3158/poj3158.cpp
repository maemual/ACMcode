#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int max(int a,int b)
{
	return a>b?a:b;
}
int min(int a,int b)
{
	return a<b?a:b;
}
int work(string s1,string s2)
{
	for (int i=0;i<s1.size();i++)
	{
		bool flag = true;
		for (int j=i;j<s1.size() && j<i+s2.size();j++)
		{
			if (s1[j] == '2' && s2[j-i] == '2')
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			return max(s1.size(),i+s2.size());
		}
	}
	return s1.size()+s2.size();
}
int main()
{
	string st;
	string s1,s2,s3;
	int cas = 0;
	while (cin >> s1)
	{
		cin >> s2;
		cout << min(work(s1,s2),work(s2,s1))<<endl;
	}
	return 0;
}
