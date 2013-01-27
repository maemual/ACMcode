#include <stdio.h>
#include <string.h>
#define MAX_LEN 1000005
#define MIN(a,b) ((a) < (b) ? (a) : (b))
char s[MAX_LEN];

int main()
{
	scanf("%s",s);
	int len = strlen(s);
	int xx,yy;
	xx=yy=0;
	int i;
	for (i = 0; i < len; i++)
	{
		if (s[i] == 'x')
		  xx++;
		else 
		  yy++;
	}
	int min = MIN(xx,yy);
	xx -= min;
	yy -= min;
	if (xx == 0)
	  for (i = 0; i < yy; i++)
		printf("y");
	else 
	  for (i = 0; i < xx; i++)
		printf("x");
	printf("\n");
	return 0;
}
