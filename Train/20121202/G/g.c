#include <stdio.h>
#include <string.h>

char version[50005][1000005];
int main()
{
	int n;
	scanf("%d",&n);
	int i,j,k;
	int x;
	int pos;
	int ver = 0;
	char st[1000005];
	for (k = 0; k < n; k++)
	{
		scanf("%d",&x);
		if (x == 1)
		{
			scanf("%d",&pos);
			scanf("%s",st);
			int len1 = strlen(st);
			for (i = 0; i < pos; i++)
			  version[ver][i] = version[ver-1][i];
			for (i = 0; i < strlen(st); i++)
			  version[ver][pos+i] = st[i];
			for (i = pos; i < strlen(version[ver-1]); i++)
			  version[ver][i+len1] = version[ver-1][i];
			ver++;
		}else if (x == 2)	
		{
			int c;
			scanf("%d",&pos);
			scanf("%d",&c);
			for (i = 0; i < pos; i++)
			  version[ver][i] = version[ver-1][i];
			for (i = pos+c; i < strlen(version[ver-1]);i++)
			  version[ver][i-c] = version[ver-1][i];
			ver++;
		}else if (x == 3)
		{
			int v,c;
			scanf("%d %d %d",&v,&pos,&c);
			for (i = pos; i < pos + c; i++)
			  printf("%c",version[v][i]);
			printf("\n");
		}
	}
	return 0;
}
