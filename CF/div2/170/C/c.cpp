/*************************************************************************
	> File Name: c.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年03月01日 星期五 00时31分57秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct ss{
	bool in;
	bool lan[105];
}node[105];
bool check(ss s1,ss s2)
{
	for (int i = 1; i <= 100; i++)
	{
		if (s1.lan[i] && s2.lan[i])
			return true;
	}
	return false;
}
int main()
{
	int n,m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		node[i].in = true;
		for (int j = 0; j < 105; j++)
			node[i].lan[j] = false;
	}
	int k,x;
	bool flag = false;
	for (int i = 1; i <= n; i++)
	{
		cin >> k;
		if (k != 0)
			flag = true;
		for (int j = 0; j < k; j++)
		{
			cin >> x;
			node[i].lan[x] = true;
		}
	}
	int p = 0;
	int sum = n;
	int tmp;
	while (1)
	{
		tmp = sum;
		for (int i = 1; i <= n; i++)
		{
			if (node[i].in)
			{
				for (int j = i+1; j <= n; j++)
				{
					if (node[j].in == false)
						continue;
					if (check(node[i],node[j]))
					{
						node[j].in = false;
						for (int k = 1; k <= m; k++)
						{
							node[i].lan[k] |= node[j].lan[k];
						}
						sum--;
					}
				}
			}
		}
		if (tmp == sum)
			break;
	}
	if (sum == n && flag == false)
		cout << sum << endl;
	else
		cout << sum - 1 << endl;
	return 0;
}
