#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
	int x,y;
	char ch[50];
}node;
node q[100001];
int cmp(const void *a,const void *b)
{
	if((*(node *)a).x!=(*(node *)b).x) 
		return (*(node *)a).x-(*(node *)b).x;
	else if((*(node *)a).y!=(*(node *)b).y) 
			return (*(node *)a).y-(*(node *)b).y;
	else	
		return strcmp((*(node *)a).ch,(*(node *)b).ch);
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		getchar();
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%d:%d",&q[i].x,&q[i].y);
			gets(q[i].ch);
		}
		int flag=0;
		for(i=0;i<n;i++)
		{
			if(q[i].x<0||q[i].x>23||q[i].y<0||q[i].y>59)
			{
				printf("Neville is so careless!\n");
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
		qsort(q,n,sizeof(q[0]),cmp);
		for(i=0;i<n;i++)
		{
			printf("%02d:%02d",q[i].x,q[i].y);
			printf("%s\n",q[i].ch);
		}
		}
	
	}
	return 0;
}
