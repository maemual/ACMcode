#include <cstdio>
int fac[]={10,9,8,7,6,5,4,3,2,1};
int a[10];
int main()
{
	char s[15];
	while (scanf("%s",s) != EOF)
	{
		int sum = 0;
		int pos = 0;
		for (int i=0;i<=9;i++)
		{
			if (s[i]>='0' && s[i]<='9')
			  sum += (s[i]-'0')*fac[i];
			else if (s[i] == 'X')
			  sum += 10*fac[i];
			else
			  pos = i;
		}
		bool flag = true;
		if (pos != 9){
			for (int i=0;i<=9;i++)
			{
				if ((sum+i*fac[pos])%11==0)
				{
					printf("%d\n",i);
					flag = false;
					break;
				}
			}
		}else {
			for (int i=0;i<=10;i++)
			{
				if ((sum+i*fac[pos])%11==0)
				{
					if (i == 10)
					  printf("X\n");
					else
					  printf("%d\n",i);
					flag = false;
					break;
				}
			}
		}
		if (flag)
		  printf("%d\n",-1);
	}
	return 0;
}
