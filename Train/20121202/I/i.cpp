#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
using namespace std;
const int MAX_LEN = 100005;
bool prime[MAX_LEN];
double converFromString(string &s)
{
	istringstream i(s);
	double x;
	if (i >> x)
	  return x;
	return 0.0;
}
int main()
{
	int p = 4;
	memset(prime,1,sizeof(prime));
	for (int i = 2; i < MAX_LEN; i++)
	{
		if (prime[i])
		{
			while (p < MAX_LEN)
			{
				prime[p] = false;
				p += i;
			}
		}
		p = 2 * (i+1);
	}
	prime[0] = false;
	prime[1] = false;
	string s;
	while (1)
	{
		cin >> s;
		if (s == "0")
		  break;
		int max = -1;
		for (int i=0; i < s.length(); i++)
		{
			for (int j = i; j < i+5 && j < s.length(); j++)
			{
				string st = "";
				for (int k = 0; k < j-i+1;k++)
					st+=s[k+i];
			//	cout << st << endl;
				int x = converFromString(st);
				if (x < MAX_LEN && prime[x] && x > max)
				  max = x;
			}
		}
		cout << max << endl;
	}
	return 0;
}
