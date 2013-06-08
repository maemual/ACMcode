#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

int main()
{
	int n,m;
	string name;
	int score;
	char str[100];
	while (cin >> n)
	{
		map<string,int> amap;

		getchar();
		for (int i = 0; i < n; i++)
		{
			getline(cin,name);
			amap.insert(pair<string,int>(name,0));
		}
		map<string,int>::iterator it;
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d ",&score);
				gets(str);
				name = str;
				amap[name] += score;
			}
			int ans = 1;
			for (it = amap.begin(); it != amap.end(); it++)
			{
				if ((it->second) > amap["Li Ming"])
				  ans++;
			}
			cout << ans << endl;
		}
	}
	return 0;
}
