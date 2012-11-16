#include <cstdio>
const int MAX_LEN = 1500;
int ugly[MAX_LEN+5];
int min(int a,int b,int c)
{
	if (a>b)
	  a=b;
	if (a>c)
	  a=c;
	return a;
}
int main()
{
	ugly[1]=1;
	int p2=1,p3=1,p5=1;
	for (int i=2;i<=MAX_LEN;i++)
	{
		ugly[i] = min(ugly[p2]*2,ugly[p3]*3,ugly[p5]*5);
		if (ugly[i] == ugly[p2]*2)
		  p2++;
		if (ugly[i] == ugly[p3]*3)
		  p3++;
		if (ugly[i] == ugly[p5]*5)
		  p5++;
	}
	int n;
	while (scanf("%d",&n) != EOF)
	{
		if (n == 0)
		  break;
		printf("%d\n",ugly[n]);
	}
	return 0;
}
