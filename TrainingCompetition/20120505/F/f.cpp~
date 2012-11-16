#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
using namespace std;
int a[2001][2001];
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s1,s2;
		cin >> s1 >> s2;
		memset(a,0,sizeof(a));
		for (int i=1;i<=s1.size();++i)
		{
			for (int j=1;j<=s2.size();++j)
			{
				if (s1[i-1] == s2[j-1])
				{
					a[i][j] = a[i-1][j-1]+1;
				}else{
					if (a[i-1][j]>=a[i][j-1])
					{
						a[i][j] = a[i-1][j];
					}else a[i][j] = a[i][j-1];
				}
			}
		}
		int max = -1;
		for (int i=1;i<=s1.size();++i)
		{
			for (int j=1;j<=s2.size();++j)
			{
				if (max < a[i][j])
				  max = a[i][j];
			}
		}
		//cout << max << endl;
		int cost = 0;
		if (s1.size() > s2.size())
		{
			cost += 2;
			if (max == s2.size())
			{
				printf("%d\n",cost);
			}else {
				cost += s2.size() - max + 2;
				printf("%d\n",cost);
			}
		}else {
			cost +=2;
			if (max == s1.size())
			{
				printf("%d\n",cost);
			}else {
				cost += s1.size()-max +2;
				printf("%d\n",cost);
			}
		}
	}
	return 0;
}
