/*************************************************************************
	> File Name: zoj1712.c
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年03月01日 星期五 22时28分57秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	int p[35];
	int i,j;
	for (i = 0; i < 31; i++)
		p[i] = (int)pow(2,i) - 1;
	p[31] = 2147483647;

	char st[35];
	int len;
	int ans;
	while (1){
		scanf("%s",st);
		if (st[0] == '0')
			break;
		len = strlen(st);
		ans = 0;
		for (i = 1,j = len-1; j >= 0; i++,j--)
		{
			ans += (st[j]-'0')*p[i];
//			printf("%d\n",p[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
