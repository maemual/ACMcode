/*************************************************************************
	> File Name: zoj2105.c
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年03月02日 星期六 20时26分25秒
 ************************************************************************/

#include<stdio.h>

int arr[100000];
int main()
{
	int A,B,n;
	int a,b,c;
	int i;
	int cir;
	while (1)
	{
		scanf("%d %d %d",&A,&B,&n);
		if (A == 0 && B == 0 && n == 0)
			break;
		arr[1] = 1;
		arr[2] = 1;
		for (i = 3; i <= 49; i++)
		{
			arr[i] = (A * arr[i-1] + B * arr[i-2]) % 7;
			if (arr[i] == 1 && arr[i-1] == 1)
				break;
		}
		cir = i - 2;
		printf("%d\n",arr[(n-1)%cir+1]);
	}
	return 0;
}
