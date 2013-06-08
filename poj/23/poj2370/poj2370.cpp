#include <cstdio>
#include <algorithm>
const int MAX_LEN = 101;
int groups[MAX_LEN+5];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	  scanf("%d",&groups[i]);
	std::sort(groups,groups+n);
	int ans = 0;
	for (int i=0;i<n/2+1;i++)
	{
		ans+=groups[i]/2+1;
	}
	printf("%d\n",ans);
	return 0;
}
