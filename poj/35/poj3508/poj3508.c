#include <stdio.h>
#include <string.h>

#define MAX_LEN 10000005
char num[MAX_LEN],result[MAX_LEN];
int len;

int main()
{
	int cas = 0;
	int i,mark,minus,tmp;
	while (1)
	{
		scanf("%s",num);
		if (num[0] == '0')
		  break;
		len = strlen(num);
		printf("%d. ",++cas);
		minus = mark = 0;
		for (i = len - 1; i >= 0; i--)
		{
			minus += mark;
			if (minus <= (num[i] - '0')){
				result[i] = num[i] - minus;
				mark = 0;
			}else {
				result[i] = num[i] + 10 - minus;
				mark = 1;
			}
			minus = result[i] - '0';
		}
		result[len] = '\0';
		if (result[0] == '0')
		  printf("IMPOSSIBLE\n");
		else
		  printf("%s\n",result);
	}
	return 0;
}
