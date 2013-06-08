#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char telephone[100000][9];

//mark用于保存定位字符对应的数字
char mark[]={'0','1','2','3','4','5','6','7','8','9','0','0','0','0','0','0','0','2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','0','7','7','8','8','8','9','9','9'};
int sort_function(const void *a,const void *b)
{
	return(strcmp((char*)a,(char*)b));
}
int main()
{
	int n,i,j,y=1;
	char c,m[9];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		while(scanf("%c",&c),c=='-');
		for(j=0;j<8;)
		{
			scanf("%c",&c);
			if(c!='-')
			  telephone[i][j++]=mark[c-'0'];
			if(j==3)
			  telephone[i][j++]='-';
		}
		telephone[i][j]='\0';
	}
	qsort((void *)telephone,n, sizeof(telephone[0]), sort_function);
	i=1;
	j=1;
	strcpy(m,telephone[0]);
	while(i<n)
	{
		if(strcmp(m,telephone[i])==0)
		{
			j++;
			y=0;
			if(j==2)
			  printf("%s ",telephone[i]);
		}
		else
		{
			if(j>1)
			{
				printf("%d\n",j);
				j=1;
			}
			strcpy(m,telephone[i]);
		}
		i++;
	}
	if(j>1)printf("%d\n",j);
	if(y==1)printf("No duplicates.\n");
	return 0;
}
