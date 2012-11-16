#include<cstdio>
#include<math.h>

int main()
{
	int m,n,k,T;
	scanf("%d",&T);
	int biao[1101][101]={0};
	for(int i=0;i<=1100;i++) biao[i][0]=1;
	for(int i=1;i<=1100;i++)
	  for(int k=1;k<=i&&k<=100;k++)
		biao[i][k]=(biao[i-1][k]+biao[i-1][k-1])%5201314;
	for(int i=0;i<T;i++)
	{
		scanf("%d%d%d",&m,&n,&k);
		int x=m+n-m*k-1;
		int y=m-1;
		if(x<0||y<0) {printf("0\n");continue;}
		printf("%d\n",biao[x][y]);
	}
	return 0;
}
