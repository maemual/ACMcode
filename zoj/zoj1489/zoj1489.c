/*************************************************************************
	> File Name: zoj1489.c
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年03月01日 星期五 10时43分42秒
 ************************************************************************/

#include<stdio.h>

int main()
{
	int n;
	while (scanf("%d",&n) != EOF){
		int i;
		long long ans;
		int x;
		if (n == 1 || (n % 2) == 0){
			printf("2^? mod %d = 1\n",n);
		}else {
			ans = 1;
			for (i = 1; ;i++)
			{
				ans *= 2;
				if (ans % n == 1){
					printf("2^%d mod %d = 1\n",i,n);
					break;
				}else
					ans %= n;
			}
		}
	}
	return 0;
}
