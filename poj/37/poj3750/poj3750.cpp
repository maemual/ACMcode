#include <stdio.h>
#include <string.h>

const int MAX_LEN = 15;
const int MAX_NUM = 64;

int main()
{
	int n;
	scanf("%d",&n);
	char list[MAX_NUM+5][MAX_LEN+5];
	bool flag[MAX_NUM+5];
	for (int i=0;i<n;i++)
	{
		scanf("%s",list[i]);
		flag[i] = true;
	}
	int w,s;
	scanf("%d,%d",&w,&s);
	int num = 0;
	int p=1,q = w-2;
	while (num < n)
	{
		p = 0;
		while (p < s)
		{
			q++;
			if (q >= n)
			  q = 0;
			if (flag[q])
			  p++;
		}
		flag[q] = false;
		printf("%s\n",list[q]);
		num++;
	}
	return 0;
}
