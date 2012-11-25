#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int n,m;
	while (scanf("%d%d",&n,&m) != EOF)
	{
		int x;
		vector<int> v;
		for (int i=0;i<n;i++)
		{
			scanf("%d",&x);
			v.push_back(x);
		}
		make_heap(v.begin(),v.end(),less());
		for (int i=0;i<m;i++)
		{
			string s;
			cin >> s;
			int x;
			cin >> x;
			if (s == "add")
			{
				v.push_back(x);
				make_heap(v.begin(),v.end(),less());
			}else {
				
			}
		}
	}
}
