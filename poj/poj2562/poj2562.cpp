#include <cstdio>
#include <cstring>
const int MAX_LEN = 12;
char s1[MAX_LEN],s2[MAX_LEN];
int num1[MAX_LEN],num2[MAX_LEN];

int main()
{
	while (1)
	{
		scanf("%s%s",s1,s2);
		if (!strcmp(s1,"0") && !strcmp(s2,"0"))
		  break;
		//printf("%s %s\n",s1,s2);
		memset(num1,0,sizeof(num1));
		memset(num2,0,sizeof(num2));
		int len1 = strlen(s1);
		int len2 = strlen(s2);
		for (int i=MAX_LEN;i>MAX_LEN-len1;i--)
		  num1[i] = s1[i-MAX_LEN+len1-1]-'0';
		//for (int i=0;i<=MAX_LEN;i++)
		//  printf("%d",num1[i]);
		//printf("\n");
		for (int i=MAX_LEN;i>MAX_LEN-len2;i--)
		  num2[i] = s2[i-MAX_LEN+len2-1]-'0';
		//for (int i=0;i<=MAX_LEN;i++)
		//  printf("%d",num2[i]);
		//printf("\n");
		
		int k=0;
		int ans = 0;
		for (int i=MAX_LEN;i>=0;i--)
		{
			num1[i] += num2[i]+k;
			if (num1[i]>=10)
			{
				num1[i] -= 10;
				k = 1;
				ans++;
			}else
				k = 0;
		}
		
		//for (int i=0;i<=MAX_LEN;i++)
		//  printf("%d",num1[i]);
		//printf("\n");

		if (ans == 0)
		  printf("No carry operation.\n");
		else if (ans == 1)
		  printf("%d carry operation.\n",ans);
		else 
		  printf("%d carry operations.\n",ans);
	}
	return 0;
}
