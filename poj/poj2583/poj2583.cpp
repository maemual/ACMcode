#include<stdio.h>

int main()
{
	int f[6];
	int i;

	while(scanf("%d%d%d",&f[0],&f[1],&f[2])!=EOF)
	{  
		f[3] = 3*(f[2]-f[1])+f[0];
		f[4] = 2*(f[3]-f[1])+f[0];
		f[5] = 5*(f[3]-f[2])+f[0];

		printf("%d %d %d\n",f[3],f[4],f[5]);
	}
	return 0;
}
