#include <stdio.h>
#include <math.h>
int main()
{
	int a,b,c;
	int i,k;
	float x;	
	for (k = 1; ; k++)
	{
		scanf("%d %d %d",&a,&b,&c);
		if (a == 0 && b == 0 && c == 0)
		  break;
		printf("Triangle #%d\n",k);
		if (a == -1)
		{
			x = pow(c,2) - pow(b,2);	
			if (x > 0)
			  printf("a = %.3f\n\n",sqrt(x));
			else 
			  printf("Impossible.\n\n");
		}else if (b == -1)
		{
			x = pow(c,2) - pow(a,2);
			if (x > 0)
			  printf("b = %.3f\n\n",sqrt(x));
			else
			  printf("Impossible.\n\n");
		}else {
			x = pow(a,2) + pow(b,2);
			printf("c = %.3f\n\n",sqrt(x));
		}
	}
	return 0;
}
