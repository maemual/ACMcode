#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int ans[1000];
int main()
{
	int cas;
	scanf("%d",&cas);
	while (cas--)
	{
		int n;
		scanf("%d",&n);
		int p,q = 0;
		vector<char> s;
		for (int j = 0;j < n;++j)
		{
			cin >> p;
			for (int k = q;k < p;++k)
				s.push_back('(');
			s.push_back(')');
			q = p;
		}
		int k = 0;
		vector<int> sta(s.size(),0);
		for (int ix = 0; ix != s.size();++ix)
			if (s[ix] == ')')
			{
				int count = 0;
				for (int jx = ix; jx >= 0;--jx)
					if (s[jx] == '(')
					{
						++count;
						if (sta[jx] == 0)
						{
							ans[k++] = count;
							sta[jx] = 1;
							break;
						}
					}
			}
		for (int i=0;i<k-1;i++)
		  printf("%d ",ans[i]);
		printf("%d\n",ans[k-1]);
	}

	return 0;
}
