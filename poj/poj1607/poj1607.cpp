#include <cstdio>
int  main()
{
	int n,k;
	double sum;
	printf("Cards  Overhang\n");
	while(scanf("%d",&n)!=EOF){
		k=2;
		sum = 0;
		for(int i=0;i<n;i++)
		{
			sum+=1.0/k;
			k+=2;
		}
		printf("%5d",n);
		printf(" %9.3f\n",sum);
	}
}
