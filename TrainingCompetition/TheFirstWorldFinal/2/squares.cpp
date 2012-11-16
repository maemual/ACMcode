#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int n,m;
	while (cin >> n)
	{
		cin >> m;
		char ch;
		int row,column;
		int a[n+1][n+1][n+1][n+1];
		//int h[n+1][n+1];
		//int v[n+1][n+1];
		//memset(h,0,sizeof(h));
		//memset(v,0,sizeof(v));
		memset(a,0,sizeof(a));
		for (int i =0 ;i < m;++i)
		{
			cin >> ch >> row >> column;
			if ('H' == ch)
				a[row][column][row][column+1] = 1;
			else 
				a[column][row][column+1][row] = 1;
		}

		for (int i = 1;i < n;++i)
		  for (int j = 1;j < n;++j)
		  {
			  for (int k = j+1;k <= n;++k)
			  {
				  for (int p = 1;p <)
			  }
		  }

		for (int i = 1;i < n;++i)
		  for (int j = 1;j < n;++j)
			for (int k = 1;k <=n;++k)
			{

			}

	}
	return 0;
}
