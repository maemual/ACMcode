#include <cstdio>
#include <algorithm>
const int MAX_LEN = 100000;
int data[MAX_LEN+5];
char s[10];
int main()
{
	int n,k;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	  scanf("%d",&data[i]);
	std::sort(data,data+n);
	scanf("%s",s);
	scanf("%d",&k);
	//for (int i=0;i<n;i++)
	//  printf("%d ",data[i]);
	//printf("\n");
	int x;
	for (int i=0;i<k;i++)
	{
		scanf("%d",&x);
		printf("%d\n",data[x-1]);
	}
	return 0;
}
