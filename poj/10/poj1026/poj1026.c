#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX 202
 
int key[MAX], t[MAX];
 
/* 求解置换周期 */
void get_time(int n)
{
	int i, j, count;
	for (i = 1; i <= n; i++)
	{
		j = key[i];
		count = 1;
		/* 直到轮回 */
		while(i != j)
		{
			count++;
			j = key[j];
		}
		t[i] = count;
	}
}
 
int main()
{
	int i, j, m, n, len;
	char src[MAX], dst[MAX];
 
	while(1)
	{
		scanf("%d", &n);
		if (n == 0) break;
 
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &key[i]);
		}
 
		/* 初始化周期数组 */
		memset(t, 0, sizeof(t));
 
		get_time(n);		
 
		while(1)
		{
			scanf("%d", &m);
			if (m == 0) break;
			getchar();
 
			/* 读入输入串 */
			gets(src + 1);
 
			/* 补全输入串 */
			for (i = strlen(src + 1) + 1; i <= n; i++)
			{
				src[i] = ' ';
			}
			src[n + 1] = 0;
 
			/* 求解输出串 */
			for (i = 1; i <= n; i++)
			{
				int pos = i;
				for (j = 0; j < m % t[i]; j++)
				{
					pos = key[pos];
				}
				dst[pos] = src[i];
			}
			dst[n + 1] = 0;
 
			puts(dst + 1);
		}
		printf("\n");		
	}
	return 0;
}
