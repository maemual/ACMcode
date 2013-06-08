#include <cstdio>
const int MAX_LEN = 20;
int a[MAX_LEN+5];
int b[MAX_LEN+5];
int main()
{
	int n;
	int flag = 0;
	while (scanf("%d",&n) != EOF)
	{
		if (n == 0)
		  break;
		if (flag != 0)
		  printf("\n");
		flag++;
		for (int i=0;i<n;i++)
		  scanf("%d",&a[i]);
		for (int i=0;i<n;i++)
		  scanf("%d",&b[i]);
		int sumA=0,sumB=0;
		for (int i=0;i<n;i++)
		{
			if (a[i] == b[i])
			  continue;
			else if (a[i] == 1 && b[i] == 2)
			  sumA+=6;
			else if (a[i] == 2 && b[i] == 1)
			  sumB+=6;
			else if (a[i]-b[i] == 1)
			  sumB+=a[i]+b[i];
			else if (b[i]-a[i] == 1)
			  sumA+=a[i]+b[i];
			else if (a[i]-b[i] >1)
			  sumA+=a[i];
			else if (b[i]-a[i]>1)
			  sumB+=b[i];
		}
		printf("A has %d points. B has %d points.\n",sumA,sumB);
	}
	return 0;
}
