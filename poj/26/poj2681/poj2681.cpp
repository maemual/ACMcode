#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cnts1[30],cnts2[30];
char s1[100],s2[100];

int main()
{
	int cas;
	scanf("%d",&cas);
	getchar();
	for (int k=1;k<=cas;k++)
	{
		//scanf("%s\n%s",s1,s2);
		//getchar();
		gets(s1);
		//getchar();
		gets(s2);
	//	printf("%s\n",s1);
	//	printf("%s\n",s2);
		memset(cnts1,0,sizeof(cnts1));
		memset(cnts2,0,sizeof(cnts2));
		for (int i=0;i<strlen(s1);i++)
		  cnts1[s1[i]-'a']++;
		for (int i=0;i<strlen(s2);i++)
		  cnts2[s2[i]-'a']++;
		int sum = 0;
		for (int i=0;i<30;i++)
		  sum += abs(cnts2[i]-cnts1[i]);
		printf("Case #%d:  %d\n",k,sum);
	}
	return 0;
}
